# Mini-Autonomous-Catapult
## Overview
The catapult is an ancient and old technology that uses basic principles of physics for its operations. To make the catapult fit the modern age, electronics can be implemented to introduce an autonomous aspect to the otherwise rudimentary design of the catapult. Through the introduction of these new features to the catapult, its operational capabilities are able to be added upon and its potential can be maximised.

This firmware allows the control and execution of different aspects of the robot, such as rotational tuning, catapult armature tuning, and servo control. Alongside this firmware, a software based interface was developed to easily use and control the operation of the robot.

## Hardware and Software Requirements
This robot runs on an Arduino Uno microcontroller. Hence, the firmware was developed on the Arduino IDE. Other microcontrollers that use the Arduino IDE or a C-based programming environment are also compatible.

The software for the targeting interface was developed using the Python Programming Language. Any suitable IDE or terminal can be used to execute the program.

## Installation
The firmware requires a few basic libraries readily available to install through the Arduino IDE.
<picture>
 <source media="(prefers-color-scheme: dark)" srcset="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/FSMLibraries.png">
 <source media="(prefers-color-scheme: light)" srcset="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/FSMLibraries.png">
 <img alt="Libraries for Firmware" src="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/FSMLibraries.png">
</picture>

For the targeting software, it is dependent on the Tkinter Library and other utility files.
<picture>
 <source media="(prefers-color-scheme: dark)" srcset="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/SoftwareLibraries.png">
 <source media="(prefers-color-scheme: light)" srcset="(https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/SoftwareLibraries.png)">
 <img alt="Shows a list of libraries to be installed" src="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/SoftwareLibraries.png">
</picture>

## Code Functions and Operations
The firmware implements a Finite State Machine (FSM) that will go through a flow of operations. It begins with setting a serial communication line with the targeting software to obtain the coordinates of the intended target. Then, it will conduct its shooting operation. The figure below shows the intended flow of operation of the robot.

<picture>
 <source media="(prefers-color-scheme: dark)" srcset="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/Coordinate%20Selection%20(1).png">
 <source media="(prefers-color-scheme: light)" srcset="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/Coordinate%20Selection%20(1).png">
 <img alt="Shows the Flow Diagram of the FSM" src="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/Coordinate%20Selection%20(1).png">
</picture>

The x-coordinate will determine the rotation of the robot while the y-coordinate will determine the shot power. The rotation and power can be tuned manually by the user.

The targeting software interface utilises the Tkinter library to create a window with interactable buttons and a grid of coordinates. The size of the grid can be configured in the settings file and the window can be resized using the util file. The targeting interface is shown below

<picture>
 <source media="(prefers-color-scheme: dark)" srcset="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/TargetingWindow.png">
 <source media="(prefers-color-scheme: light)" srcset="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/TargetingWindow.png">
 <img alt="YOUR-ALT-TEXT" src="https://github.com/AmirMasri/Mini-Autonamous-Catapult/blob/main/TargetingWindow.png">
</picture>

The user will select the intended target coordinates and the program will transfer the coordinates to the Arduino microcontroller through serial communications



