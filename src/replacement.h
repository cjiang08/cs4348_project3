#ifndef REPLACEMENT_H
#define REPLACEMENT_H

void init_replacement();            
int select_victim_frame_fifo();     
int select_victim_frame_lru();      
void track_frame_use(int frame_id); 

#endif
