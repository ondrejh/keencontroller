/*
 Keyboard emulator for playing Commander Keen.

 For the Arduino Leonardo and Micro.

 The circuit:
 * set of pushbuttons and microswitch joystick attached from pin to GND.

 Original example code:
 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald

 http://www.arduino.cc/en/Tutorial/KeyboardMessage

 modification to keencontroller (OH):
 started: 20.11.2018 - input settings, keyboard print tested
 first useful version: 3.12.2018 - multikey solved by rotating
 key function unified
 */

#include "Keyboard.h"

// KEY TYPE
#define KT_FST 0x00
#define KT_ROT 0x10
#define KT_QUE 0x20

// KEY MAP
const uint8_t D02_KEYS[2] = {KT_FST + 1, ' '};
const uint8_t D03_KEYS[2] = {KT_FST + 1, KEY_LEFT_CTRL};
const uint8_t D04_KEYS[2] = {KT_FST + 1, KEY_LEFT_ALT};
const uint8_t D05_KEYS[4] = {KT_ROT + 3, 'd', 'y', KEY_RETURN};
const uint8_t D06_KEYS[4] = {KT_ROT + 3, 't', 'n', KEY_F5};
const uint8_t D07_KEYS[2] = {KT_FST + 1, '4'};
const uint8_t D08_KEYS[2] = {KT_FST + 1, '3'};
const uint8_t D09_KEYS[2] = {KT_FST + 1, '2'};
const uint8_t D10_KEYS[2] = {KT_FST + 1, KEY_LEFT_ARROW};
const uint8_t D14_KEYS[2] = {KT_FST + 1, KEY_RIGHT_ARROW};
const uint8_t D15_KEYS[2] = {KT_FST + 1, KEY_UP_ARROW};
const uint8_t D16_KEYS[2] = {KT_FST + 1, KEY_DOWN_ARROW};
const uint8_t A00_KEYS[1] = {0};
const uint8_t A01_KEYS[1] = {0};
const uint8_t A02_KEYS[2] = {KT_FST + 1, KEY_ESC};
const uint8_t A03_KEYS[2] = {KT_FST + 1, '1'};

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

uint8_t rotCnt[16];

#define QUE_PRESS_TIME 200
#define QUE_RELEASE_TIME 100
#define QUELEN 16
uint8_t queue[QUELEN];
uint8_t quein = 0;
uint8_t queout = 0;
uint8_t questatus = 0;
unsigned long quetime = 0;

void que_insert(uint8_t key) {
  uint8_t next = quein + 1;
  next %= QUELEN;
  if (next != queout) {
    queue[quein] = key;
    quein = next;
  }
}

void key_set(bool stat, uint8_t *rot, const uint8_t *key) {
  if (key[0] == 0) // 0 keys to press .. do nothing
    return;
    
  switch (key[0] & 0xF0) { // select key type
    
  case KT_FST: // fast key(s)
    if (stat)
      for (int i = (key[0] & 0x0F); i > 0; i--)
        Keyboard.release(key[i]);
    else
      for (int i = 1; i <= (key[0] & 0x0F); i++)
        Keyboard.press(key[i]);
    break;
    
  case KT_ROT: // rotate (changing) keys
    if (*rot == 0)
      *rot = 1;
    if (stat) {
      Keyboard.release(key[*rot]);
      *rot += 1;
      if (*rot > (key[0] & 0x0F))
        *rot = 1;
    }
    else
      Keyboard.press(key[*rot]);
    break;

  case KT_QUE: // queue
    for (int i=1; i<=key[0]&0x0F; i++) {
      que_insert(key[i]);
    }
    break;

  default: // unknown type, do nothing
    break;
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

  memset(rotCnt, 0, 16);

  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  uint8_t p, px;

  // PORT B
  p = PINB & PORTB_MASK;
  px = pB ^ p;
  if (px & D08) key_set(p & D08, &rotCnt[0], D08_KEYS);
  if (px & D09) key_set(p & D09, &rotCnt[1], D09_KEYS);
  if (px & D10) key_set(p & D10, &rotCnt[2], D10_KEYS);
  if (px & D14) key_set(p & D14, &rotCnt[3], D14_KEYS);
  if (px & D15) key_set(p & D15, &rotCnt[4], D15_KEYS);
  if (px & D16) key_set(p & D16, &rotCnt[5], D16_KEYS);
  pB = p;

  // PORT C
  p = PINC & PORTC_MASK;
  px = pC ^ p;
  //if (px & D05) multikey_set(p & D07, &d05_kp, D05_KEYS);
  if (px & D05) key_set(p & D07, &rotCnt[6], D05_KEYS);
  pC = p;
  
  // PORT D
  p = PIND & PORTD_MASK;
  px = pD ^ p;
  if (px & D02) key_set(p & D02, &rotCnt[7], D02_KEYS);
  if (px & D03) key_set(p & D03, &rotCnt[6], D03_KEYS);
  if (px & D04) key_set(p & D04, &rotCnt[8], D04_KEYS);
  //if (px & D06) multikey_set(p & D06, &d06_kp, D06_KEYS);
  if (px & D06) key_set(p & D06, &rotCnt[9], D06_KEYS);
  pD = p;

  // PORT E
  p = PINE & PORTE_MASK;
  px = pE ^ p;
  if (px & D07) key_set(p & D07, &rotCnt[10], D07_KEYS);
  pE = p;

  // PORT F
  p = PINF & PORTF_MASK;
  px = pF ^ p;
  if (px & A00) key_set(p & A00, &rotCnt[11], A00_KEYS);
  if (px & A01) key_set(p & A01, &rotCnt[12], A01_KEYS);
  if (px & A02) key_set(p & A02, &rotCnt[13], A02_KEYS);
  if (px & A03) key_set(p & A03, &rotCnt[14], A03_KEYS);
  pF = p;

  unsigned long now = millis();
  switch (questatus) {
  case 0:
    if (quein!=queout) {
      Keyboard.press(queue[queout]);
      quetime = now;
      questatus++;
    }
    break;
  case 1:
    if ((now - quetime) >= QUE_PRESS_TIME) {
      Keyboard.release(queue[queout]);
      int next = (queout + 1) % QUELEN;
      queout = next;
      quetime = now;
      questatus++;
    }
    break;
  case 2:
    if ((now - quetime) >= QUE_RELEASE_TIME) {
      questatus=0;
    }
    break;
  default:
    questatus = 0;
    break;
  }
}

