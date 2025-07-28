#ifndef MEMORY_H
#define MEMORY_H

#define FRAME_SIZE 4096     // = 4KB
#define NUM_FRAMES 256      // total phys mem: 256 frames = 1MB

// one physical frame
typedef struct {
    int frame_id;           
    int occupied;           
    int process_id;        
    int page_number;        
} Frame;

extern Frame frame_table[NUM_FRAMES]; 

void init_memory();                 
int find_free_frame();              
void free_process_frames(int pid); 

#endif
