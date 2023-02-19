#include "button.h"
#include "contador.h"
#include "led.h"
#include <Arduino.h>

// ====================================================================================================
// Private variables
// ====================================================================================================

// ====================================================================================================
// Private functions
// ====================================================================================================

static void contador_ajustar_valor(contador_t *contador)
{

    if(contador->last_reading_up & button_is_pressed(&(contador->aumentar)))
    {
        contador->valor++;
        if (contador->valor > 0b00001111) contador->valor = 0;  
        contador->last_reading_up = false; 
    }

    if(!contador->last_reading_up & !button_is_pressed(&(contador->aumentar))) 
    contador->last_reading_up = true;

    if(contador->last_reading_down & button_is_pressed(&(contador->disminuir)))
    {
        contador->valor--;
        if(contador->valor<0) contador->valor = 0b00001111;
        contador->last_reading_down = false; 
    }

    if(!contador->last_reading_down & !button_is_pressed(&(contador->disminuir))) 
        contador->last_reading_down = true;

}

// ====================================================================================================
// Public function definitions
// ====================================================================================================
uint8_t contador_get_value(contador_t *contador)
{
    contador_ajustar_valor(contador);
    return contador->valor;
}


void contador_update_display(contador_t *contador)
{
    contador_ajustar_valor(contador);

    if(((contador->valor&0x08)>>3) == 0b0001) led_turn_on(&contador ->bit3);
    else led_turn_off(&contador->bit3);

    if(((contador->valor&0x04)>>2) == 0b0001) led_turn_on(&contador ->bit2);
    else led_turn_off(&contador->bit2);

    if(((contador->valor&0x02)>>1) == 0b0001) led_turn_on(&contador ->bit1);
    else led_turn_off(&contador->bit1);

    if(((contador->valor&0x01)) == 0b0001) led_turn_on(&contador ->bit0);
    else led_turn_off(&contador->bit0);
}