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

// KEY MAP (0 if not used)
#define D02_KEY ' '
#define D03_KEY KEY_LEFT_CTRL
#define D04_KEY KEY_LEFT_ALT
#define D05_KEY 'd'
#define D06_KEY 't'
#define D07_KEY '4'
#define D08_KEY '3'
#define D09_KEY '2'
#define D10_KEY KEY_LEFT_ARROW
#define D14_KEY KEY_RIGHT_ARROW
#define D15_KEY KEY_UP_ARROW
#define D16_KEY KEY_DOWN_ARROW
#define A00_KEY 0
#define A01_KEY 0
#define A02_KEY KEY_ESC
#define A03_KEY '1'

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

void key_set(bool stat, int key) {
  if (key == 0)
    return;
    
  if (stat)
    Keyboard.release(key);
  else
    Keyboard.press(key);
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
  if (px & D08) key_set(p & D08, D08_KEY);
  if (px & D09) key_set(p & D09, D09_KEY);
  if (px & D10) key_set(p & D10, D10_KEY);
  if (px & D14) key_set(p & D14, D14_KEY);
  if (px & D15) key_set(p & D15, D15_KEY);
  if (px & D16) key_set(p & D16, D16_KEY);
  pB = p;

  // PORT C
  p = PINC & PORTC_MASK;
  px = pC ^ p;
  if (px & D05) key_set(p & D05, D05_KEY);
  pC = p;
  
  // PORT D
  p = PIND & PORTD_MASK;
  px = pD ^ p;
  if (px & D02) key_set(p & D02, D02_KEY);
  if (px & D03) key_set(p & D03, D03_KEY);
  if (px & D04) key_set(p & D04, D04_KEY);
  if (px & D06) key_set(p & D06, D06_KEY);
  pD = p;

  // PORT E
  p = PINE & PORTE_MASK;
  px = pE ^ p;
  if (px & D07) key_set(p & D07, D07_KEY);
  pE = p;

  // PORT F
  p = PINF & PORTF_MASK;
  px = pF ^ p;
  if (px & A00) key_set(p & A00, A00_KEY);
  if (px & A01) key_set(p & A01, A01_KEY);
  if (px & A02) key_set(p & A02, A02_KEY);
  if (px & A03) key_set(p & A03, A03_KEY);
  pF = p;
}

