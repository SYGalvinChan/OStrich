#include "printf.h"

void handle_sync_el1t() {
    printf("Synchronous Exception in EL1t\r\n");
}

void handle_irq_el1t() {
    printf("IRQ in EL1t\r\n");
}

void handle_fiq_el1t() {
    printf("FIQ in EL1t\r\n");
}

void handle_error_el1t() {
    printf("SError in EL1t\r\n");
}	

void handle_sync_el1h() {
    printf("Synchronous Exception in EL1h\r\n");
}

void handle_irq_el1h() {
    printf("IRQ in EL1h\r\n");
}

void handle_fiq_el1h() {
    printf("FIQ in EL1h\r\n");
}

void handle_error_el1h() {
    printf("SError in EL1h\r\n");
}	

void handle_sync_el0_64() {
    printf("Synchronous Exception in EL0_64\r\n");
}

void handle_irq_el0_64() {
    printf("IRQ in EL0_64\r\n");
}

void handle_fiq_el0_64() {
    printf("FIQ in EL0_64\r\n");
}

void handle_error_el0_64() {
    printf("SError in EL0_64\r\n");
}

void handle_sync_el0_32() {
    printf("Synchronous Exception in EL0_32\r\n");
}

void handle_irq_el0_32() {
    printf("IRQ in EL0_32\r\n");
}

void handle_fiq_el0_32() {
    printf("FIQ in EL0_32\r\n");
}

void handle_error_el0_32() {
    printf("SError in EL0_32\r\n");
}