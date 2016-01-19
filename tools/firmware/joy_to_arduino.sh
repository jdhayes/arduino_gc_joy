#!/bin/bash

# Flash Arduino to Joystick
sudo dfu-programmer atmega16u2 erase
sudo dfu-programmer atmega16u2 flash atmega16u2_org.hex
sudo dfu-programmer atmega16u2 reset

