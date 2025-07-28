#ifndef MANAGER_H
#define MANAGER_H

void alloc(int pid, int num_pages);                     
void free_memory(int pid);                              
void access_memory(int pid, int vaddr, const char* rw); 

#endif
