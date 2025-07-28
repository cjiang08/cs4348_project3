#ifndef MANAGER_H
#define MANAGER_H

void alloc(int pid, int num_pages);                     // Allocate pages
void free_memory(int pid);                              // Deallocate memory
void access_memory(int pid, int vaddr, const char* rw); // Read/write virtual address

#endif
