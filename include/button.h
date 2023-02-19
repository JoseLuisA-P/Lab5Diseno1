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
    long last_debounce_time;
    long debounce_delay;
    bool new_reading;
    bool last_reading;
    bool state;

}button_t;


// ====================================================================================================
// Public function definitions
// ====================================================================================================
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