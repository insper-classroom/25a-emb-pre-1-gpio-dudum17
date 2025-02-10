#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);
    int cnt_1 = 0;
    int cnt_2 = 0;
    bool last_state_1 = true;
    bool last_state_2 = true;

    while (true) {
        bool state_1 = gpio_get(BTN_PIN);
        bool state_2 = gpio_get(BTN_PIN_2);

        if (state_1 == false && last_state_1 == true){
         sleep_ms(50); 
         if (!gpio_get(BTN_PIN)) {
             printf("Botao 1: %d\n", cnt_1++);
          }
        }

        if (state_2 == false && last_state_2 == true){
        sleep_ms(50); 
        if (!gpio_get(BTN_PIN_2)) {
            printf("Botao 2: %d\n", cnt_2++);
        }
        }
    }
}
