#include "replacement.h"
#include "memory.h"
#include <limits.h>

int fifo_queue[NUM_FRAMES]; // Circular queue of frame IDs
int fifo_front = 0;
int fifo_back = 0;
int fifo_size = 0;

int lru_timestamp[NUM_FRAMES]; // LRU: stores last-used time per frame
int current_time = 0;

// Call once at startup
void init_replacement() {
    for (int i = 0; i < NUM_FRAMES; i++) {
        fifo_queue[i] = -1;
        lru_timestamp[i] = 0;
    }
    fifo_front = fifo_back = fifo_size = 0;
    current_time = 0;
}

// FIFO: add used frame to queue
void track_frame_use(int frame_id) {
    // For FIFO, only enqueue if not already present
    int already_present = 0;
    for (int i = 0; i < fifo_size; i++) {
        int idx = (fifo_front + i) % NUM_FRAMES;
        if (fifo_queue[idx] == frame_id) {
            already_present = 1;
            break;
        }
    }

    if (!already_present && fifo_size < NUM_FRAMES) {
        fifo_queue[fifo_back] = frame_id;
        fifo_back = (fifo_back + 1) % NUM_FRAMES;
        fifo_size++;
    }

    // For LRU, update timestamp
    lru_timestamp[frame_id] = ++current_time;
}

// FIFO: return oldest frame in queue
int select_victim_frame_fifo() {
    if (fifo_size == 0) return -1;

    int victim = fifo_queue[fifo_front];
    fifo_front = (fifo_front + 1) % NUM_FRAMES;
    fifo_size--;
    return victim;
}

// LRU: return least recently used frame
int select_victim_frame_lru() {
    int min_time = INT_MAX;
    int victim = -1;
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (frame_table[i].occupied && lru_timestamp[i] < min_time) {
            min_time = lru_timestamp[i];
            victim = i;
        }
    }
    return victim;
}
