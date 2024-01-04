#ifndef INTERRUPT_CONTROLLER_H
#define INTERRUPT_CONTROLLER_H

#include "memory_map/interrupt_controller.h"

void interrupt_controller_init();

int get_irq_src(int cpu_id);

#endif