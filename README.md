# Car-Park-System-Using-Mbed-RTOS

## Description

This is a simple car park controller project. It is assumed that the car park has a capacity of 100 cars. Entry and exit gate barriers are available at the car park entry and exit points, respectively. The gate output signals are normally at logic HIGH and they go to logic LOW when a gate opens to let a car pass through. The controller counts the number of cars inside the car park and displays messages on the screen to let the drivers know how many spaces are available inside the car park (if any). 

Initially the card park is assumed to be closed (e.g., at night) and message CLOSED is displayed. The car park becomes operational when a button called StartButton is pressed. When the car park is full or when it is closed the entry barrier is locked and does not open to let any cars into the car park.

## Aim
The aim of this project is to show how a car park controller can be designed using a multitasking approach.

## Block Diagram
![image](https://user-images.githubusercontent.com/81603864/223952014-c4357cd3-ae65-4f39-b7c9-92f019ab29fe.png)

## Circuit Diagram
![image](https://user-images.githubusercontent.com/81603864/223952228-874a3a4a-70cf-4462-b9bf-804168a018f6.png)

