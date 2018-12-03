/*
 Keyboard message test

 For the Arduino Leonardo and Micro.

 Sends a text string when a button is pressed.

 The circuit:
 * pushbutton attached from pin 2,3,4 to GND

 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/KeyboardMessage

 modification to keencontroller (OH):
 started: 20.11.2018 - input settings, keyboard print tested
 */

#include "Keyboard.h"

const int buttonPin = 4;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton
int counter = 0;                  // button push counter

// KEY MAP (key = uint8_t array ending 0, 0 not used)
const uint8_t D02_KEYS[2] = {' ', 0};
const uint8_t D03_KEYS[2] = {KEY_LEFT_CTRL, 0};
const uint8_t D04_KEYS[2] = {KEY_LEFT_ALT, 0};
const uint8_t D05_KEYS[4] = {'t', 'y', KEY_RETURN, 0};
const uint8_t D06_KEYS[3] = {'d', 'n', 0};
const uint8_t D07_KEYS[2] = {'4', 0};
const uint8_t D08_KEYS[2] = {'3', 0};
const uint8_t D09_KEYS[2] = {'2', 0};
const uint8_t D10_KEYS[2] = {KEY_LEFT_ARROW, 0};
const uint8_t D14_KEYS[2] = {KEY_RIGHT_ARROW, 0};
const uint8_t D15_KEYS[2] = {KEY_UP_ARROW, 0};
const uint8_t D16_KEYS[2] = {KEY_DOWN_ARROW, 0};
const uint8_t A00_KEYS[1] = {0};
const uint8_t A01_KEYS[1] = {0};
const uint8_t A02_KEYS[2] = {KEY_ESC, 0};
const uint8_t A03_KEYS[2] = {'1', 0};

// PORT MASKS

// PORTB (--- D10 D09 D08 D14 D16 D15 ---)
#define D08 (1<<4)
#define D09 (1<<5)
#define D10 (1<<6)
#define D14 (1<<3)
#define D15 (1<<1)
#define D16 (1<<2)
#define PORTB_MASK (D15 | D16 | D14 | D08 | D09 | D10)

// PORTC (--- D05 --- --- --- --- --- ---)
#define D05 (1<<6)
#define PORTC_MASK (D05)

// PORTD (D06 --- --- D04 --- --- D02 D03)
#define D02 (1<<1)
#define D03 (1<<0)
#define D04 (1<<4)
#define D06 (1<<7)
#define PORTD_MASK (D03 | D02 | D04 | D06)

// PORTE (--- D07 --- --- --- --- --- ---)
#define D07 (1<<6)
#define PORTE_MASK (D07)

// PORTF (A00 A01 A02 A03 --- --- --- ---)
#define A00 (1<<7)
#define A01 (1<<6)
#define A02 (1<<5)
#define A03 (1<<4)
#define PORTF_MASK (A03 | A02 | A01 | A00)

uint8_t pB = PORTB_MASK, pC = PORTC_MASK, pD = PORTD_MASK, pE = PORTE_MASK, pF = PORTF_MASK;

void key_set(bool stat, uint8_t *key) {
  uint8_t *k = key;

  while (*k != 0) {
    if (stat)
      Keyboard.release(*k++);
    else
      Keyboard.press(*k++);
  }
}

void setup() {
  // make the pushButton nibbles an input with pullup:
  DDRB |= PORTB_MASK;
  PORTB |= PORTB_MASK;

  DDRC |= PORTC_MASK;
  PORTC |= PORTC_MASK;

  DDRD |= PORTD_MASK;
  PORTD |= PORTD_MASK;

  DDRE |= PORTE_MASK;
  PORTE |= PORTE_MASK;

  DDRF |= PORTF_MASK;
  PORTF |= PORTF_MASK;

  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  uint8_t p, px;

  // PORT B
  p = PINB & PORTB_MASK;
  px = pB ^ p;
  if (px & D08) key_set(p & D08, D08_KEYS);
  if (px & D09) key_set(p & D09, D09_KEYS);
  if (px & D10) key_set(p & D10, D10_KEYS);
  if (px & D14) key_set(p & D14, D14_KEYS);
  if (px & D15) key_set(p & D15, D15_KEYS);
  if (px & D16) key_set(p & D16, D16_KEYS);
  pB = p;

  // PORT C
  p = PINC & PORTC_MASK;
  px = pC ^ p;
  if (px & D05) key_set(p & D05, D05_KEYS);
  pC = p;
  
  // PORT D
  p = PIND & PORTD_MASK;
  px = pD ^ p;
  if (px & D02) key_set(p & D02, D02_KEYS);
  if (px & D03) key_set(p & D03, D03_KEYS);
  if (px & D04) key_set(p & D04, D04_KEYS);
  if (px & D06) key_set(p & D06, D06_KEYS);
  pD = p;

  // PORT E
  p = PINE & PORTE_MASK;
  px = pE ^ p;
  if (px & D07) key_set(p & D07, D07_KEYS);
  pE = p;

  // PORT F
  p = PINF & PORTF_MASK;
  px = pF ^ p;
  if (px & A00) key_set(p & A00, A00_KEYS);
  if (px & A01) key_set(p & A01, A01_KEYS);
  if (px & A02) key_set(p & A02, A02_KEYS);
  if (px & A03) key_set(p & A03, A03_KEYS);
  pF = p;
}

