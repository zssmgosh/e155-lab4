// STM32L432KC_RCC.c
// Source code for RCC functions

#include "STM32L432KC_RCC.h"

void configurePLL() {
    // Set clock to 80 MHz
    // Output freq = (src_clk) * (N/M) / R
    // (4 MHz) * (N/M) / R = 80 MHz
    // M: XX, N: XX, R: XX
    // Use MSI as PLLSRC

    // Turn off PLL
    RCC->CR &= ~(1 << 24);
    // Wait till PLL is unlocked (e.g., off)
    while((RCC->CR >> 25) & 1); //unlock when bit 25 is 0

    // Load configuration
    // Set PLL SRC to MSI
    RCC->PLLCFGR &= ~(1 << 1); 
    RCC->PLLCFGR |= (1 << 0);

    // Set PLLN
    RCC->PLLCFGR &= ~(0b1111111 << 8);
    // RCC->PLLCFGR |= 0b1010000 << 8; // 80MHz
    RCC->PLLCFGR |= 0b0000001 << 8; // 1MHz

    // Set PLLM
    RCC->PLLCFGR &= ~(0b111 << 4);
    RCC->PLLCFGR |= 0b001 <<4;

    // Set PLLR
    RCC->PLLCFGR &= ~(0b11 << 25);
    RCC->PLLCFGR |= 0b01 << 25;
    
    // Enable PLLR output
    RCC->PLLCFGR |= 1 << 24;

    // Enable PLL
    RCC->CR |= 1 << 24;
    
    // Wait until PLL is locked
    while((RCC->CR >> 25) | ~1); // lock when bit 25 is 1
}

void configureClock(){
    // Configure and turn on PLL
    configurePLL();

    // Select PLL as clock source
    RCC->CFGR |= (0b11 << 0);
    while(!((RCC->CFGR >> 2) & 0b11));
}