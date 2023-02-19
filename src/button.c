#include "button.h"
#include <stdint.h>
#include <Arduino.h>

// ====================================================================================================
// Private variables
// ====================================================================================================

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

bool button_is_pressed(button_t *boton)
{
    return (button_get_state(boton) == true);
}

uint8_t button_return_pin(button_t *boton)
{
    return boton->pin;
}