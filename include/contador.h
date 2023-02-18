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

// ====================================================================================================
// Type definitions
// ====================================================================================================
typedef struct 
{
    button_t aumentar;
    button_t disminuir;

}contador_t;


// ====================================================================================================
// Public function definitions
// ====================================================================================================

static void contador_init(contador_t * contador,button_t boton_aumentar, button_t boton_disminuir)
{
    contador -> aumentar = boton_aumentar;
    contador -> disminuir = boton_disminuir;
}

// ====================================================================================================
// Public function prototypes
// ====================================================================================================

#ifdef __cplusplus
}
#endif

#endif/*CONTADOR_H*/