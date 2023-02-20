#ifndef LED_H
#define LED_H

#ifdef __cplusplus
extern "C" {
#endif

// ====================================================================================================
// Dependencies
// ====================================================================================================
#include <Arduino.h>
// ====================================================================================================
// Type definitions
// ====================================================================================================
typedef struct 
{
    uint8_t pin;  /** El pin que se desea prender (LED pin)*/
}led_t;   


// ====================================================================================================
// Public function definitions
// ====================================================================================================
/**
 * @brief Se definen los parametros de los LEDs.
 * 
 * @param[in, out] led  Points to the LED's data structure.
 * @param[in] pinF      Pin a utilizar para activar el LED.        
 */
static void led_init(led_t *led,uint8_t pinF)
{
    led->pin = pinF;
    pinMode(led->pin, OUTPUT);
}


// ====================================================================================================
// Public function prototypes
// ====================================================================================================
void led_turn_on(led_t* led);
void led_turn_off(led_t* led);

#ifdef __cplusplus
}
#endif

#endif/*LED_H*/