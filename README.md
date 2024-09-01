# USB Gamepad for ESP32

See https://registry.platformio.org/libraries/schnoog/Joystick_ESP32S2 for a
more powerful and flexible USB joystick library for ESP32-S2 and ESP32-S3.

This has only been tested on ESP32S3 boards. It should work on ESP32S2 boards.

The gamepad has the following controls.

Control |Description
--------|---------------
X       |8 bits, 0..255, left stick
Y       |8 bits, 0..255, left stick
Z       |8 bits, 0..255, right stick
RZ      |8 bits, 0..255, right stick
Hat     |8 way hat switch/direction pad
Buttons |12 buttons

The HID report has been carefully chosen so it works with the Xbox Adaptive
Controller (XAC). The X,Y axes map to the XAC left joystick. The Z,RZ
axes map to the XAC right joystick. The hat switch maps to the XAC dpad.
The buttons map to XAC buttons.

The XAC firmware must be updated to the June 2024 version or newer for all
features to work. Use the Xbox Accessory app to update the firmware. The app
runs on Xbox console and Windows.

Install this library by downloading a zip file from this repo. Use the IDE
"Add .ZIP library" option.

## Troubleshooting

After uploading firmware, powering cycling and/or reseting the board is
required.
