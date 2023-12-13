#include "utils.h"
#include "gpio.h"
#include "memory_map/gpio.h"

#include <stdint.h>

#define DELAY_LOOP 100000

void infinite_loop_toggle_gpio() {

	// Sets GPIO Pin 5 to output
	gpio_set_func(5, GPIO_FUNC_OUTPUT);

    // Sets Pull Up/Pull Down resistor for GPIO Pin 5 to none
	gpio_set_pull_state(5, GPIO_PULL_NONE);

    int set = 1;
    while (1) {
        if (set) {
            gpio_set(5);
            set = 0;
        } else {
            gpio_clear(5);
            set = 1;
        }
        // Delay
        int ignore = 0;
        for (int i = 0; i < DELAY_LOOP; i++) {
            ignore += 1;
        }        
    }
}
