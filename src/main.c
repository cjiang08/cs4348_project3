#include <stdio.h>
#include <string.h>
#include "memory.h"
#include "manager.h"
#include "replacement.h"


int main() {
    init_memory(); 
	init_replacement(); 

    char line[100];
    char rw[10];
    int pid, num_pages, vaddr;

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "alloc P%d %d", &pid, &num_pages) == 2) {
            alloc(pid, num_pages); 
        } 
        else if (sscanf(line, "free P%d", &pid) == 1) {
            free_memory(pid); 
        } 
        else if (sscanf(line, "access P%d %d %s", &pid, &vaddr, rw) == 3) {
            access_memory(pid, vaddr, rw);
        } 
        else {
            printf("Invalid command: %s", line); 
        }
    }

    return 0;
}
