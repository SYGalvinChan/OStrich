#ifndef MM_AUX_H
#define MM_AUX_H

/*
 * The BCM2711 device has three Auxiliary peripherals: One mini UART (UART1) and two SPI masters (SPI1 & SPI2)
 * The Auxiliary register base address is 0x7E215000.
 */

#define AUX_BASE_ADDR           0x7E215000

#define AUX_IRQ                 (uint32_t *) (AUX_BASE_ADDR + 0x00)  // Auxiliary Interrupt status
#define AUX_ENABLES             (uint32_t *) (AUX_BASE_ADDR + 0x04)  // Auxiliary enables

// Mini UART
#define AUX_MU_IO_REG           (uint32_t *) (AUX_BASE_ADDR + 0x40)  // Mini UART I/O Data
#define AUX_MU_IER_REG          (uint32_t *) (AUX_BASE_ADDR + 0x44)  // Mini UART Interrupt Enable
#define AUX_MU_IIR_REG          (uint32_t *) (AUX_BASE_ADDR + 0x48)  // Mini UART Interrupt Identify
#define AUX_MU_LCR_REG          (uint32_t *) (AUX_BASE_ADDR + 0x4c)  // Mini UART Line Control
#define AUX_MU_MCR_REG          (uint32_t *) (AUX_BASE_ADDR + 0x50)  // Mini UART Modem Control
#define AUX_MU_LSR_REG          (uint32_t *) (AUX_BASE_ADDR + 0x54)  // Mini UART Line Status
#define AUX_MU_MSR_REG          (uint32_t *) (AUX_BASE_ADDR + 0x58)  // Mini UART Modem Status
#define AUX_MU_SCRATCH          (uint32_t *) (AUX_BASE_ADDR + 0x5c)  // Mini UART Scratch
#define AUX_MU_CNTL_REG         (uint32_t *) (AUX_BASE_ADDR + 0x60)  // Mini UART Extra Control
#define AUX_MU_STAT_REG         (uint32_t *) (AUX_BASE_ADDR + 0x64)  // Mini UART Extra Status
#define AUX_MU_BAUD_REG         (uint32_t *) (AUX_BASE_ADDR + 0x68)  // Mini UART Baudrate
// SPI
#define AUX_SPI1_CNTL0_REG      (uint32_t *) (AUX_BASE_ADDR + 0x80)  // SPI 1 Control register 0
#define AUX_SPI1_CNTL1_REG      (uint32_t *) (AUX_BASE_ADDR + 0x84)  // SPI 1 Control register 1
#define AUX_SPI1_STAT_REG       (uint32_t *) (AUX_BASE_ADDR + 0x88)  // SPI 1 Status
#define AUX_SPI1_PEEK_REG       (uint32_t *) (AUX_BASE_ADDR + 0x8c)  // SPI 1 Peek
#define AUX_SPI1_IO_REGa        (uint32_t *) (AUX_BASE_ADDR + 0xa0)  // SPI 1 Data
#define AUX_SPI1_IO_REGb        (uint32_t *) (AUX_BASE_ADDR + 0xa4)  // SPI 1 Data
#define AUX_SPI1_IO_REGc        (uint32_t *) (AUX_BASE_ADDR + 0xa8)  // SPI 1 Data
#define AUX_SPI1_IO_REGd        (uint32_t *) (AUX_BASE_ADDR + 0xac)  // SPI 1 Data
#define AUX_SPI1_TXHOLD_REGa    (uint32_t *) (AUX_BASE_ADDR + 0xb0)  // SPI 1 Extended Data
#define AUX_SPI1_TXHOLD_REGb    (uint32_t *) (AUX_BASE_ADDR + 0xb4)  // SPI 1 Extended Data
#define AUX_SPI1_TXHOLD_REGc    (uint32_t *) (AUX_BASE_ADDR + 0xb8)  // SPI 1 Extended Data
#define AUX_SPI1_TXHOLD_REGd    (uint32_t *) (AUX_BASE_ADDR + 0xbc)  // SPI 1 Extended Data
#define AUX_SPI2_CNTL0_REG      (uint32_t *) (AUX_BASE_ADDR + 0xc0)  // SPI 2 Control register 0
#define AUX_SPI2_CNTL1_REG      (uint32_t *) (AUX_BASE_ADDR + 0xc4)  // SPI 2 Control register 1
#define AUX_SPI2_STAT_REG       (uint32_t *) (AUX_BASE_ADDR + 0xc8)  // SPI 2 Status
#define AUX_SPI2_PEEK_REG       (uint32_t *) (AUX_BASE_ADDR + 0xcc)  // SPI 2 Peek
#define AUX_SPI2_IO_REGa        (uint32_t *) (AUX_BASE_ADDR + 0xe0)  // SPI 2 Data
#define AUX_SPI2_IO_REGb        (uint32_t *) (AUX_BASE_ADDR + 0xe4)  // SPI 2 Data
#define AUX_SPI2_IO_REGc        (uint32_t *) (AUX_BASE_ADDR + 0xe8)  // SPI 2 Data
#define AUX_SPI2_IO_REGd        (uint32_t *) (AUX_BASE_ADDR + 0xec)  // SPI 2 Data
#define AUX_SPI2_TXHOLD_REGa    (uint32_t *) (AUX_BASE_ADDR + 0xf0)  // SPI 2 Extended Data
#define AUX_SPI2_TXHOLD_REGb    (uint32_t *) (AUX_BASE_ADDR + 0xf4)  // SPI 2 Extended Data
#define AUX_SPI2_TXHOLD_REGc    (uint32_t *) (AUX_BASE_ADDR + 0xf8)  // SPI 2 Extended Data
#define AUX_SPI2_TXHOLD_REGd    (uint32_t *) (AUX_BASE_ADDR + 0xfc)  // SPI 2 Extended Data

#endif
