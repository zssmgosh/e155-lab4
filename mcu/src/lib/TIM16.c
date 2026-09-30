#include "TIM16.h"

void initTIM16(void) {
    // set PSC
    TIM16->PSC = 19;

    // configure output mode
    TIM16->CCMR1 &= ~(1 << 16); // clear OCM1[3]
    TIM16->CCMR1 &= ~(0b111 << 4); //clear OCM1[2:0]
    TIM16->CCMR1 |= (0b110 << 4); //output PWM to channel 1 
    TIM16->CCMR1 |= (1 << 3); // preload enable
    TIM16->CCMR1 &= ~(0b11 << 0); // set as output
    
    TIM16->BDTR |= (1 << 15); // main output enable
    TIM16->CCER &= ~(1 << 1); // output polarity as active high 
    TIM16->CCER |= (1 << 0); // output enable
    TIM16->CR1 |= (1 << 7); //set ARPE to use PWM

    TIM16->EGR |= (1 << 0); // set UG to update registers
    TIM16->CR1 |= (1 << 0); // bit0 of CR1 is CEN, enable to use internal clock
    TIM16->CNT &= 0; // start counter at 0
}

void configureTIM16(int pitch) {
    if (pitch == 0) {
        TIM16->ARR &= 0;
    } else {
        int arrVal = (4000000 / pitch) - 1;
        TIM16->ARR = arrVal; // set ARR 
    }

    // configure CCR1
    int ccrVal = ((4000000 / pitch) - 1) / 2; // 50% duty cycle
    TIM16->CCR1 = ccrVal; 
    
    // set UG 
    TIM16->EGR |= (1 << 0); 

    TIM16->CNT = 0;
}