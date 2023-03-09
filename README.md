# Car-Park-System-Using-Mbed-RTOS

## Description

This is a simple car park controller project. It is assumed that the car park has a capacity of 100 cars. Entry and exit gate barriers are available at the car park entry and exit points, respectively. The gate output signals are normally at logic HIGH and they go to logic LOW when a gate opens to let a car pass through. The controller counts the number of cars inside the car park and displays messages on the screen to let the drivers know how many spaces are available inside the car park (if any). 

Initially the card park is assumed to be closed (e.g., at night) and message CLOSED is displayed. The car park becomes operational when a button called StartButton is pressed. When the car park is full or when it is closed the entry barrier is locked and does not open to let any cars into the car park.

## Aim
The aim of this project is to show how a car park controller can be designed using a multitasking approach.

## Block Diagram
![image](https://user-images.githubusercontent.com/81603864/223952014-c4357cd3-ae65-4f39-b7c9-92f019ab29fe.png)

The block diagram of the project is shown Fig. 15.13. It is assumed that barriers with
switches are used at the entry and exit points of the car park. Normally the outputs of these
switches are held at logic HIGH and they become LOW when the barriers are lifted.
15.7.4 Circuit Diagram
The circuit diagram of the project is shown in Fig. 15.14. Entry and exit switches are named
as EntrySwitch and ExitSwitch, respectively and they are connected to GPIO pins PC_0 and
PC_1 as shown in the figure. In this project two push-button switches are used to simulate the
car park barriers. A PC is used to display the car park informatio
