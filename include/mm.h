#ifndef MM_H
#define MM_H

void memory_management_init();

void* kalloc();
void free(void* ptr);
#endif //MM_H