#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PINO_BUZZER 21
#define PINO_LED_VERDE 11

void tocar_nota(uint pino, uint frequencia, uint duracao_ms) {
    uint slice_num = pwm_gpio_to_slice_num(pino);
    uint32_t clock_freq = 125000000;
    uint32_t divisor = clock_freq / frequencia / 4096 + 1;
    uint32_t top = clock_freq / (divisor * frequencia) - 1;

    pwm_set_clkdiv(slice_num, divisor);
    pwm_set_wrap(slice_num, top);
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(pino), top / 2);
    pwm_set_enabled(slice_num, true);
    
    sleep_ms(duracao_ms);
    pwm_set_enabled(slice_num, false);
    sleep_ms(50);
}

int main() {
    stdio_init_all();
    
    gpio_init(PINO_LED_VERDE);
    gpio_set_dir(PINO_LED_VERDE, GPIO_OUT);


    gpio_set_function(PINO_BUZZER, GPIO_FUNC_PWM);

    while (true) {
        printf("Ambiente GitHub Codespaces Configurado com Sucesso!\n");
        
        gpio_put(PINO_LED_VERDE, 1);
        
        tocar_nota(PINO_BUZZER, 523, 150);
        tocar_nota(PINO_BUZZER, 659, 150); 
        tocar_nota(PINO_BUZZER, 784, 150); 
        tocar_nota(PINO_BUZZER, 1046, 400); 

        gpio_put(PINO_LED_VERDE, 0);
        
        sleep_ms(5000); 
    }
}