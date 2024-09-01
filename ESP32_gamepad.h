/*
MIT License

Copyright (c) 2023 esp32beans@gmail.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef ESP32_GAMEPAD_H_
#define ESP32_GAMEPAD_H_

#include <Arduino.h>
#include "USBHID.h"
#if CONFIG_TINYUSB_HID_ENABLED

// Dpad directions
typedef uint8_t Direction_t;
#define GAMEPAD_DPAD_UP  0
#define GAMEPAD_DPAD_UP_RIGHT 1
#define GAMEPAD_DPAD_RIGHT 2
#define GAMEPAD_DPAD_DOWN_RIGHT 3
#define GAMEPAD_DPAD_DOWN 4
#define GAMEPAD_DPAD_DOWN_LEFT 5
#define GAMEPAD_DPAD_LEFT 6
#define GAMEPAD_DPAD_UP_LEFT 7
#define GAMEPAD_DPAD_CENTERED 0xF

enum BUTTONs {
  BUTTON_0 = 0,
  BUTTON_1,
  BUTTON_2,
  BUTTON_3,
  BUTTON_4,
  BUTTON_5,
  BUTTON_6,
  BUTTON_7,
  BUTTON_8,
  BUTTON_9,
  BUTTON_10,
  BUTTON_11,
};

// Gamepad HID report layout
// Joystick with 4 8-bit axes, 1 hat/dpad, 12 buttons
typedef struct __attribute__((packed)) {
  uint8_t x;
  uint8_t y;
  uint8_t z;
  uint8_t rz;
  uint16_t hat:4;
  uint16_t buttons:12;
} Gamepad_Report_t;

class ESP32_gamepad: public USBHIDDevice {
  public:
    ESP32_gamepad(void);
    void begin(void);
    void end(void);
    void loop(void);
    bool write(void);
    bool write(void *report);
    bool write(void *report, size_t len);
    void press(uint8_t button);
    void release(uint8_t button);
    inline void releaseAll(void) { _report.buttons = 0;  }
    inline void buttons(uint16_t b) { _report.buttons = b; }
    inline void xAxis(uint8_t a) { _report.x = a; }
    inline void yAxis(uint8_t a) { _report.y = a; }
    inline void xAxisRight(uint8_t a) { _report.z = a; }
    inline void yAxisRight(uint8_t a) { _report.rz = a; }
    inline void dPad(Direction_t d) { _report.hat = d; }
    void dPad(bool up, bool down, bool left, bool right);

    // internal use
    uint16_t _onGetDescriptor(uint8_t* buffer);
  private:
    USBHID hid;
    Gamepad_Report_t _report;
    uint32_t startMillis;
};

#endif  // CONFIG_TINYUSB_HID_ENABLED
#endif  // ESP32_GAMEPAD_H_
