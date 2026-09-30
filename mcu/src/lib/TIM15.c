#include "TIM15.h"

void initTIM15(void) {
    TIM15->PSC = 3999; // constant PSC that gives counter frequency of 20kHz, 1 count = 0.05ms

    TIM15->SMCR &= ~(1 << 16); 
    TIM15->SMCR &= ~(0b111 << 0); // turn off SMS[2:0] and SMS[16] to use UG and CEN as control bits

    TIM15->EGR |= (1 << 0);
    TIM15->CR1 |= (1 << 0); // bit0 of CR1 is CEN, enable to use internal clock
    TIM15->CNT = 0;
}

void configureTIM15(int duration) {
    // find max count
    int maxCount = duration * 20;
    
    // configure ARR
    TIM15->ARR = maxCount;
    
    // configure UG to update registers
    TIM15->EGR |= (1 << 0);

    TIM15->SR &= ~(1 << 0); // clear UIF
    
    TIM15->CNT = 0; // reset counter

    // stay for as long as duration
    while((TIM15->SR & 1) == 0);

    // clear UIF after wait
    TIM15->SR |= ~(1 << 0);
}