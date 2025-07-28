#ifndef REPLACEMENT_H
#define REPLACEMENT_H

void init_replacement();            // Initialize queues or tracking
int select_victim_frame_fifo();     // FIFO algorithm
int select_victim_frame_lru();      // LRU algorithm
void track_frame_use(int frame_id); // Called on every access (for LRU)

#endif
