#include "button.h"
#include <stdint.h>
#include <Arduino.h>

// ====================================================================================================
// Private variables
// ====================================================================================================
/*
static long last_debounce_time = 0;
static long debounce_delay = 50;
static bool new_reading;
static bool last_reading = false;
static bool state;
*/

// ====================================================================================================
// Private functions
// ====================================================================================================
static bool button_update(button_t *boton)
{
    boton->new_reading = digitalRead(boton->pin);

    if(boton->new_reading != boton->last_reading)
    {
        boton->last_debounce_time = millis();
    }

    if(millis() - boton->last_debounce_time > boton->debounce_delay){
        boton->state = boton->new_reading;
    }

   boton->last_reading = boton->new_reading;

}
// ====================================================================================================
// Public function definitions
// ====================================================================================================

bool button_get_state(button_t *boton)
{   
    button_update(boton);
    return boton->state;
}