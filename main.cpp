#include "mbed.h"
#include "rtos.h"

Serial pc(USBTX, USBRX);                                      //Serial PC interface

DigitalIn EntrySwitch(PC_0);                                  //Entry switch
DigitalIn ExitSwitch(PC_1);                                   //Exit switch
DigitalOut LockEntryBarrier(PC_2);
DigitalIn StartButton(PC_3);

Thread thread1, thread2;                                      //Create threads
#define CarParkCapacity 100                                   //Car park capacity
int Spaces;

//
//Clear the screen
//
void clrscr()
{
  char clrscr[] = {0x1B, '[', '2', 'J', 0};
}

//
//Home the cursor
//
void homescr()
{
  char homescr[] = {0x1B, '[', 'H', 0};
  pc.printf(homescr);
}

//
//Goto specified line and column
//
void gotoscr(int line, int column)
{
  char scr[] = {0x1B, '[', 0X00, ':', 0X00, 'H', 0};
  scr[2] = line;
  scr[4] = column;
  pc.printf(scr);
}

//
//CarPark thread that works to calculate the available spaces based on the entry and exit barrier switches
//The thread initially waits on an event flag
//
void CarPark()
{
  Thread::signal_wait(0x1);                                   //Wait for flag 1
  while(1)                                                    //Do forever
  {
    if(Spaces == 0)                                           //If no spaces...
      LockEntryBarrier = 1;                                   //Lock the barrier
    else                                                      //Else...
      LockEntryBarrier =0;                                    //Unlock the barrier
    
    if(EntrySwitch ==0)                                       //If a car enters
    {
      Spaces--;                                               //Decrement space count
      if(Spaces < 0)Spaces=0;                                 //If no spaces
      while(EntrySwitch == 0);                                //Wait until barrier down
    }
    
    if(ExitSwitch == 0)                                       //If a car leaves
    {
      Spaces++;                                               //Increment space count
      if(Spaces > CarParkCapacity)Spaces = CarParkCapacity;     
      while(ExitSwitch == 0);
    }
  }
}

//
//This thread display car park status. Initally thread wait fot an event flag
//
void Display()
{
  Thread::signal_wait(0x2);                                   //Wait for flag 2
  homescr();                                                  //Home cursor
  pc.printf("SPACES = ");                                     //Display spaces
  
  while(1)                                                    //Do forever
  {
    gotoscr('0', '9');                                        //Goto 0.9
    pc.print("%d" , Spaces);                                  //Diplay spaces
    Thread::wait(250);                                        //Wait a bit
  }
}

//
//This is the main program. The program locks the barrier to start with and displays the message CLOSED.
//When the StartButton is pressed flags 1 and 2 are set and therefore threads CarPark and display start running
//
int main()
{
  Spaces = CarParkCapacity;                                   //At the beginning
  LockEntryBarrier = 1;                                       //Lock entry barrier (at night)
  clrscr();                                                   //Clear screen
  homescr();                                                  //Home cursor
  pc.printf("CLOSED");                                        //Display CLOSED
  
  thread1.start(CarPark);                                     //Start thread CarPark
  thread2.start(Display);                                     //Start thread Display
  
  while(StartButton == 1);                                    //Wait to start processing
                                                              //StartButton is pressed....
  thread1.signal_set(0x1);                                    //Set flag 1
  thread2.signal_set(0x2);                                    //Set flag 2
  
  while(1);                                                   //Wait here forever
}
    
