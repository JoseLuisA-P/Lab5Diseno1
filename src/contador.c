#include "button.h"
#include "contador.h"
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