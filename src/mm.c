#include "mm.h"
#include "console.h"
#define MAX_PHYSICAL_ADDRESS 
struct free_page {
    struct free_page* next;
};
extern int _end;

void memory_management_init() {
    printf("kernel code end:%x", _end);

}
void* kalloc() {

}
void free(void* ptr) {

}