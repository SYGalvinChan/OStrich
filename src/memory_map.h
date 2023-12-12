#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

/*
 * This file defines addresses of various memory-mapped peripherals.
 *
 * These addresses are specified https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf.
 */
/*
 * The GPIO has the following registers. All accesses are assumed to be 32-bit. The GPIO register base address is 0x7e200000.
 */
#define GPIO_BASE_ADDR          0x7E200000

#define GPFSEL0                 GPIO_BASE_ADDR + 0x00 // GPIO Function Select 0
#define GPFSEL1                 GPIO_BASE_ADDR + 0x04 // GPIO Function Select 1
#define GPFSEL2                 GPIO_BASE_ADDR + 0x08 // GPIO Function Select 2
#define GPFSEL3                 GPIO_BASE_ADDR + 0x0c // GPIO Function Select 3
#define GPFSEL4                 GPIO_BASE_ADDR + 0x10 // GPIO Function Select 4
#define GPFSEL5                 GPIO_BASE_ADDR + 0x14 // GPIO Function Select 5
#define GPSET0                  GPIO_BASE_ADDR + 0x1c // GPIO Pin Output Set 0
#define GPSET1                  GPIO_BASE_ADDR + 0x20 // GPIO Pin Output Set 1
#define GPCLR0                  GPIO_BASE_ADDR + 0x28 // GPIO Pin Output Clear 0
#define GPCLR1                  GPIO_BASE_ADDR + 0x2c // GPIO Pin Output Clear 1
#define GPLEV0                  GPIO_BASE_ADDR + 0x34 // GPIO Pin Level 0
#define GPLEV1                  GPIO_BASE_ADDR + 0x38 // GPIO Pin Level 1
#define GPEDS0                  GPIO_BASE_ADDR + 0x40 // GPIO Pin Event Detect Status 0
#define GPEDS1                  GPIO_BASE_ADDR + 0x44 // GPIO Pin Event Detect Status 1
#define GPREN0                  GPIO_BASE_ADDR + 0x4c // GPIO Pin Rising Edge Detect Enable 0
#define GPREN1                  GPIO_BASE_ADDR + 0x50 // GPIO Pin Rising Edge Detect Enable 1
#define GPFEN0                  GPIO_BASE_ADDR + 0x58 // GPIO Pin Falling Edge Detect Enable 0
#define GPFEN1                  GPIO_BASE_ADDR + 0x5c // GPIO Pin Falling Edge Detect Enable 1
#define GPHEN0                  GPIO_BASE_ADDR + 0x64 // GPIO Pin High Detect Enable 0
#define GPHEN1                  GPIO_BASE_ADDR + 0x68 // GPIO Pin High Detect Enable 1
#define GPLEN0                  GPIO_BASE_ADDR + 0x70 // GPIO Pin Low Detect Enable 0
#define GPLEN1                  GPIO_BASE_ADDR + 0x74 // GPIO Pin Low Detect Enable 1
#define GPAREN0                 GPIO_BASE_ADDR + 0x7c // GPIO Pin Async. Rising Edge Detect 0
#define GPAREN1                 GPIO_BASE_ADDR + 0x80 // GPIO Pin Async. Rising Edge Detect 1
#define GPAFEN0                 GPIO_BASE_ADDR + 0x88 // GPIO Pin Async. Falling Edge Detect 0
#define GPAFEN1                 GPIO_BASE_ADDR + 0x8c // GPIO Pin Async. Falling Edge Detect 1
#define GPIO_PUP_PDN_CNTRL_REG0 GPIO_BASE_ADDR + 0xe4 // GPIO Pull-up / Pull-down Register 0
#define GPIO_PUP_PDN_CNTRL_REG1 GPIO_BASE_ADDR + 0xe8 // GPIO Pull-up / Pull-down Register 1
#define GPIO_PUP_PDN_CNTRL_REG2 GPIO_BASE_ADDR + 0xec // GPIO Pull-up / Pull-down Register 2
#define GPIO_PUP_PDN_CNTRL_REG3 GPIO_BASE_ADDR + 0xf0 // GPIO Pull-up / Pull-down Register 3

// ###### Auxiliaries #####
/*
 * The BCM2711 device has three Auxiliary peripherals: One mini UART (UART1) and two SPI masters (SPI1 & SPI2)
 * The Auxiliary register base address is 0x7E215000.
 */

#define AUX_BASE_ADDR           0x7E215000

