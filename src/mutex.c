#include "mutex.h"
#include <stdint.h>

void mutex_init(struct mutex* m, char* name) {
    m->name = name;
    m->locked = 0;
}

// Not a good implementation but i lazy
void mutex_lock(struct mutex* m) {
    while (m->locked);
    m->locked = 1;
}

void mutex_unlock(struct mutex* m) {
    m->locked = 0;
}
