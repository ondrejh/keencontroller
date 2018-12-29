#ifndef __CONFIG_H__
#define __CONFIG_H__

#define KEEN
//#define DAVE
//#define PRINCE2

// Filter
#define FILTER_TIME_MS 1
#define FILTER_LENGTH 3

// KEY TYPE
#define KT_FST 0x00
#define KT_ROT 0x10
#define KT_QUE 0x20

// keymap Commander Keen
#ifdef KEEN
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
#endif

// keymap Dangerous Dave
#ifdef DAVE
const uint8_t D02_KEYS[2] = {KT_FST + 1, KEY_LEFT_ALT};
const uint8_t D03_KEYS[2] = {KT_FST + 1, ' ' };
const uint8_t D04_KEYS[2] = {KT_FST + 1, KEY_TAB};
const uint8_t D05_KEYS[2] = {KT_FST + 1, 'y'};
const uint8_t D06_KEYS[2] = {KT_FST + 1, 'n'};
const uint8_t D07_KEYS[1] = {0};
const uint8_t D08_KEYS[1] = {0};
const uint8_t D09_KEYS[1] = {0};
const uint8_t D10_KEYS[2] = {KT_FST + 1, KEY_LEFT_ARROW};
const uint8_t D14_KEYS[2] = {KT_FST + 1, KEY_RIGHT_ARROW};
const uint8_t D15_KEYS[2] = {KT_FST + 1, KEY_UP_ARROW};
const uint8_t D16_KEYS[2] = {KT_FST + 1, KEY_DOWN_ARROW};
const uint8_t A00_KEYS[1] = {0};
const uint8_t A01_KEYS[1] = {0};
const uint8_t A02_KEYS[2] = {KT_FST + 1, KEY_ESC};
const uint8_t A03_KEYS[1] = {0};
#endif

// keymap Prince 2
#ifdef PRINCE2
const uint8_t D02_KEYS[2] = {KT_FST + 1, KEY_UP_ARROW};
const uint8_t D03_KEYS[2] = {KT_FST + 1, KEY_LEFT_CTRL};
const uint8_t D04_KEYS[2] = {KT_FST + 1, KEY_LEFT_SHIFT};
const uint8_t D05_KEYS[2] = {KT_FST + 1, KEY_RETURN};
const uint8_t D06_KEYS[2] = {KT_FST + 1, KEY_ESC};
const uint8_t D07_KEYS[3] = {KT_FST + 2, KEY_LEFT_ALT, 'O'};
const uint8_t D08_KEYS[3] = {KT_FST + 2, KEY_LEFT_CTRL, 'A'};
const uint8_t D09_KEYS[3] = {KT_FST + 2, KEY_LEFT_CTRL, 'S'};
const uint8_t D10_KEYS[2] = {KT_FST + 1, KEY_LEFT_ARROW};
const uint8_t D14_KEYS[2] = {KT_FST + 1, KEY_RIGHT_ARROW};
const uint8_t D15_KEYS[2] = {KT_FST + 1, KEY_UP_ARROW};
const uint8_t D16_KEYS[2] = {KT_FST + 1, KEY_DOWN_ARROW};
const uint8_t A00_KEYS[1] = {0};
const uint8_t A01_KEYS[1] = {0};
const uint8_t A02_KEYS[3] = {KT_FST + 2, KEY_LEFT_CTRL, 'Q'};
const uint8_t A03_KEYS[3] = {KT_FST + 2, KEY_LEFT_CTRL, 'S'};
#endif

#endif __CONFIG_H__
