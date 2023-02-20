#ifndef BUTTON_H
#define BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

// ====================================================================================================
// Dependencies
// ====================================================================================================
#include <Arduino.h>
#include <stdint.h>
// ====================================================================================================
// Type definitions
// ====================================================================================================
typedef struct 
{
    uint8_t pin;
    long last_debounce_time;    /** Tiempo transcurrido desde el ultimo pulso. */
    long debounce_delay;        /** Tiempo del antirrebote. */
    bool new_reading;           /** Lectura actual. */
    bool last_reading;          /** Ultima lectura realizada. */
    bool state;                 /** Estado actual del boton. */

}button_t;


// ====================================================================================================
// Public function definitions
// ====================================================================================================
/**
 * @brief Se definen los parametros de los PushButtons.
 * 
 * @param[in, out] button                 Points to the Button's data structure.
 * @param[in] pinF                        Pin donde se hace lectura del la señal.
 * @param[in] last_debounce_time          Tiempo que se desea como comparativa.  
 * @param[in] debounce_delay              El tiempo que deseamos para el antirebote.         
 */
static void button_init(button_t *button,uint8_t pinF)
{
    button->pin = pinF;
    pinMode(button->pin, INPUT);
    button->last_debounce_time = 0;
    button->debounce_delay = 50;
    button->last_reading = false;
}


// ====================================================================================================
// Public function prototypes
// ====================================================================================================
bool button_get_state(button_t *boton);
uint8_t button_return_pin(button_t *boton);
bool button_is_pressed(button_t *boton);

#ifdef __cplusplus
}
#endif

#endif/*BUTTON_H*/