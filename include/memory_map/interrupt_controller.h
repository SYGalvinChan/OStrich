#ifndef MM_INTERRUPT_CONTROLLER_H
#define MM_INTERRUPT_CONTROLLER_H

#define ARM_LOCAL_BASE_ADDRESS (void*) 0xFF800000

#define ARM_CONTROL         ARM_LOCAL_BASE_ADDRESS + 0x00    // ARM Timer and AXI Error IRQ control
#define CORE_IRQ_CONTROL    ARM_LOCAL_BASE_ADDRESS + 0x0c    // VideoCore Interrupt Control
#define PMU_CONTROL_SET     ARM_LOCAL_BASE_ADDRESS + 0x10    // PMU Bit Set
#define PMU_CONTROL_CLR     ARM_LOCAL_BASE_ADDRESS + 0x14    // PMU Bit Clear
#define PERI_IRQ_ROUTE0     ARM_LOCAL_BASE_ADDRESS + 0x24    // Peripheral Interrupt Routing (Bank 0)
#define AXI_QUIET_TIME      ARM_LOCAL_BASE_ADDRESS + 0x30    // AXI Outstanding Transaction Time and IRQ Control
#define LOCAL_TIMER_CONTROL ARM_LOCAL_BASE_ADDRESS + 0x34    // Local Timer Control
#define LOCAL_TIMER_IRQ     ARM_LOCAL_BASE_ADDRESS + 0x38    // Local Timer Reload and Interrupt
#define TIMER_CNTRL0 Timer  ARM_LOCAL_BASE_ADDRESS + 0x40    // Interrupt Control for ARM Core 0
#define TIMER_CNTRL1 Timer  ARM_LOCAL_BASE_ADDRESS + 0x44    // Interrupt Control for ARM Core 1
#define TIMER_CNTRL2 Timer  ARM_LOCAL_BASE_ADDRESS + 0x48    // Interrupt Control for ARM Core 2
#define TIMER_CNTRL3 Timer  ARM_LOCAL_BASE_ADDRESS + 0x4c    // Interrupt Control for ARM Core 3
#define MAILBOX_CNTRL0      ARM_LOCAL_BASE_ADDRESS + 0x50    // Mailbox Interrupt Control for ARM Core 0
#define MAILBOX_CNTRL1      ARM_LOCAL_BASE_ADDRESS + 0x54    // Mailbox Interrupt Control for ARM Core 1
#define MAILBOX_CNTRL2      ARM_LOCAL_BASE_ADDRESS + 0x58    // Mailbox Interrupt Control for ARM Core 2
#define MAILBOX_CNTRL3      ARM_LOCAL_BASE_ADDRESS + 0x5c    // Mailbox Interrupt Control for ARM Core 3
#define IRQ_SOURCE0         ARM_LOCAL_BASE_ADDRESS + 0x60    // IRQ Source flags for ARM Core 0
#define IRQ_SOURCE1         ARM_LOCAL_BASE_ADDRESS + 0x64    // IRQ Source flags for ARM Core 1
#define IRQ_SOURCE2         ARM_LOCAL_BASE_ADDRESS + 0x68    // IRQ Source flags for ARM Core 2
#define IRQ_SOURCE3         ARM_LOCAL_BASE_ADDRESS + 0x6c    // IRQ Source flags for ARM Core 3
#define FIQ_SOURCE0         ARM_LOCAL_BASE_ADDRESS + 0x70    // FIQ Source flags for ARM Core 0
#define FIQ_SOURCE1         ARM_LOCAL_BASE_ADDRESS + 0x74    // FIQ Source flags for ARM Core 1
#define FIQ_SOURCE2         ARM_LOCAL_BASE_ADDRESS + 0x78    // FIQ Source flags for ARM Core 2
#define FIQ_SOURCE3         ARM_LOCAL_BASE_ADDRESS + 0x7c    // FIQ Source flags for ARM Core 3

#define ARMC_BASE_ADDRESS (void*) 0xFE00B000

