/************************************************************************************************
Copyright (c) 2024, Leandro Soria <leandromsoria@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#pragma once

/** @file leds.h
 ** @brief Capa de abstracción para controlar LEDs
 **/

/* === Headers files inclusions ================================================================ */

#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
/* === Public data type declarations =========================================================== */
/* === Public variable declarations ============================================================ */
/* === Public function declarations ============================================================ */

/// @brief Inicializa el puerto de LEDs, con todos ellos apagados.
/// @param port puerto a inicializar.
/// @return 0 en caso de éxito.
int leds_init(uint16_t * port);

/// @brief Deinicializa el puerto de LEDs previamente inicializado, dejándolo NULL
void leds_deinit(void);

/// @brief Encender el LED deseado
/// @param led LED a encender.
/// @return 0 en caso de éxito, o -1 si el puerto no se encuentra inicializado.
int leds_turn_on_single(uint16_t led);

/// @brief Apagar el LED deseado
/// @param led LED a apagar.
/// @return 0 en caso de éxito, o -1 si el puerto no se encuentra inicializado.
int leds_turn_off_single(uint16_t led);

/// @brief Consultar el estado del LED deseado
/// @param led LED a consultar.
/// @return 1 si el LED está prendido, 0 si está apagado o -1 si el puerto no está inicializado.
int leds_get_status_single(uint16_t led);

/// @brief Prender todos los LEDs del puerto.
/// @return 0 en caso de éxito, o -1 si el puerto no se encuentra inicializado.
int leds_turn_on_all(void);

/// @brief Apagar todos los LEDs del puerto.
/// @return 0 en caso de éxito, o -1 si el puerto no se encuentra inicializado.
int leds_turn_off_all(void);

/// @brief Consultar el estado de toda la máscara de LEDs del puerto.
/// @return Máscara del puerto, o -1 si el puerto no se encuentra inicializado.
int leds_get_status_all(void);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif
