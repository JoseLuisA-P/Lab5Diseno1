#include "button.h"
#include "contador.h"
#include "led.h"
#include <Arduino.h>

// ====================================================================================================
// Private variables
// ====================================================================================================
static uint8_t valor = 0;
// ====================================================================================================
// Private functions
// ====================================================================================================

static void contador_ajustar_valor(contador_t *contador)
{
    if(button_get_state(&(contador->aumentar)) == true)
    {
        valor++;
        if (valor > 0b00001111) valor = 0;
    }

    if(button_get_state(&(contador->disminuir)) == true )
    {
        valor--;
        if(valor<=0) valor = 0b00001111;
    }
}

// ====================================================================================================
// Public function definitions
// ====================================================================================================
uint8_t contador_get_value(contador_t *contador)
{
    contador_ajustar_valor(contador);
    return valor;
}

void contador_update_display(contador_t *contador)
{
    contador_ajustar_valor(contador);

    if(((valor&0x08)>>3) == 0b0001) led_turn_on(&contador ->bit3);
    else led_turn_off(&contador->bit3);

    if(((valor&0x04)>>2) == 0b0001) led_turn_on(&contador ->bit2);
    else led_turn_off(&contador->bit2);

    if(((valor&0x02)>>1) == 0b0001) led_turn_on(&contador ->bit1);
    else led_turn_off(&contador->bit1);

    if(((valor&0x01)) == 0b0001) led_turn_on(&contador ->bit0);
    else led_turn_off(&contador->bit0);
}