#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#define MAX_PAGES 256 

// single page table entry
typedef struct {
    int valid;           
    int frame_number;    
    int reference_bit;   
    int modified_bit;    
} PageTableEntry;

typedef struct {
    int pid;                    
    PageTableEntry entries[MAX_PAGES]; 
} PageTable;

PageTable* create_page_table(int pid); 
void destroy_page_table(PageTable* pt);

#endif
