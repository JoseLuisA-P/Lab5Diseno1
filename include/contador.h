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
    button_t aumentar;    /** Entrada para aumentar el contador*/
    button_t disminuir;   /** Entrada para disminuir el contador*/
    led_t bit0;           /** Primer bit del contador binario*/
    led_t bit1;           /** Segundo bit del contador binario*/
    led_t bit2;           /** Tercer bit del contador binario*/
    led_t bit3;           /** Cuarto bit del contador binario*/
    bool last_reading_up;
    bool last_reading_down;
    uint8_t valor;        /** El valor actual del contador*/
    
}contador_t;


// ====================================================================================================
// Public function definitions
// ====================================================================================================
/**
 * @brief Se definen los parametros del contador interno.
 * 
 * @param[in, out] contador               Points to the Contador's data structure.
 * @param[in] aumentar                    Hace referencia al boton que aumenta el contador.
 * @param[in] Disminuir                   Hace referencia al boton que disminuye el contador.
 * @param[in] led0                        Hace referencia al primer led del contador.    
 * @param[in] led1                        Hace referencia al segundo led del contador.   
 * @param[in] led2                        Hace referencia al tercero led del contador.   
 * @param[in] led3                        Hace referencia al cuarto led del contador.         
 */
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