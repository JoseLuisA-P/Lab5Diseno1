#include "button.h"
#include <stdint.h>
#include <Arduino.h>

// ====================================================================================================
// Private variables
// ====================================================================================================
static long last_debounce_time = 0;
static long debounce_delay = 50;
static bool new_reading;
static bool last_reading = false;
static bool state;


// ====================================================================================================
// Private functions
// ====================================================================================================
static bool button_update(button_t *boton)
{
    new_reading = digitalRead(boton->pin);

    if(new_reading != last_reading)
    {
        last_debounce_time = millis();
    }

    if(millis() - last_debounce_time > debounce_delay){
        state = new_reading;
    }

    last_reading = new_reading;

}
// ====================================================================================================
// Public function definitions
// ====================================================================================================

bool button_get_state(button_t *boton)
{
    button_update(boton);
    return state;
}