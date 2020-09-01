 /*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_SPARKFUN52840MINI_
#define _VARIANT_SPARKFUN52840MINI_

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)

#define USE_LFXO      // Board uses 32khz crystal for LF
// define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT           (64)
#define NUM_DIGITAL_PINS     (64)
#define NUM_ANALOG_INPUTS    (8)    //TODO
#define NUM_ANALOG_OUTPUTS   (0)    //TODO

// LEDs
#define PIN_LED1             (7)
#define LED_BUILTIN          PIN_LED1
#define LED_BLUE             PIN_LED1
#define LED_STATE_ON         1         // State when LED is litted

/*
 * Digital pins
 */
#define PIN_D0                  (27)
#define PIN_D1                  (40)
#define PIN_G0                  (47)
#define PIN_G1                  (46)
#define PIN_G2                  (45)
#define PIN_G3                  (44)
#define PIN_G4                  (43)
#define PIN_G5                  (42)
#define PIN_G6                  (38)
#define PIN_G7                  (35)

static const uint8_t D0 = PIN_D0;
static const uint8_t D1 = PIN_D1;
static const uint8_t G0 = PIN_G0;
static const uint8_t G1 = PIN_G1;
static const uint8_t G2 = PIN_G2;
static const uint8_t G3 = PIN_G3;
static const uint8_t G4 = PIN_G4;
static const uint8_t G5 = PIN_G5;
static const uint8_t G6 = PIN_G6;
static const uint8_t G7 = PIN_G7;

/*
 * Analog pins
 */
#define PIN_A0               (4)
#define PIN_A1               (5)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
#define ADC_RESOLUTION    14        //TODO

/*
 * PWM pins
 */
#define PIN_PWM0            (6)
#define PIN_PWM1            (16)

static const uint8_t PWM0 = PIN_PWM0;
static const uint8_t PWM1 = PIN_PWM1;

// Other pins
#define PIN_AREF           (2)
#define PIN_DFU            (13)
#define PIN_NFC1           (9)
#define PIN_NFC2           (10)

static const uint8_t AREF = PIN_AREF;

/*
 * Serial interfaces
 */
// Serial
//Previous Hardware UART definition for nRF52 Arduino Core, below 0.16.0
//Feel free to comment out these two lines below if there are conflicts with latest release
//06/16/20 - the "Serial" bus is the Serial USB interface. Defining pins for "Serial" does not make any sense.
// #define PIN_SERIAL_RX       (15)
// #define PIN_SERIAL_TX       (17)

//Hardware UART definition for nRF52 Arduino Core, 0.17.0 and above
#define PIN_SERIAL1_RX      (17)
#define PIN_SERIAL1_TX      (15)
#define PIN_SERIAL1_RTS1    (34)    //NOT SURE THIS WILL WORK
#define PIN_SERIAL1_CTS1    (41)    //NOT SURE THIS WILL WORK

//06/16/20 - Added the second serial bus
#define PIN_SERIAL2_RX      (37)
#define PIN_SERIAL2_TX      (39)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (31)
#define PIN_SPI_MOSI         (3)
#define PIN_SPI_SCK          (30)

static const uint8_t SS   = 2 ;
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (8)
#define PIN_WIRE_SCL         (11)

/*
 * QSPI interface for external flash
 */
#define PIN_QSPI_SCK         32
#define PIN_QSPI_CS          33
#define PIN_QSPI_DATA0       34
#define PIN_QSPI_DATA1       35
#define PIN_QSPI_DATA2       36
#define PIN_QSPI_DATA3       37

// On-board QSPI Flash
// If EXTERNAL_FLASH_DEVICES is not defined, all supported devices will be used
#define EXTERNAL_FLASH_DEVICES   GD25Q16C

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
