/*==========================================*
* main.c
*
* Created on: 06/28/2014
* Author: Gaetano Scognamiglio

* Copyright© 2016 Gaetano Scognamiglio

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*===========================================*/


#include "ch.h"
#include "hal.h"

#define FING1 8         //Thumb
#define FING2 9         //Forefinger
#define FING3 6         //Middle finger
#define FING4 7         //Ring finger
#define FING5 4         //Little finger



static PWMConfig pwmcfg = {
  1000000,                 /* 1MHz PWM clock frequency */
  20000,                   /* PWM period 20 milli  second */
  NULL,                    /* No callback */
 {                         // All channels enabled
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
    {PWM_OUTPUT_ACTIVE_HIGH, NULL},
  },
  0
};


//THREAD 1
static WORKING_AREA(waThread1, 128);

static msg_t Thread1(void *arg) {
  (void)arg;
  chRegSetThreadName("Finger1");
  enum {UP, DOWN};
    static int dir = UP, step = 700, width = 700;   //starts at 0.7ms, ends at 1.4ms
    palSetPadMode(GPIOB, FING1, PAL_MODE_ALTERNATE(2));     //pin PB8 controlling servo FING1
    palSetPadMode(GPIOD,1,PAL_MODE_INPUT);                  //pin PD1 button
    palSetPadMode(GPIOC, 15, PAL_MODE_OUTPUT_PUSHPULL);     //pin PC15 controlling Status LED (Red)
    pwmStart(&PWMD4, &pwmcfg);

    int b1;                     //a variable to detect button's state

    while (TRUE) {
      pwmEnableChannel(&PWMD4, 2, width);               //Enables PWMD4 Channel 3
      b1=palReadPad(GPIOD,1);

      if(width == 700) dir = UP;
      else if (b1== FALSE) dir = DOWN;
      if (dir == UP && b1) {                //if the button is pressed, Status LED turn on and the finger up
        width += step;
        palWritePad(GPIOC, 15, PAL_HIGH);
      }
      else if (dir == DOWN && b1==FALSE) {  //if the button is relased, Status Led turn off and the finger down
        width -= step;
        palWritePad(GPIOC, 15, PAL_LOW);
      }

      chThdSleepMilliseconds(100);
    }

    return 0;
}

//THREAD 2
static WORKING_AREA(waThread2,128);

static msg_t Thread2(void *arg) {
  (void)arg;
  chRegSetThreadName("Finger2");
  enum {UP, DOWN};
      static int dir = UP, step = 300, width = 1800;
      palSetPadMode(GPIOB, FING2, PAL_MODE_ALTERNATE(2));  //PB9 controlling servo FING2
      palSetPadMode(GPIOD,2,PAL_MODE_INPUT);                //PD2 button

      palSetPadMode(GPIOC, 15, PAL_MODE_OUTPUT_PUSHPULL);
      pwmStart(&PWMD4, &pwmcfg);

      int b2;

      while (TRUE) {

        pwmEnableChannel(&PWMD4, 3, width);             //Enables PWMD4 Channel 4
        b2=palReadPad(GPIOD,2);

        if(width == 1800) dir = UP ;
        else if (b2== FALSE) dir = DOWN;
        if (dir == UP && b2) {
          width -= step;
          palWritePad(GPIOC, 15, PAL_HIGH);
        }
        else if (dir == DOWN && b2==FALSE) {
          width += step;
          palWritePad(GPIOC, 15, PAL_LOW);
        }

        chThdSleepMilliseconds(60);
      }

      return 0;
}

//THREAD 3
static WORKING_AREA(waThread3,128);

