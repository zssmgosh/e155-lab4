

#include "TIM15.h"

void initTIM15() {
    TIM15->CR1 |= (1 << 0); // bit0 of CR1 is CEN, enable to use internal clock

    TIM15->SMCR &= ~(1 << 16); 
    TIM15->SMCR &= ~(0b111 << 0); // turn off SMS[2:0] and SMS[16] to use UG and CEN as control bits
}

int configureTIM15(int duration, int pitch) {
    // find psc val
    int pscVal = 1000000/pitch - 1;

    // configure PSC
    TIM15->PSC &= ~(0b1111111111111111);
    TIM15->PSC |= pscVal;

    // find max count
    int maxCount = duration*pitch/1000;

    // configure ARR
    TIM15->ARR &= ~(0b1111111111111111);
    TIM15->ARR |= maxCount;

    // configure UG to update registers
    TIM15->EGR |= 1;

    // wait for note to finish by reading UIF
    return TIM15->SR;
}