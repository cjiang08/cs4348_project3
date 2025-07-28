#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory.h"
#include "page_table.h"
#include "manager.h"
#include "replacement.h"

#define MAX_PROCESSES 100 // Upper bound for process IDs
int use_fifo = 0; // Set to 0 to use LRU instead of FIFO

PageTable* processes[MAX_PROCESSES]; // Array of process page tables

// Allocate num_pages to a process with ID pid
void alloc(int pid, int num_pages) {
    PageTable* pt = create_page_table(pid);
    processes[pid] = pt;

    for (int i = 0; i < num_pages; i++) {
        int f = find_free_frame();
        if (f == -1) {
            printf("Error: Out of memory\n");
            return;
        }

        frame_table[f].occupied = 1;
        frame_table[f].process_id = pid;
        frame_table[f].page_number = i;

        pt->entries[i].valid = 1;
        pt->entries[i].frame_number = f;
    }

    printf("Allocated %d pages to process P%d\n", num_pages, pid);
}

// Free all memory used by a process
void free_memory(int pid) {
    if (processes[pid] == NULL) return;

    free_process_frames(pid);
    destroy_page_table(processes[pid]);
    processes[pid] = NULL;

    printf("Freed memory for process P%d\n", pid);
}

// Translate and access a virtual address for read/write
void access_memory(int pid, int vaddr, const char* mode) {
    if (processes[pid] == NULL) {
        printf("Process P%d not found\n", pid);
        return;
    }

    int page_num = vaddr / FRAME_SIZE;
    int offset = vaddr % FRAME_SIZE;
    PageTableEntry* entry = &processes[pid]->entries[page_num];

    // Page fault check
	if (!entry->valid) {
   		printf("Page fault on P%d at page %d (virtual address %d)\n", pid, page_num, vaddr);
		
		int victim = find_free_frame();
	 	
		if (victim == -1) {
        	victim = use_fifo ? select_victim_frame_fifo() : select_victim_frame_lru();

        if (victim == -1) {
            printf("No frame available for replacement!\n");
            return;
        }
	
		int old_pid = frame_table[victim].process_id;
        int old_page = frame_table[victim].page_number;
        processes[old_pid]->entries[old_page].valid = 0;

        printf("Evicted frame %d (P%d page %d)\n", victim, old_pid, old_page);
    }
	
	frame_table[victim].occupied = 1;
    frame_table[victim].process_id = pid;
    frame_table[victim].page_number = page_num;

    entry->valid = 1;
    entry->frame_number = victim;
}
 
   // Set reference/modified bits
    entry->reference_bit = 1;
    if (strcmp(mode, "write") == 0)
        entry->modified_bit = 1;

    int phys_addr = entry->frame_number * FRAME_SIZE + offset;
	track_frame_use(entry->frame_number); // Update FIFO or LRU tracking
    printf("Translated virtual address %d (P%d) -> physical address %d\n", vaddr, pid, phys_addr);
}
