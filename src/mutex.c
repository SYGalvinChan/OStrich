#include "mutex.h"
#include "utils.h"

void mutex_init(struct mutex* m, char* name) {
    m->name = name;
    m->locked = 0;
}

// Not a good implementation but i lazy
void mutex_lock(struct mutex* m) {
    do {
        delay(cpu_id() * 0x200);
    } while (m->locked);

    m->locked = 1;
    if (is_irq_enabled()) {
        m->prev_irq_enabled = 1;
    } else {
        m->prev_irq_enabled = 0;
    }
    irq_disable();
}

void mutex_unlock(struct mutex* m) {
    m->locked = 0;
    if (m->prev_irq_enabled) {
        irq_enable();
    }
}
