#include "gpio.h"
#include "memory_map/gpio.h"
#include "utils.h"

#include <stdint.h>

static uint32_t* GPIO_SEL_FUNC_REGISTERS[] = {GPFSEL0, GPFSEL1, GPFSEL2, GPFSEL3, GPFSEL4, GPFSEL5};
static uint32_t* GPIO_PUP_PDN_CNTRL_REGISTERS[] = {GPIO_PUP_PDN_CNTRL_REG0, GPIO_PUP_PDN_CNTRL_REG1, GPIO_PUP_PDN_CNTRL_REG2, GPIO_PUP_PDN_CNTRL_REG3};
static uint32_t* GPIO_SET_REGISTERS[] = {GPSET0, GPSET1};
static uint32_t* GPIO_CLEAR_REGISTERS[] = {GPCLR0, GPCLR1};

void gpio_set_func(int gpio_pin, int func) {
    volatile uint32_t register_value;
    volatile uint32_t* gpio_sel_func_register = GPIO_SEL_FUNC_REGISTERS[gpio_pin / 10];

    register_value = READ_REG_32(gpio_sel_func_register);
    register_value = register_value & ~(0b111 << ((gpio_pin % 10) * 3));
    register_value = register_value | func << ((gpio_pin % 10) * 3);
    WRITE_REG_32(gpio_sel_func_register, register_value);
}

void gpio_set_pull_state(int gpio_pin, int pull_state) {
    volatile uint32_t register_value;
    volatile uint32_t* gpio_pup_pdn_cntrl_register = GPIO_PUP_PDN_CNTRL_REGISTERS[gpio_pin / 16];

    register_value = READ_REG_32(gpio_pup_pdn_cntrl_register);
    register_value = register_value & ~(0b11 << ((gpio_pin % 16) * 2));
    register_value = register_value | pull_state << ((gpio_pin % 16) * 2);
    WRITE_REG_32(gpio_pup_pdn_cntrl_register, register_value);
}

void gpio_set(int gpio_pin) {
    volatile uint32_t* gpio_set_register = GPIO_SET_REGISTERS[gpio_pin / 32];
    WRITE_REG_32(gpio_set_register, 1 << (gpio_pin % 32));
}

void gpio_clear(int gpio_pin) {
    volatile uint32_t* gpio_clear_register = GPIO_CLEAR_REGISTERS[gpio_pin / 32];
    WRITE_REG_32(gpio_clear_register, 1 << (gpio_pin % 32));
}
