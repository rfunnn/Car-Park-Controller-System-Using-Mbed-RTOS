# Car-Park-Controller-System-Using-Mbed-RTOS

## Description

This is a simple car park controller project. It is assumed that the car park has a capacity of 100 cars. Entry and exit gate barriers are available at the car park entry and exit points, respectively. The gate output signals are normally at logic HIGH and they go to logic LOW when a gate opens to let a car pass through. The controller counts the number of cars inside the car park and displays messages on the screen to let the drivers know how many spaces are available inside the car park (if any). 

Initially the card park is assumed to be closed (e.g., at night) and message CLOSED is displayed. The car park becomes operational when a button called StartButton is pressed. When the car park is full or when it is closed the entry barrier is locked and does not open to let any cars into the car park.

## Aim
The aim of this project is to show how a car park controller can be designed using a multitasking approach.

## Block Diagram
![image](https://user-images.githubusercontent.com/81603864/223952014-c4357cd3-ae65-4f39-b7c9-92f019ab29fe.png)

## Circuit Diagram
![image](https://user-images.githubusercontent.com/81603864/223952228-874a3a4a-70cf-4462-b9bf-804168a018f6.png)

## Explanation
At the beginning of the program, header files mbed.h and rtos.h are included in the program, and the serial PC interface is
defined. EntrySwitch, ExitSwitch, and StartButton are assigned to PC_0, PC_1, and PC_3, respectively. LockEntryBarrier output when set locks the entry barrier so that it does not open and it is assigned to PC_2. The car park capacity is set to 100 cars. Inside the main program message CLOSED is displayed since the car park is closed at the beginning of the program. Threads CarParkandDisplay are started. These threads wait for event flags 1 and 2 to be set, respectively, before they can continue. These flags are set when the StartButton is pressed (i.e., StartButton is at logic LOW). Setting the flags starts the two threads. Thread Display displays the spaces available in the car park at screen coordinate (0, 9). Thread CarPark increases or decreases the space count depending on whether the cars are entering or leaving the car park. When a car enters the car park variable Spaces is decremented by one. Similarly, when a car leaves the car park variable Spaces is incremented by one. The program makes sure that the space count is not above the car park capacity or below zero 
