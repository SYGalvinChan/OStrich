#include "utils.h"
#include "memory_map/gpio.h"

#include <stdint.h>

#define DELAY_LOOP 100000

void infinite_loop_toggle_gpio() {
    uint32_t register_value;

	// Sets GPIO Pin 0 to output
	register_value = READ_REG_32(GPFSEL0);
	register_value = register_value & ~(0b111);
	register_value = register_value | 0b001;
	WRITE_REG_32(GPFSEL0, register_value);

    // Sets Pull Up/Pull Down resistor for GPIO Pin 0 to none
	register_value = READ_REG_32(GPIO_PUP_PDN_CNTRL_REG0);
	register_value = register_value & ~(0b11);
	register_value = register_value | 0b00;
	WRITE_REG_32(GPIO_PUP_PDN_CNTRL_REG0, register_value);

    int set = 1;
    while (1) {
        if (set) {
            WRITE_REG_32(GPSET0, 1);
            set = 0;
        } else {
            WRITE_REG_32(GPCLR0, 1);
            set = 1;
        }
        // Delay
        int ignore = 0;
        for (int i = 0; i < DELAY_LOOP; i++) {
            ignore += 1;
        }        
    }
}
