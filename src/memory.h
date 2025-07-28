#ifndef MEMORY_H
#define MEMORY_H

#define FRAME_SIZE 4096     // Each frame is 4KB
#define NUM_FRAMES 256      // Total physical memory: 256 frames = 1MB

// Frame structure representing one physical frame
typedef struct {
    int frame_id;           // Unique ID of the frame
    int occupied;           // Whether the frame is currently used
    int process_id;         // ID of process using this frame
    int page_number;        // Page number within the process
} Frame;

extern Frame frame_table[NUM_FRAMES]; // Global array of all frames

void init_memory();                 // Initialize all frames
int find_free_frame();              // Find an unused frame
void free_process_frames(int pid);  // Free all frames owned by a process

#endif
