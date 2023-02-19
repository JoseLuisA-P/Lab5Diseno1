#include <Arduino.h>
#include "led.h"
#include "button.h"
#include "contador.h"

led_t led1;
led_t led2;
led_t led3;
led_t led4;

button_t boton1;
button_t boton2;
button_t boton3;

contador_t contador1;
contador_t contador2;

bool flag_cambio = true;
bool flag_contador = false;

void change_contadores();

void setup()
{
  led_init(&led1,33);
  led_init(&led2,25);
  led_init(&led3,14);
  led_init(&led4,12);

  button_init(&boton1,16);
  button_init(&boton2,17);
  button_init(&boton3,18);

  contador_init(&contador1,boton1,boton2,led1,led2,led3,led4);
  contador_init(&contador2,boton1,boton2,led1,led2,led3,led4);

}

void loop()
{
  change_contadores();
  if(flag_contador)contador_update_display(&contador1);
  else contador_update_display(&contador2);

}

void change_contadores()
{

  if(button_get_state(&boton3) & flag_cambio)
  {
    flag_contador = !flag_contador;
    flag_cambio = false;
  }

  if(!button_get_state(&boton3) & !flag_cambio) flag_cambio = true; 

}