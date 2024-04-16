# Mini-Autonomous-Catapult
## Overview
The catapult is an ancient and old technology that uses basic principles of physics for its operations. To make the catapult fit the modern age, electronics can be implemented to introduce an autonomous aspect to the otherwise rudimentary design of the catapult. Through the introduction of these new features to the catapult, its operational capabilities are able to be added upon and its potential can be maximised.

This firmware allows the control and execution of different aspects of the robot, such as rotational tuning, catapult armature tuning, and servo control. Alongside this firmware, a software based interface was developed to easily use and control the operation of the robot.

## Hardware and Software Requirements
This robot runs on an Arduino Uno microcontroller. Hence, the firmware was developed on the Arduino IDE. Other microcontrollers that use the Arduino IDE or a C-based programming environment are also compatible.

The software for the targeting interface was developed using the Python Programming Language. Any suitable IDE or terminal can be used to execute the program.

## Installation
The firmware requires a few basic libraries readily available to install through the Arduino IDE.<br><br>
#include <string.h><br>
#include <stdio.h><br>
#include <Servo.h><br>
#include <Arduino.h><br>