#define IRQ0_PENDING0     ARMC_BASE_ADDRESS + 0x200     // ARM Core 0 IRQ Enabled Interrupt Pending bits [31:0]
#define IRQ0_PENDING1     ARMC_BASE_ADDRESS + 0x204     // ARM Core 0 IRQ Enabled Interrupt pending bits [63:32]
#define IRQ0_PENDING2     ARMC_BASE_ADDRESS + 0x208     // ARM Core 0 IRQ Enabled Interrupt pending bits [79:64]
#define IRQ0_SET_EN_0     ARMC_BASE_ADDRESS + 0x210     // Write to Set ARM Core 0 IRQ enable bits [31:0]
#define IRQ0_SET_EN_1     ARMC_BASE_ADDRESS + 0x214     // Write to Set ARM Core 0 IRQ enable bits [63:32]
#define IRQ0_SET_EN_2     ARMC_BASE_ADDRESS + 0x218     // Write to Set ARM Core 0 IRQ enable bits[79:64]
#define IRQ0_CLR_EN_0     ARMC_BASE_ADDRESS + 0x220     // Write to Clear ARM Core 0 IRQ enable bits [31:0]
#define IRQ0_CLR_EN_1     ARMC_BASE_ADDRESS + 0x224     // Write to Clear ARM Core 0 IRQ enable bits [63:32]
#define IRQ0_CLR_EN_2     ARMC_BASE_ADDRESS + 0x228     // Write to Clear ARM Core 0 IRQ enable bits [79:64]
#define IRQ_STATUS0       ARMC_BASE_ADDRESS + 0x230     // Interrupt Line bits [31:0]
#define IRQ_STATUS1       ARMC_BASE_ADDRESS + 0x234     // Interrupt Line bits [63:32]
#define IRQ_STATUS2       ARMC_BASE_ADDRESS + 0x238     // Interrupt Line bits [79:64]
#define IRQ1_PENDING0     ARMC_BASE_ADDRESS + 0x240     // ARM Core 1 IRQ Enabled Interrupt pending bits [31:0]
#define IRQ1_PENDING1     ARMC_BASE_ADDRESS + 0x244     // ARM Core 1 IRQ Enabled Interrupt pending bits [63:32]
#define IRQ1_PENDING2     ARMC_BASE_ADDRESS + 0x248     // ARM Core 1 IRQ Enabled Interrupt pending bits [79:64]
#define IRQ1_SET_EN_0     ARMC_BASE_ADDRESS + 0x250     // Write to Set ARM Core 1 IRQ enable bits [31:0]
#define IRQ1_SET_EN_1     ARMC_BASE_ADDRESS + 0x254     // Write to Set ARM Core 1 IRQ enable bits [63:32]
#define IRQ1_SET_EN_2     ARMC_BASE_ADDRESS + 0x258     // Write to Set ARM Core 1 IRQ enable bits[79:64]
#define IRQ1_CLR_EN_0     ARMC_BASE_ADDRESS + 0x260     // Write to Clear ARM Core 1 IRQ enable bits [31:0]
#define IRQ1_CLR_EN_1     ARMC_BASE_ADDRESS + 0x264     // Write to Clear ARM Core 1 IRQ enable bits [63:32]
#define IRQ1_CLR_EN_2     ARMC_BASE_ADDRESS + 0x268     // Write to Clear ARM Core 1 IRQ enable bits [79:64]
#define IRQ2_PENDING0     ARMC_BASE_ADDRESS + 0x280     // ARM Core 2 IRQ Enabled Interrupt pending bits [31:0]
#define IRQ2_PENDING1     ARMC_BASE_ADDRESS + 0x284     // ARM Core 2 IRQ Enabled Interrupt pending bits [63:32]
#define IRQ2_PENDING2     ARMC_BASE_ADDRESS + 0x288     // ARM Core 2 IRQ Enabled Interrupt pending bits [79:64]
#define IRQ2_SET_EN_0     ARMC_BASE_ADDRESS + 0x290     // Write to Set ARM Core 2 IRQ enable bits [31:0]
#define IRQ2_SET_EN_1     ARMC_BASE_ADDRESS + 0x294     // Write to Set ARM Core 2 IRQ enable bits [63:32]
#define IRQ2_SET_EN_2     ARMC_BASE_ADDRESS + 0x298     // Write to Set ARM Core 2 IRQ enable bits[79:64]
#define IRQ2_CLR_EN_0     ARMC_BASE_ADDRESS + 0x2a0     // Write to Clear ARM Core 2 IRQ enable bits [31:0]
#define IRQ2_CLR_EN_1     ARMC_BASE_ADDRESS + 0x2a4     // Write to Clear ARM Core 2 IRQ enable bits [63:32]
#define IRQ2_CLR_EN_2     ARMC_BASE_ADDRESS + 0x2a8     // Write to Clear ARM Core 2 IRQ enable bits [79:64]
#define IRQ3_PENDING0     ARMC_BASE_ADDRESS + 0x2c0     // ARM Core 3 IRQ Enabled Interrupt pending bits [31:0]
#define IRQ3_PENDING1     ARMC_BASE_ADDRESS + 0x2c4     // ARM Core 3 IRQ Enabled Interrupt pending bits [63:32]
#define IRQ3_PENDING2     ARMC_BASE_ADDRESS + 0x2c8     // ARM Core 3 IRQ Enabled Interrupt pending bits [79:64]
#define IRQ3_SET_EN_0     ARMC_BASE_ADDRESS + 0x2d0     // Write to Set ARM Core 3 IRQ enable bits [31:0]
#define IRQ3_SET_EN_1     ARMC_BASE_ADDRESS + 0x2d4     // Write to Set ARM Core 3 IRQ enable bits [63:32]
#define IRQ3_SET_EN_2     ARMC_BASE_ADDRESS + 0x2d8     // Write to Set ARM Core 3 IRQ enable bits[79:64]
#define IRQ3_CLR_EN_0     ARMC_BASE_ADDRESS + 0x2e0     // Write to Clear ARM Core 3 IRQ enable bits [31:0]
#define IRQ3_CLR_EN_1     ARMC_BASE_ADDRESS + 0x2e4     // Write to Clear ARM Core 3 IRQ enable bits [63:32]
#define IRQ3_CLR_EN_2     ARMC_BASE_ADDRESS + 0x2e8     // Write to Clear ARM Core 3 IRQ enable bits [79:64]
#define FIQ0_PENDING0     ARMC_BASE_ADDRESS + 0x300     // ARM Core 0 FIQ Enabled Interrupt pending bits [31:0]
#define FIQ0_PENDING1     ARMC_BASE_ADDRESS + 0x304     // ARM Core 0 FIQ Enabled Interrupt pending bits [63:32]
#define FIQ0_PENDING2     ARMC_BASE_ADDRESS + 0x308     // ARM Core 0 FIQ Enabled Interrupt pending bits [79:64]
#define FIQ0_SET_EN_0     ARMC_BASE_ADDRESS + 0x310     // Write to Set ARM Core 0 FIQ enable bits [31:0]
#define FIQ0_SET_EN_1     ARMC_BASE_ADDRESS + 0x314     // Write to Set ARM Core 0 FIQ enable bits [63:32]
#define FIQ0_SET_EN_2     ARMC_BASE_ADDRESS + 0x318     // Write to Set ARM Core 0 FIQ enable bits[79:64]
#define FIQ0_CLR_EN_0     ARMC_BASE_ADDRESS + 0x320     // Write to Clear ARM Core 0 FIQ enable bits [31:0]
#define FIQ0_CLR_EN_1     ARMC_BASE_ADDRESS + 0x324     // Write to Clear ARM Core 0 FIQ enable bits [63:32]
#define FIQ0_CLR_EN_2     ARMC_BASE_ADDRESS + 0x328     // Write to Clear ARM Core 0 FIQ enable bits [79:64]
#define FIQ1_PENDING0     ARMC_BASE_ADDRESS + 0x340     // ARM Core 1 FIQ Enabled Interrupt pending bits [31:0]
#define FIQ1_PENDING1     ARMC_BASE_ADDRESS + 0x344     // ARM Core 1 FIQ Enabled Interrupt pending bits [63:32]
#define FIQ1_PENDING2     ARMC_BASE_ADDRESS + 0x348     // ARM Core 1 FIQ Enabled Interrupt pending bits [79:64]
#define FIQ1_SET_EN_0     ARMC_BASE_ADDRESS + 0x350     // Write to Set ARM Core 1 FIQ enable bits [31:0]
#define FIQ1_SET_EN_1     ARMC_BASE_ADDRESS + 0x354     // Write to Set ARM Core 1 FIQ enable bits [63:32]
#define FIQ1_SET_EN_2     ARMC_BASE_ADDRESS + 0x358     // Write to Set ARM Core 1 FIQ enable bits[79:64]
#define FIQ1_CLR_EN_0     ARMC_BASE_ADDRESS + 0x360     // Write to Clear ARM Core 1 FIQ enable bits [31:0]
#define FIQ1_CLR_EN_1     ARMC_BASE_ADDRESS + 0x364     // Write to Clear ARM Core 1 FIQ enable bits [63:32]
#define FIQ1_CLR_EN_2     ARMC_BASE_ADDRESS + 0x368     // Write to Clear ARM Core 1 FIQ enable bits [79:64]
#define FIQ2_PENDING0     ARMC_BASE_ADDRESS + 0x380     // ARM Core 2 FIQ Enabled Interrupt pending bits [31:0]
#define FIQ2_PENDING1     ARMC_BASE_ADDRESS + 0x384     // ARM Core 2 FIQ Enabled Interrupt pending bits [63:32]
#define FIQ2_PENDING2     ARMC_BASE_ADDRESS + 0x388     // ARM Core 2 FIQ Enabled Interrupt pending bits [79:64]
#define FIQ2_SET_EN_0     ARMC_BASE_ADDRESS + 0x390     // Write to Set ARM Core 2 FIQ enable bits [31:0]
#define FIQ2_SET_EN_1     ARMC_BASE_ADDRESS + 0x394     // Write to Set ARM Core 2 FIQ enable bits [63:32]
#define FIQ2_SET_EN_2     ARMC_BASE_ADDRESS + 0x398     // Write to Set ARM Core 2 FIQ enable bits[79:64]
#define FIQ2_CLR_EN_0     ARMC_BASE_ADDRESS + 0x3a0     // Write to Clear ARM Core 2 FIQ enable bits [31:0]
#define FIQ2_CLR_EN_1     ARMC_BASE_ADDRESS + 0x3a4     // Write to Clear ARM Core 2 FIQ enable bits [63:32]
#define FIQ2_CLR_EN_2     ARMC_BASE_ADDRESS + 0x3a8     // Write to Clear ARM Core 2 FIQ enable bits [79:64]
#define FIQ3_PENDING0     ARMC_BASE_ADDRESS + 0x3c0     // ARM Core 3 FIQ Enabled Interrupt pending bits [31:0]
#define FIQ3_PENDING1     ARMC_BASE_ADDRESS + 0x3c4     // ARM Core 3 FIQ Enabled Interrupt pending bits [63:32]
#define FIQ3_PENDING2     ARMC_BASE_ADDRESS + 0x3c8     // ARM Core 3 FIQ Enabled Interrupt pending bits [79:64]
#define FIQ3_SET_EN_0     ARMC_BASE_ADDRESS + 0x3d0     // Write to Set ARM Core 3 FIQ enable bits [31:0]
#define FIQ3_SET_EN_1     ARMC_BASE_ADDRESS + 0x3d4     // Write to Set ARM Core 3 FIQ enable bits [63:32]
#define FIQ3_SET_EN_2     ARMC_BASE_ADDRESS + 0x3d8     // Write to Set ARM Core 3 FIQ enable bits[79:64]
#define FIQ3_CLR_EN_0     ARMC_BASE_ADDRESS + 0x3e0     // Write to Clear ARM Core 3 FIQ enable bits [31:0]
#define FIQ3_CLR_EN_1     ARMC_BASE_ADDRESS + 0x3e4     // Write to Clear ARM Core 3 FIQ enable bits [63:32]
#define FIQ3_CLR_EN_2     ARMC_BASE_ADDRESS + 0x3e8     // Write to Clear ARM Core 3 FIQ enable bits [79:64]
#define SWIRQ_SET         ARMC_BASE_ADDRESS + 0x3f0     // Write to Set Software Interrupt sources
#define SWIRQ_CLEAR       ARMC_BASE_ADDRESS + 0x3f4     // Write to Clear Software Interrupt sources


