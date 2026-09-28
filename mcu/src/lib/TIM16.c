#include "TIM16.h"

void initTIM16(){
    TIM16->CR1 |= (1 << 0); // bit0 of CR1 is CEN, enable to use internal clock
}

int configureTIM16(int pitch, int SR) {
    // find psc val
    int pscVal = 1000000/pitch - 1;

    // configure PSC
    TIM16->PSC &= ~(0b1111111111111111);
    TIM16->PSC |= pscVal;

    // configure ARR
    TIM16->ARR &= ~(0b1111111111111111);
    TIM16->ARR |= 1; // set maxCount to 1 so UIF toggles at counting frequency
    
    // set UG 
    TIM16->EGR |= 1;

    while(~SR & 1); // while UIF == 0, keep outputting frequency
    
    return TIM16->SR;
}