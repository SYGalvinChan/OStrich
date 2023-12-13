#ifndef MM_GPIO_H
#define MM_GPIO_H

/*
 * The GPIO has the following registers. All accesses are assumed to be 32-bit. The GPIO register base address is 0x7e200000.
 */
#define GPIO_BASE_ADDR          0x7E200000

#define GPFSEL0                 (uint32_t *) GPIO_BASE_ADDR + 0x00 // GPIO Function Select 0
#define GPFSEL1                 (uint32_t *) GPIO_BASE_ADDR + 0x04 // GPIO Function Select 1
#define GPFSEL2                 (uint32_t *) GPIO_BASE_ADDR + 0x08 // GPIO Function Select 2
#define GPFSEL3                 (uint32_t *) GPIO_BASE_ADDR + 0x0c // GPIO Function Select 3
#define GPFSEL4                 (uint32_t *) GPIO_BASE_ADDR + 0x10 // GPIO Function Select 4
#define GPFSEL5                 (uint32_t *) GPIO_BASE_ADDR + 0x14 // GPIO Function Select 5
#define GPSET0                  (uint32_t *) GPIO_BASE_ADDR + 0x1c // GPIO Pin Output Set 0
#define GPSET1                  (uint32_t *) GPIO_BASE_ADDR + 0x20 // GPIO Pin Output Set 1
#define GPCLR0                  (uint32_t *) GPIO_BASE_ADDR + 0x28 // GPIO Pin Output Clear 0
#define GPCLR1                  (uint32_t *) GPIO_BASE_ADDR + 0x2c // GPIO Pin Output Clear 1
#define GPLEV0                  (uint32_t *) GPIO_BASE_ADDR + 0x34 // GPIO Pin Level 0
#define GPLEV1                  (uint32_t *) GPIO_BASE_ADDR + 0x38 // GPIO Pin Level 1
#define GPEDS0                  (uint32_t *) GPIO_BASE_ADDR + 0x40 // GPIO Pin Event Detect Status 0
#define GPEDS1                  (uint32_t *) GPIO_BASE_ADDR + 0x44 // GPIO Pin Event Detect Status 1
#define GPREN0                  (uint32_t *) GPIO_BASE_ADDR + 0x4c // GPIO Pin Rising Edge Detect Enable 0
#define GPREN1                  (uint32_t *) GPIO_BASE_ADDR + 0x50 // GPIO Pin Rising Edge Detect Enable 1
#define GPFEN0                  (uint32_t *) GPIO_BASE_ADDR + 0x58 // GPIO Pin Falling Edge Detect Enable 0
#define GPFEN1                  (uint32_t *) GPIO_BASE_ADDR + 0x5c // GPIO Pin Falling Edge Detect Enable 1
#define GPHEN0                  (uint32_t *) GPIO_BASE_ADDR + 0x64 // GPIO Pin High Detect Enable 0
#define GPHEN1                  (uint32_t *) GPIO_BASE_ADDR + 0x68 // GPIO Pin High Detect Enable 1
#define GPLEN0                  (uint32_t *) GPIO_BASE_ADDR + 0x70 // GPIO Pin Low Detect Enable 0
#define GPLEN1                  (uint32_t *) GPIO_BASE_ADDR + 0x74 // GPIO Pin Low Detect Enable 1
#define GPAREN0                 (uint32_t *) GPIO_BASE_ADDR + 0x7c // GPIO Pin Async. Rising Edge Detect 0
#define GPAREN1                 (uint32_t *) GPIO_BASE_ADDR + 0x80 // GPIO Pin Async. Rising Edge Detect 1
#define GPAFEN0                 (uint32_t *) GPIO_BASE_ADDR + 0x88 // GPIO Pin Async. Falling Edge Detect 0
#define GPAFEN1                 (uint32_t *) GPIO_BASE_ADDR + 0x8c // GPIO Pin Async. Falling Edge Detect 1
#define GPIO_PUP_PDN_CNTRL_REG0 (uint32_t *) GPIO_BASE_ADDR + 0xe4 // GPIO Pull-up / Pull-down Register 0
#define GPIO_PUP_PDN_CNTRL_REG1 (uint32_t *) GPIO_BASE_ADDR + 0xe8 // GPIO Pull-up / Pull-down Register 1
#define GPIO_PUP_PDN_CNTRL_REG2 (uint32_t *) GPIO_BASE_ADDR + 0xec // GPIO Pull-up / Pull-down Register 2
#define GPIO_PUP_PDN_CNTRL_REG3 (uint32_t *) GPIO_BASE_ADDR + 0xf0 // GPIO Pull-up / Pull-down Register 3

#endif // MM_GPIO_H