// #define GIC_400_BASE_ADDRESS             (void*) 0xFF840000

// // Distributor Registers
// #define GIC_DISTRIBUTOR_BASE_ADDRESS     GIC_400_BASE_ADDRESS + 0x1000
// #define GICD_CTLR                        GIC_DISTRIBUTOR_BASE_ADDRESS + 0x000 
// #define GICD_TYPER                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0x004
// #define GICD_IIDR                        GIC_DISTRIBUTOR_BASE_ADDRESS + 0x008
// #define GICD_IGROUPRn                    GIC_DISTRIBUTOR_BASE_ADDRESS + 0x080
// #define GICD_ISENABLERn                  GIC_DISTRIBUTOR_BASE_ADDRESS + 0x100
// #define GICD_ICENABLERn                  GIC_DISTRIBUTOR_BASE_ADDRESS + 0x180
// #define GICD_ISPENDRn                    GIC_DISTRIBUTOR_BASE_ADDRESS + 0x200
// #define GICD_ICPENDRn                    GIC_DISTRIBUTOR_BASE_ADDRESS + 0x280
// #define GICD_ISACTIVERn                  GIC_DISTRIBUTOR_BASE_ADDRESS + 0x300
// #define GICD_ICACTIVERn                  GIC_DISTRIBUTOR_BASE_ADDRESS + 0x380
// #define GICD_IPRIORITYRn                 GIC_DISTRIBUTOR_BASE_ADDRESS + 0x400
// #define GICD_ITARGETSRn                  GIC_DISTRIBUTOR_BASE_ADDRESS + 0x800
// #define GICD_ICFGRn                      GIC_DISTRIBUTOR_BASE_ADDRESS + 0xC00
// #define GICD_PPISR                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xD00
// #define GICD_SPISRn                      GIC_DISTRIBUTOR_BASE_ADDRESS + 0xD04
// #define GICD_SGIR                        GIC_DISTRIBUTOR_BASE_ADDRESS + 0xF00
// #define GICD_CPENDSGIRn                  GIC_DISTRIBUTOR_BASE_ADDRESS + 0xF10
// #define GICD_SPENDSGIRn                  GIC_DISTRIBUTOR_BASE_ADDRESS + 0xF20
// #define GICD_PIDR4                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFD0
// #define GICD_PIDR5                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFD4
// #define GICD_PIDR6                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFD8
// #define GICD_PIDR7                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFDC
// #define GICD_PIDR0                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFE0
// #define GICD_PIDR1                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFE4
// #define GICD_PIDR2                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFE8
// #define GICD_PIDR3                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFEC
// #define GICD_CIDR0                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFF0
// #define GICD_CIDR1                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFF4
// #define GICD_CIDR2                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFF8
// #define GICD_CIDR3                       GIC_DISTRIBUTOR_BASE_ADDRESS + 0xFFC

// // CPU Interfaces registers
// #define GIC_CPU_INTERFACE_BASE_ADDRESS   GIC_400_BASE_ADDRESS + 0x2000
// #define GICC_CTLR                        GIC_CPU_INTERFACE_BASE_ADDRESS + 0x0000
// #define GICC_PMR                         GIC_CPU_INTERFACE_BASE_ADDRESS + 0x0004
// #define GICC_BPR                         GIC_CPU_INTERFACE_BASE_ADDRESS + 0x0008
// #define GICC_IAR                         GIC_CPU_INTERFACE_BASE_ADDRESS + 0x000C
// #define GICC_EOIR                        GIC_CPU_INTERFACE_BASE_ADDRESS + 0x0010
// #define GICC_RPR                         GIC_CPU_INTERFACE_BASE_ADDRESS + 0x0014
// #define GICC_HPPIR                       GIC_CPU_INTERFACE_BASE_ADDRESS + 0x0018
// #define GICC_ABPR                        GIC_CPU_INTERFACE_BASE_ADDRESS + 0x001C
// #define GICC_AIAR                        GIC_CPU_INTERFACE_BASE_ADDRESS + 0x0020
// #define GICC_AEOIR                       GIC_CPU_INTERFACE_BASE_ADDRESS + 0x0024
// #define GICC_AHPPIR                      GIC_CPU_INTERFACE_BASE_ADDRESS + 0x0028
// #define GICC_APR0                        GIC_CPU_INTERFACE_BASE_ADDRESS + 0x00D0
// #define GICC_NSAPR0                      GIC_CPU_INTERFACE_BASE_ADDRESS + 0x00E0
// #define GICC_IIDR                        GIC_CPU_INTERFACE_BASE_ADDRESS + 0x00FC
// #define GICC_DIR                         GIC_CPU_INTERFACE_BASE_ADDRESS + 0x1000

#endif
