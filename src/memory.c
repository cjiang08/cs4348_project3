#include "memory.h"

Frame frame_table[NUM_FRAMES];

void init_memory() {
    for (int i = 0; i < NUM_FRAMES; i++) {
        frame_table[i].frame_id = i;
        frame_table[i].occupied = 0;
        frame_table[i].process_id = -1;
        frame_table[i].page_number = -1;
    }
}

int find_free_frame() {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (!frame_table[i].occupied){
            return i;
        }
    }

    return -1;
}

void free_process_frames(int pid) {
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (frame_table[i].process_id == pid) {
            frame_table[i].occupied = 0;
            frame_table[i].process_id = -1;
            frame_table[i].page_number = -1;
        }
    }
}
