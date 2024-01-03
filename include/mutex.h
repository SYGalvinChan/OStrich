#ifndef MUTEX_H
#define MUTEX_H

struct mutex {
    int locked;
    int prev_irq_enabled;

    // For debugging
    char* name;
};

void mutex_init(struct mutex* m, char* name);

void mutex_lock(struct mutex* m);
void mutex_unlock(struct mutex* m);

#endif // MUTEX_H