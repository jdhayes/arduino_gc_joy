#!/bin/bash

# Flash Arduino to Joystick
sudo dfu-programmer atmega16u2 erase
sudo dfu-programmer atmega16u2 flash Arduino-big-joystick.hex
sudo dfu-programmer atmega16u2 reset

