#ifndef CONTADOR_H
#define CONTADOR_H

#ifdef __cplusplus
extern "C" {
#endif

// ====================================================================================================
// Dependencies
// ====================================================================================================
#include <Arduino.h>
#include "button.h"
#include "led.h"
// ====================================================================================================
// Type definitions
// ====================================================================================================
typedef struct 
{
    button_t aumentar;
    button_t disminuir;
    led_t bit0;
    led_t bit1;
    led_t bit2;
    led_t bit3;
    bool last_reading_up;
    bool last_reading_down;
    uint8_t valor;
    
}contador_t;


// ====================================================================================================
// Public function definitions
// ====================================================================================================

static void contador_init
(contador_t * contador,button_t boton_aumentar, button_t boton_disminuir,led_t led0,led_t led1,led_t led2,led_t led3)
{
    contador -> aumentar = boton_aumentar;
    contador -> disminuir = boton_disminuir;
    contador -> bit0 = led0;
    contador -> bit1 = led1;
    contador -> bit2 = led2;
    contador -> bit3 = led3;
    contador -> last_reading_up = false;
    contador -> last_reading_down = false;
}

// ====================================================================================================
// Public function prototypes
// ====================================================================================================
uint8_t contador_get_value(contador_t *contador);
void contador_update_display(contador_t *contador);

#ifdef __cplusplus
}
#endif

#endif/*CONTADOR_H*/