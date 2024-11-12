#include <stdint.h>
#include "U545RE.h"

int main_UART();

void Reset_Handler(void) __attribute__((section(".reset_handler")));

typedef volatile uint32_t io_32_t;

#define REG_GPIOC_BASE 0x42020800
#define REG_GPIOA_BASE 0x42020000

#define REG_GPIOA_MODER ( (io_32_t *)(REG_GPIOA_BASE + 0x00) )
#define REG_GPIOC_MODER ( (io_32_t *)(REG_GPIOC_BASE + 0x00) )
#define REG_GPIOA_ODR ( (io_32_t *)(REG_GPIOA_BASE + 0x14) )
#define REG_GPIOC_ODR ( (io_32_t *)(REG_GPIOC_BASE + 0x14) )
#define MODER_SIZE 2

#define REG_RCC_BASE 0x46020C00
#define REG_RCC_AHB2ENR1 ( (io_32_t *)(REG_RCC_BASE + 0x08C) )

static void _set(io_32_t *reg, io_32_t data){
    *reg = data;
}

void set_moder(uint32_t pin, io_32_t mode){
    io_32_t mask = (0b11 << (pin * MODER_SIZE));
    io_32_t clear = *REG_GPIOA_MODER & ~mask;
    io_32_t data = clear | (mode << (pin * MODER_SIZE));

    _set(REG_GPIOA_MODER, data);
}

void delay(uint32_t delay){
    for(uint32_t i = 0; i < delay;i++){
        asm("NOP");
    }
}

int main(void) {
    enable_gpioc_clock();
    set_moder( 5, 1 );

    while(1){
        xor_pin(5);
        delay(0x000F0000);

    }
}

void Reset_Handler(void){
    main_UART();
}

typedef __IO uint32_t _HW32;


static void _SetBit(_HW32 *reg, uint32_t bit){
    _HW32 data = *reg;
    uint32_t mask = (1u << bit);
    data = data | mask;
    *reg = data;
}

int main_UART(){

}

void GPIO_init(){
    _SetBit(&RCC->AHB2ENR1, RCC_AHB2ENR1_GPIOAEN_Pos); 
    
    GPIO_TypeDef gpioa = {0};

    gpioa.MODER = 

}

void UART_init(){
    _SetBit(&RCC->APB2ENR, RCC_APB2ENR_USART1EN_Pos);


}

