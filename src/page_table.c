#include "page_table.h"
#include <stdlib.h>

// Create and initialize a new page table for a process
PageTable* create_page_table(int pid) {
    PageTable* pt = malloc(sizeof(PageTable));
    pt->pid = pid;

    // Set all entries to invalid
    for (int i = 0; i < MAX_PAGES; i++) {
        pt->entries[i].valid = 0;
        pt->entries[i].frame_number = -1;
        pt->entries[i].reference_bit = 0;
        pt->entries[i].modified_bit = 0;
    }
    return pt;
}

// Free the memory used by a page table
void destroy_page_table(PageTable* pt) {
    free(pt);
}
