#include <stdio.h>
#include <string.h>
#include "memory.h"
#include "manager.h"
#include "replacement.h"


int main() {
    init_memory(); // Initialize the physical memory frame table
	init_replacement(); // Initializes LRU and FIFO tracking

    char line[100];
    char rw[10];
    int pid, num_pages, vaddr;

    // Command loop to read input and call corresponding operations
    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "alloc P%d %d", &pid, &num_pages) == 2) {
            alloc(pid, num_pages); // Allocate pages to process
        } else if (sscanf(line, "free P%d", &pid) == 1) {
            free_memory(pid); // Free all memory used by the process
        } else if (sscanf(line, "access P%d %d %s", &pid, &vaddr, rw) == 3) {
            access_memory(pid, vaddr, rw); // Perform memory access with read/write
        } else {
            printf("Invalid command: %s", line); // Handle invalid command format
        }
    }

    return 0;
}