#define AUX_IRQ                 AUX_BASE_ADDR + 0x00  // Auxiliary Interrupt status
#define AUX_ENABLES             AUX_BASE_ADDR + 0x04  // Auxiliary enables

// Mini UART
#define AUX_MU_IO_REG           AUX_BASE_ADDR + 0x40  // Mini UART I/O Data
#define AUX_MU_IER_REG          AUX_BASE_ADDR + 0x44  // Mini UART Interrupt Enable
#define AUX_MU_IIR_REG          AUX_BASE_ADDR + 0x48  // Mini UART Interrupt Identify
#define AUX_MU_LCR_REG          AUX_BASE_ADDR + 0x4c  // Mini UART Line Control
#define AUX_MU_MCR_REG          AUX_BASE_ADDR + 0x50  // Mini UART Modem Control
#define AUX_MU_LSR_REG          AUX_BASE_ADDR + 0x54  // Mini UART Line Status
#define AUX_MU_MSR_REG          AUX_BASE_ADDR + 0x58  // Mini UART Modem Status
#define AUX_MU_SCRATCH          AUX_BASE_ADDR + 0x5c  // Mini UART Scratch
#define AUX_MU_CNTL_REG         AUX_BASE_ADDR + 0x60  // Mini UART Extra Control
#define AUX_MU_STAT_REG         AUX_BASE_ADDR + 0x64  // Mini UART Extra Status
#define AUX_MU_BAUD_REG         AUX_BASE_ADDR + 0x68  // Mini UART Baudrate
// SPI
#define AUX_SPI1_CNTL0_REG      AUX_BASE_ADDR + 0x80  // SPI 1 Control register 0
#define AUX_SPI1_CNTL1_REG      AUX_BASE_ADDR + 0x84  // SPI 1 Control register 1
#define AUX_SPI1_STAT_REG       AUX_BASE_ADDR + 0x88  // SPI 1 Status
#define AUX_SPI1_PEEK_REG       AUX_BASE_ADDR + 0x8c  // SPI 1 Peek
#define AUX_SPI1_IO_REGa        AUX_BASE_ADDR + 0xa0  // SPI 1 Data
#define AUX_SPI1_IO_REGb        AUX_BASE_ADDR + 0xa4  // SPI 1 Data
#define AUX_SPI1_IO_REGc        AUX_BASE_ADDR + 0xa8  // SPI 1 Data
#define AUX_SPI1_IO_REGd        AUX_BASE_ADDR + 0xac  // SPI 1 Data
#define AUX_SPI1_TXHOLD_REGa    AUX_BASE_ADDR + 0xb0  // SPI 1 Extended Data
#define AUX_SPI1_TXHOLD_REGb    AUX_BASE_ADDR + 0xb4  // SPI 1 Extended Data
#define AUX_SPI1_TXHOLD_REGc    AUX_BASE_ADDR + 0xb8  // SPI 1 Extended Data
#define AUX_SPI1_TXHOLD_REGd    AUX_BASE_ADDR + 0xbc  // SPI 1 Extended Data
#define AUX_SPI2_CNTL0_REG      AUX_BASE_ADDR + 0xc0  // SPI 2 Control register 0
#define AUX_SPI2_CNTL1_REG      AUX_BASE_ADDR + 0xc4  // SPI 2 Control register 1
#define AUX_SPI2_STAT_REG       AUX_BASE_ADDR + 0xc8  // SPI 2 Status
#define AUX_SPI2_PEEK_REG       AUX_BASE_ADDR + 0xcc  // SPI 2 Peek
#define AUX_SPI2_IO_REGa        AUX_BASE_ADDR + 0xe0  // SPI 2 Data
#define AUX_SPI2_IO_REGb        AUX_BASE_ADDR + 0xe4  // SPI 2 Data
#define AUX_SPI2_IO_REGc        AUX_BASE_ADDR + 0xe8  // SPI 2 Data
#define AUX_SPI2_IO_REGd        AUX_BASE_ADDR + 0xec  // SPI 2 Data
#define AUX_SPI2_TXHOLD_REGa    AUX_BASE_ADDR + 0xf0  // SPI 2 Extended Data
#define AUX_SPI2_TXHOLD_REGb    AUX_BASE_ADDR + 0xf4  // SPI 2 Extended Data
#define AUX_SPI2_TXHOLD_REGc    AUX_BASE_ADDR + 0xf8  // SPI 2 Extended Data
#define AUX_SPI2_TXHOLD_REGd    AUX_BASE_ADDR + 0xfc  // SPI 2 Extended Data

#endif // MEMORY_MAP_H
