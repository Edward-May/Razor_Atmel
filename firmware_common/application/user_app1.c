/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
void UserApp1Initialize(void)
{
 
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{
/**********************************************************************************************************************
File: user_app1.c                                                                

----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------

Description:
This is a user_app1.c file template 

------------------------------------------------------------------------------------------------------------------------
API:

Public functions:


Protected System functions:
void UserApp1Initialize(void)
Runs required initialzation for the task.  Should only be called once in main init section.

void UserApp1RunActiveState(void)
Runs current task state.  Should only be called once in main loop.


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                       /* Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                  /* From main.c */
extern volatile u32 G_u32ApplicationFlags;             /* From main.c */

extern volatile u32 G_u32SystemTime1ms;                /* From board-specific source file */
extern volatile u32 G_u32SystemTime1s;                 /* From board-specific source file */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;            /* The state machine function pointer */
//static u32 UserApp1_u32Timeout;                      /* Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Public functions                                                                                                   */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/* Protected functions                                                                                                */
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
Function: UserApp1Initialize

Description:
Initializes the State Machine and its variables.

Requires:
  -

Promises:
  - 
*/
static u8 u8counter=0;
 static u32 u32timer=500;
void UserApp1Initialize(void)
{
   LCDCommand(LCD_CLEAR_CMD); 
   u8 au8Message[] = "       START!      "; 
   LCDMessage(LINE1_START_ADDR, au8Message); 
  PWMAudioSetFrequency(BUZZER1, 500);
    /* Initialize all unused LEDs to off */  
    
  LedOff(GREEN); 
  LedOff(YELLOW);  
  LedOff(ORANGE);  
  LedOff(RED);
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }

} /* end UserApp1Initialize() */

  
/*----------------------------------------------------------------------------------------------------------------------
Function UserApp1RunActiveState()

Description:
Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.

Requires:
  - State machine function pointer points at current state

Promises:
  - Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Private functions                                                                                                  */
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*-------------------------------------------------------------------------------------------------------------------*/
/* Wait for ??? */
static void UserApp1SM_Idle(void)
{
  
  static  u8 u8aSong[]={1,0,1,1,0,1,1,2,3,2};
  static u8 u8BCount=0;
  static u8 u8State=0;
  u8 au8Message[] = "    COUNT DUCKS   "; 
  
  
  if(u8State==0)
    {
      
      if(WasButtonPressed(BUTTON0)) {
        ButtonAcknowledge(BUTTON0); 
        u8State=1;
        LCDCommand(LCD_CLEAR_CMD); 
 
        LCDMessage(LINE1_START_ADDR, au8Message);
        
         //u8State=0;
      u32timer=500;
      u8counter=0;
      u8BCount=0;
      LedOff(YELLOW);
      LedOff(GREEN);
      LedOff(RED);
      LedOff(ORANGE);
      }else{
      
        return;
      
      }
    }
  if(WasButtonPressed(BUTTON0)) 
  {   
    ButtonAcknowledge(BUTTON0); 
    PWMAudioSetFrequency(BUZZER1, 523); 
    if(u8aSong[u8BCount]==0){
      
       u8BCount++;
    
    }else{
      
      LCDCommand(LCD_CLEAR_CMD); 
 
      LCDMessage(LINE1_START_ADDR, "BUTTON ERROR");
      u8State=0;
      u32timer=500;
      u8counter=0;
      u8BCount=0;
      LedOff(YELLOW);
      LedOff(GREEN);
      LedOff(RED);
      LedOff(ORANGE);
      
      
    }
  }
   if(IsButtonPressed(BUTTON0)) 
   {    
     PWMAudioOn(BUZZER1);  
   }
   if(WasButtonPressed(BUTTON1))  
   { 
     
    ButtonAcknowledge(BUTTON1);  
    PWMAudioSetFrequency(BUZZER1, 659); 
    
    if(u8aSong[u8BCount]==1){
      
       u8BCount++;
    
    }else{
      
      LCDCommand(LCD_CLEAR_CMD); 
 
      LCDMessage(LINE1_START_ADDR, "BUTTON ERROR");
      u8State=0;
      u32timer=500;
      u8counter=0;
      u8BCount=0;
      LedOff(YELLOW);
      LedOff(GREEN);
      LedOff(RED);
      LedOff(ORANGE);
      
      
    }
    //u8BCount++;
    
   }
    if(WasButtonPressed(BUTTON2))  
    {    
      ButtonAcknowledge(BUTTON2);   
      PWMAudioSetFrequency(BUZZER1, 784); 
      if(u8aSong[u8BCount]==2){
      
       u8BCount++;
    
    }else{
      
      LCDCommand(LCD_CLEAR_CMD); 
 
      LCDMessage(LINE1_START_ADDR, "BUTTON ERROR");
      u8State=0;
      u32timer=600;
      u8counter=0;
      u8BCount=0;
      LedOff(YELLOW);
      LedOff(GREEN);
      LedOff(RED);
      LedOff(ORANGE);
      
      
    }
     // u8BCount++;
    } 
 
  if(WasButtonPressed(BUTTON3)) 
  {  
    ButtonAcknowledge(BUTTON3);   
    PWMAudioSetFrequency(BUZZER1, 880); 
    if(u8aSong[u8BCount]==3){
      
       u8BCount++;
    
    }else{
      
      LCDCommand(LCD_CLEAR_CMD); 
 
      LCDMessage(LINE1_START_ADDR, "BUTTON ERROR");
      u8State=0;
      u32timer=400;
      u8counter=0;
      u8BCount=0;
      LedOff(YELLOW);
      LedOff(GREEN);
      LedOff(RED);
      LedOff(ORANGE);
      
      
    }
    //u8BCount++;
  }
  
  if(u8BCount>=10){
     u8BCount=0;
  }
  
   /* Tone is on as long as button is pressed */  
  if( IsButtonPressed(BUTTON0) || IsButtonPressed(BUTTON1) ||       IsButtonPressed(BUTTON2) || IsButtonPressed(BUTTON3) )  
   { 
     PWMAudioOn(BUZZER1); 
   }  
  else  
  {    
    PWMAudioOff(BUZZER1);   
  }
  u32timer--;
  if(u32timer==0)
  {
  u8counter++;
  u32timer=400;
  }
  if(u8counter==0)
    LedOn(YELLOW);
   if(u8counter==1)
   {
     LedOn(GREEN);
      LedOff(YELLOW);
   }
    if(u8counter==2)
    {
      LedOn(YELLOW);
      LedOff(GREEN);
    }
     if(u8counter==3)
     {
    LedOn(YELLOW);
     }
    if(u8counter==4)
     {
    LedOff(YELLOW);
     }
    if(u8counter==5)
     {
    LedOn(YELLOW);
     }
    if(u8counter==6)
    {
      LedOn(GREEN);
      LedOff(YELLOW);
    }
    if(u8counter==7)
    {
      LedOn(YELLOW);
      LedOff(GREEN);
    }
   if(u8counter==8)
     {
    LedOff(YELLOW);
     }
    if(u8counter==9)
     {
    LedOn(YELLOW);
     }
    if(u8counter==10)
    {
      LedOn(ORANGE);
      LedOff(YELLOW);
    }
   if(u8counter==11)
    {
      LedOn(RED);
      LedOff(ORANGE);
      
    }
  if(u8counter==12)
    {
      LedOn(ORANGE);
      LedOff(RED);
    }
}
} /* end UserApp1SM_Idle() */
    

/*-------------------------------------------------------------------------------------------------------------------*/
/* Handle an error */
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */



/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/
