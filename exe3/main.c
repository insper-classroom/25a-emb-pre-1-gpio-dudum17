#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>


const int LED1 = 4;
const int LED2 = 6;
const int BTN1 = 28;
const int BTN2 = 26;
bool btn1_ligado = false;
bool btn2_ligado = false;


int main() {
  stdio_init_all();


  gpio_init(LED1);
  gpio_set_dir(LED1, GPIO_OUT);

  gpio_init(LED2);
  gpio_set_dir(LED2, GPIO_OUT);


  gpio_init(BTN1);
  gpio_set_dir(BTN1, GPIO_IN);
  gpio_pull_up(BTN1);

  gpio_init(BTN2);
  gpio_set_dir(BTN2, GPIO_IN);
  gpio_pull_up(BTN2);

  while (true) {
    if (!gpio_get(BTN1)) {
      if(btn1_ligado == false){
         gpio_put(LED1, 1);
         btn1_ligado = true;
      } else{
         gpio_put(LED1, 0);
         btn1_ligado = false;
      }
      while (!gpio_get(BTN1)) {
      };
    } 
    if(!gpio_get(BTN2)){
      if(btn2_ligado == false){
         gpio_put(LED2, 1);
         btn2_ligado = true;
      } else{
         gpio_put(LED2, 0);
         btn2_ligado = false;
      }
       while (!gpio_get(BTN2)) {
      };
    }
  }
}