static msg_t Thread3(void *arg) {
  (void)arg;
  chRegSetThreadName("Finger3");
  enum {UP, DOWN};
      static int dir = UP, step = 700, width = 700;
      palSetPadMode(GPIOB, FING3, PAL_MODE_ALTERNATE(2));           //PB6 controlling servo FING3
      palSetPadMode(GPIOD,3,PAL_MODE_INPUT);                        //PD3 button

      palSetPadMode(GPIOC, 15, PAL_MODE_OUTPUT_PUSHPULL);
      pwmStart(&PWMD4, &pwmcfg);

      int b3;

      while (TRUE) {

        pwmEnableChannel(&PWMD4, 0, width);                     //Enables PWMD4 Channel 1
        b3=palReadPad(GPIOD,3);

        if(width == 700) dir = UP;
        else if (b3== FALSE) dir = DOWN;
        if (dir == UP && b3) {
          width += step;
          palWritePad(GPIOC, 15, PAL_HIGH);
        }
        else if (dir == DOWN && b3==FALSE) {
          width -= step;
          palWritePad(GPIOC, 15, PAL_LOW);
        }

        chThdSleepMilliseconds(100);
      }

      return 0;
}

//THREAD 4
static WORKING_AREA(waThread4,128);

static msg_t Thread4(void *arg) {
  (void)arg;
  chRegSetThreadName("Finger4");
  enum {UP, DOWN};
      static int dir = UP, step = 300, width = 1700;
      palSetPadMode(GPIOB, FING4, PAL_MODE_ALTERNATE(2));               //PB7 controlling servo FING4
      palSetPadMode(GPIOD,4,PAL_MODE_INPUT);                            //PD4 button

      palSetPadMode(GPIOC, 15, PAL_MODE_OUTPUT_PUSHPULL);
      pwmStart(&PWMD4, &pwmcfg);

      int b4;

      while (TRUE) {

        pwmEnableChannel(&PWMD4, 1, width);         //Enables PWMD4 Channel 2
        b4=palReadPad(GPIOD,4);

        if(width == 1700) dir = UP;
        else if (b4== FALSE) dir = DOWN;
        if (dir == UP && b4) {
          width -= step;
          palWritePad(GPIOC, 15, PAL_HIGH);
        }
        else if (dir == DOWN && b4==FALSE) {
          width += step;
          palWritePad(GPIOC, 15, PAL_LOW);
        }

        chThdSleepMilliseconds(60);
      }

      return 0;
}

//THREAD 5
static WORKING_AREA(waThread5,128);

static msg_t Thread5(void *arg) {
  (void)arg;
  chRegSetThreadName("Finger5");
  enum {UP, DOWN};
      static int dir = UP, step = 300, width = 2000;
      palSetPadMode(GPIOB, FING5, PAL_MODE_ALTERNATE(2));           //PB4 controlling servo FING5
      palSetPadMode(GPIOD,5,PAL_MODE_INPUT);                        //PD5  button

      palSetPadMode(GPIOC, 15, PAL_MODE_OUTPUT_PUSHPULL);
      pwmStart(&PWMD3, &pwmcfg);

      int b5;

      while (TRUE) {

        pwmEnableChannel(&PWMD3, 0, width);                     //Enables PWMD3 Channel 1
        b5=palReadPad(GPIOD,5);

        if(width == 2000) dir = UP;
        else if (b5== FALSE) dir = DOWN;
        if (dir == UP && b5) {
          width -= step;
          palWritePad(GPIOC, 15, PAL_HIGH);
        }
        else if (dir == DOWN && b5==FALSE) {
          width += step;
          palWritePad(GPIOC, 15, PAL_LOW);
        }

        chThdSleepMilliseconds(60);
      }

      return 0;
}



int main(void) {

  halInit();
  chSysInit();
  palSetPadMode(GPIOC, 13, PAL_MODE_OUTPUT_PUSHPULL);               //PC13 controlling Power Led (Green)
  palWritePad(GPIOC, 13, PAL_HIGH);                                 //Turn on Power LED at start

  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1,NULL);
  chThdCreateStatic(waThread2, sizeof(waThread2), NORMALPRIO, Thread2,NULL);
  chThdCreateStatic(waThread3, sizeof(waThread3), NORMALPRIO, Thread3,NULL);
  chThdCreateStatic(waThread4, sizeof(waThread4), NORMALPRIO, Thread4,NULL);
  chThdCreateStatic(waThread5, sizeof(waThread5), NORMALPRIO, Thread5,NULL);

  return 0;
}
