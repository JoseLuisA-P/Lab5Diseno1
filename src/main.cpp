#include <Arduino.h>
#include "led.h"
#include "button.h"

led_t led1;
led_t led2;
led_t led3;
led_t led4;

button_t boton1;
button_t boton2;
button_t boton3;

void setup()
{
  led_init(&led1,33);
  led_init(&led2,25);
  led_init(&led3,14);
  led_init(&led4,12);

  button_init(&boton1,16);
  button_init(&boton2,17);
  button_init(&boton3,18);
}

void loop()
{
  if(button_get_state(&boton1) == true) led_turn_on(&led1);
  else led_turn_off(&led1);

}