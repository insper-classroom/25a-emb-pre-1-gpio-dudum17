#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int btn1 = 28;
int led1 = 5;
int led2 = 8;
int led3 = 11;
int led4 = 15;


int main() {
  stdio_init_all();

  gpio_init(btn1);
  gpio_set_dir(btn1, GPIO_IN);
  gpio_pull_up(btn1);

  gpio_init(led1);
  gpio_set_dir(led1, GPIO_OUT);

  gpio_init(led2);
  gpio_set_dir(led2, GPIO_OUT);

  gpio_init(led3);
  gpio_set_dir(led3, GPIO_OUT);

  gpio_init(led4);
  gpio_set_dir(led4, GPIO_OUT);

  while (true) {
     if (!gpio_get(btn1)){
       gpio_put(led1, 1);
       sleep_ms(300);
       gpio_put(led1, 0);
       gpio_put(led2, 1);
       sleep_ms(300);
       gpio_put(led2, 0);
       gpio_put(led3, 1);
       sleep_ms(300);
       gpio_put(led3, 0);
       gpio_put(led4, 1);
       sleep_ms(300);
       gpio_put(led4, 0);
     }
  }
}
