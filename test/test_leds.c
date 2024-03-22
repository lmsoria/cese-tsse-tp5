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

/** @file test_leds.c
 ** @brief Batería de Unit Tests para la API de manejo de LEDs.
 **/

/* === Headers files inclusions ================================================================ */

#include <unity.h>

#include "leds.h"

/* === Macros definitions ====================================================================== */
/* === Private data type declarations ========================================================== */
/* === Private variable declarations =========================================================== */

static uint16_t leds_port = 0xFF;

/* === Private function declarations =========================================================== */
/* === Public variable definitions ============================================================= */
/* === Private variable definitions ============================================================ */
/* === Private function implementation ========================================================= */
/* === Public function implementation ========================================================== */

void setUp(void) {
    leds_init(&leds_port);
}

/// @brief Al iniciar el controlador todos los bits de los LEDs deben quedar en cero,
///  sin importar el estado anterior.
void test_initial_state(void) {
    uint16_t leds_port = 0xFF;

    TEST_ASSERT_EQUAL_INT(0x00, leds_init(&leds_port));
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_port);
}

/// @brief Con todos los LEDs apagados prender el LED3, y verificar que el bit 3 está en alto
/// mientras el resto de bits está en bajo.
void test_single_led_on(void) {
    static const int LED = 3;

    TEST_ASSERT_EQUAL_INT(0x00, leds_turn_on_single(LED));
    TEST_ASSERT_BIT_HIGH(LED - 1, leds_port);
    TEST_ASSERT_BITS_LOW(~(1 << (LED - 1)), leds_port);
}

/// @brief Apagar el LED3 (prendido previamente), y verificar que el bit 3 está en bajo
/// mientras el resto de bits no cambia.
void test_single_led_off(void) {
    static const int LED = 3;

    leds_turn_on_single(LED);

    TEST_ASSERT_EQUAL_INT(0x00, leds_turn_off_single(LED));
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_port);
}

/// @brief Prender el LED5 dos veces, prender el LED7 una vez, apagar el LED5 una vez y apagar el
/// LED9 dos veces.
/// Se espera que el único LED prendido al final del test sea el LED7
void test_multiple_leds_on_and_off(void) {
    static const int LED5 = 5;
    static const int LED7 = 7;
    static const int LED9 = 9;
    leds_turn_on_single(LED5);
    leds_turn_on_single(LED7);
    leds_turn_on_single(LED5);
    leds_turn_off_single(LED5);
    leds_turn_off_single(LED9);
    leds_turn_off_single(LED9);

    TEST_ASSERT_EQUAL_UINT16((1 << (LED7 - 1)), leds_port);
}

/// @brief Con todos los LEDs apagados prender el LED3, y verificar que al consultar
/// el estado del mismo se encuentre prendido
void test_single_led_get_status_on(void) {
    static const int LED = 3;

    TEST_ASSERT_EQUAL_INT(0, leds_turn_on_single(LED));
    TEST_ASSERT_EQUAL_INT(1, leds_get_status_single(LED));
}

/// @brief Prender todos los LEDs y verificar que al consultar el estado del puerto sea 0xFF
void test_all_leds_turn_on(void) {

    TEST_ASSERT_EQUAL_INT(0, leds_turn_on_all());
    TEST_ASSERT_EQUAL_UINT16(0xFF, leds_get_status_all());
}

/// @brief Apagar todos los LEDs (prendidos previamente) y verificar que al consultar el estado del
/// puerto sea 0x00
void test_all_leds_turn_off(void) {

    leds_turn_on_all();
    leds_turn_off_all();
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_get_status_all());
}

/// @brief Deinicializar el puerto de los LEDs, y prender todos los LEDs.
/// El programa no debería sufrir una excepción y la función debe retornar -1.
/// Por otro lado, el valor de `leds_port` deberá continuar en cero.
void test_uninitialized_led_port(void) {
    leds_deinit();

    TEST_ASSERT_EQUAL_INT(-1, leds_turn_on_all());
    TEST_ASSERT_EQUAL_UINT16(0x00, leds_port);
}

/// @brief Deinicializar el puerto de los LEDs, y consultar el estado del LED3.
/// El programa no debería sufrir una excepción y la función `leds_get_status_single()` debe
/// retornar -1.
void test_uninitialized_led_port_get_single_value(void) {
    static const int LED = 3;
    leds_deinit();

    TEST_ASSERT_EQUAL_INT(-1, leds_get_status_single(LED));
}

/* === End of documentation ==================================================================== */
