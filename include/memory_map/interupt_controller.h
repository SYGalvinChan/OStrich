#ifndef MM_INTERUPT_CONTROLLER_H
#define MM_INTERUPT_CONTROLLER_H

#define INTERUPT_CONTROLLER_BASE_ADDRESS            0xFF840000

#define DISTRIBUTOR_BASE_ADDRESS                    INTERUPT_CONTROLLER_BASE_ADDRESS + 0x1000
#define GICD_CTLR                                   DISTRIBUTOR_BASE_ADDRESS + 0x000
#define GICD_TYPER                                  DISTRIBUTOR_BASE_ADDRESS + 0x004
#define GICD_IIDR                                   DISTRIBUTOR_BASE_ADDRESS + 0x008
#define GICD_IGROUPRn                               DISTRIBUTOR_BASE_ADDRESS + 0x080
#define GICD_ISENABLERn                             DISTRIBUTOR_BASE_ADDRESS + 0x100
#define GICD_ICENABLERn                             DISTRIBUTOR_BASE_ADDRESS + 0x180
#define GICD_ISPENDRn                               DISTRIBUTOR_BASE_ADDRESS + 0x200
#define GICD_ICPENDRn                               DISTRIBUTOR_BASE_ADDRESS + 0x280
#define GICD_ISACTIVERn                             DISTRIBUTOR_BASE_ADDRESS + 0x300
#define GICD_ICACTIVERn                             DISTRIBUTOR_BASE_ADDRESS + 0x380
#define GICD_IPRIORITYRn                            DISTRIBUTOR_BASE_ADDRESS + 0x400
#define GICD_ITARGETSRn                             DISTRIBUTOR_BASE_ADDRESS + 0x800
#define GICD_ICFGRn                                 DISTRIBUTOR_BASE_ADDRESS + 0xC00
#define GICD_PPISR                                  DISTRIBUTOR_BASE_ADDRESS + 0xD00
#define GICD_SPISRn                                 DISTRIBUTOR_BASE_ADDRESS + 0xD04
#define GICD_SGIR                                   DISTRIBUTOR_BASE_ADDRESS + 0xF00
#define GICD_CPENDSGIRn                             DISTRIBUTOR_BASE_ADDRESS + 0xF10
#define GICD_SPENDSGIRn                             DISTRIBUTOR_BASE_ADDRESS + 0xF20
#define GICD_PIDR4                                  DISTRIBUTOR_BASE_ADDRESS + 0xFD0
#define GICD_PIDR5                                  DISTRIBUTOR_BASE_ADDRESS + 0xFD4
#define GICD_PIDR6                                  DISTRIBUTOR_BASE_ADDRESS + 0xFD8
#define GICD_PIDR7                                  DISTRIBUTOR_BASE_ADDRESS + 0xFDC
#define GICD_PIDR0                                  DISTRIBUTOR_BASE_ADDRESS + 0xFE0
#define GICD_PIDR1                                  DISTRIBUTOR_BASE_ADDRESS + 0xFE4
#define GICD_PIDR2                                  DISTRIBUTOR_BASE_ADDRESS + 0xFE8
#define GICD_PIDR3                                  DISTRIBUTOR_BASE_ADDRESS + 0xFEC
#define GICD_CIDR0                                  DISTRIBUTOR_BASE_ADDRESS + 0xFF0
#define GICD_CIDR1                                  DISTRIBUTOR_BASE_ADDRESS + 0xFF4
#define GICD_CIDR2                                  DISTRIBUTOR_BASE_ADDRESS + 0xFF8
#define GICD_CIDR3                                  DISTRIBUTOR_BASE_ADDRESS + 0xFFC

#define CPU_INTERFACES_BASE_ADDRESS                 INTERUPT_CONTROLLER_BASE_ADDRESS + 0x2000
#define GICC_CTLR                                   CPU_INTERFACES_BASE_ADDRESS + 0x0000
#define GICC_PMR                                    CPU_INTERFACES_BASE_ADDRESS + 0x0004
#define GICC_BPR                                    CPU_INTERFACES_BASE_ADDRESS + 0x0008
#define GICC_IAR                                    CPU_INTERFACES_BASE_ADDRESS + 0x000C
#define GICC_EOIR                                   CPU_INTERFACES_BASE_ADDRESS + 0x0010
#define GICC_RPR                                    CPU_INTERFACES_BASE_ADDRESS + 0x0014
#define GICC_HPPIR                                  CPU_INTERFACES_BASE_ADDRESS + 0x0018
#define GICC_ABPR                                   CPU_INTERFACES_BASE_ADDRESS + 0x001C
#define GICC_AIAR                                   CPU_INTERFACES_BASE_ADDRESS + 0x0020
#define GICC_AEOIR                                  CPU_INTERFACES_BASE_ADDRESS + 0x0024
#define GICC_AHPPIR                                 CPU_INTERFACES_BASE_ADDRESS + 0x0028
#define GICC_APR0                                   CPU_INTERFACES_BASE_ADDRESS + 0x00D0
#define GICC_NSAPR0                                 CPU_INTERFACES_BASE_ADDRESS + 0x00E0
#define GICC_IIDR                                   CPU_INTERFACES_BASE_ADDRESS + 0x00FC
#define GICC_DIR                                    CPU_INTERFACES_BASE_ADDRESS + 0x1000

#endif
