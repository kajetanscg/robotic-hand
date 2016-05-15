# robotic-hand
*A simple library to control a robotic hand prototype by using an external controller.*


<img src="image.jpg" width="650"/>

<br>The mechanical structure is very simple:
It consists in five 9g micro servo; each of them is connected to the finger through a nylon string.
The hand is controlled using a 5 button controller.
Each button is programmed to control the action of each finger that is moved by using the servo motor.
The servo is setted to a starting position. When the button is pressed it rotates for a certain angle and the finger is up If the button is relased the servo come back to the starting position.
This process has made by each finger through five different threads in order to execute the operations in a single process and avoid a continuos control cycle of the fingers.

On the controller there are two status-LEDs:
- RED LED: Power led
- GREEN LED: User input

**Notes:**
<br>The project runs on *ST STM32F3 Discovery ARMv7 32-bit Cortex-M4* through *ChibiOS/RT*.
<br>The servos are powered by a series of four AA 1,5V battery to obtain 6V while the microcontroller needs 5V.


**Future improvements:**
- Using flex sensors attached to a glove's fingers to control the hand.
- Mechanical improvements.
