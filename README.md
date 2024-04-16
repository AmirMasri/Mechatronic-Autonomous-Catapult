# Mini-Autonomous-Catapult

[GitHub Page](https://github.com/AmirMasri/Mini-Autonomous-Catapult)
## Overview
The catapult is an ancient and old technology that uses basic principles of physics for its operations. To make the catapult fit the modern age, electronics can be implemented to introduce an autonomous aspect to the otherwise rudimentary design of the catapult. Through the introduction of these new features to the catapult, its operational capabilities are able to be added upon and its potential can be maximised.

This firmware allows the control and execution of different aspects of the robot, such as rotational tuning, catapult armature tuning, and servo control. Alongside this firmware, a software based interface was developed to easily use and control the operation of the robot.

## Hardware and Software Requirements
This robot runs on an Arduino Uno microcontroller. Hence, the firmware was developed on the Arduino IDE. Other microcontrollers that use the Arduino IDE or a C-based programming environment are also compatible.

The software for the targeting interface was developed using the Python Programming Language. Any suitable IDE or terminal can be used to execute the program.

## Installation
For the targeting software, it is dependent on the Tkinter Library and other utility files.
Before running the targeting software program, ensure Tkinter is installed on the system.<br>
`pip install tk`

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

The user will select the intended target coordinates and the program will transfer the coordinates to the Arduino microcontroller through serial communications after the confirmation button is pressed. 

## Settings
Different configuration files are provided to the user to customize the targeting window. The settings.py file enables the user to resize the window and add additional visual elements to the window

The util.py file is used to configure the coordinate grid which allows the user to increase the x-coordinates and y-coordinate range covered by the project. Note that by adding new coordinates, manual tuning of the movement of the robot needs to be done through the NewFSM.ino file.

## Running the Program

Before running the targeting software program, ensure all of these points have been done:
1. Download the following files:
   - NewFSM.ino
   - TargetCode.py
   - SerialCom.py
   - settings.py
   - util.py
2. Ensure the SerialCom.py is downloaded and placed in the same filepath as the TargetCode.py file as it is required to establish serial communications with the Arduino microcontroller.
3. Ensure the Arduino Uno is connected to the computer through USB.
4. The serial port that is specified in the SerialCom.py file is COM3, change this setting to the serial port being used. This can be easily identified on the Arduino IDE as it displays the COM port the Arduino Microcontroller is connected to.
5. Install all required libraries that are prompted on the respective IDEs used.
6. Run the TargetCode.py program and a window should appear!

If the NewFSM.ino file needs to be updated, ensure the targeting window is closed before uploading the updated code to the Arduino Uno Microcontroller as the serial communication from the TargetCode.py program will interfere with the serial communications.
