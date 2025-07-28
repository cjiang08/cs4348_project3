#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#define MAX_PAGES 256 // Max virtual pages per process

// Single page table entry (PTE)
typedef struct {
    int valid;           // Valid bit: 1 if page is mapped
    int frame_number;    // Frame number in physical memory
    int reference_bit;   // Used for LRU tracking
    int modified_bit;    // 1 if the page has been written to
} PageTableEntry;

// Page table for a process
typedef struct {
    int pid;                     // Process ID
    PageTableEntry entries[MAX_PAGES]; // All entries for this process
} PageTable;

PageTable* create_page_table(int pid);  // Allocate new page table
void destroy_page_table(PageTable* pt); // Free page table

#endif
