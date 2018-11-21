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

#define D02_KEY KEY_LEFT_CTRL
#define D03_KEY KEY_LEFT_ALT
#define D04_KEY KEY_ESC

// D                   15     16     14      8      9     10
#define PORTB_MASK ((1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(1<<6))
#define D08 (1<<4)
#define D09 (1<<5)
#define D10 (1<<6)
#define D14 (1<<3)
#define D15 (1<<1)
#define D16 (1<<2)
// D                    5
#define PORTC_MASK ((1<<6))
#define D05 (1<<6)
// D                    3      2      4      6
#define PORTD_MASK ((1<<0)|(1<<1)|(1<<4)|(1<<7))
#define D02 (1<<1)
#define D03 (1<<0)
#define D04 (1<<4)
#define D06 (1<<7)
// D                    7
#define PORTE_MASK ((1<<6))
// A                    3      2      1      0
#define PORTF_MASK ((1<<4)|(1<<5)|(1<<6)|(1<<7))

uint8_t portd;

void key_set(bool stat, int key) {
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

  portd = PIND&PORTD_MASK;
  
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  uint8_t p = PIND&PORTD_MASK;
  uint8_t px = portd^p;
  if (px & D02) key_set(p & D02, D02_KEY);
  if (px & D03) key_set(p & D03, D03_KEY);
  if (px & D04) key_set(p & D04, D04_KEY);
  portd = p;
}

