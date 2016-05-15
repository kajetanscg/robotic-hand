# robotic-hand
*A simple library to control a robotic hand prototype by using an external controller.*


<img src="image.jpg" width="650"/>

<br>The mechanical structure is very simple:
It consists in five 9g micro servo; each of them is connected to the finger through a nylon string.
The hand is controlled using a 5 button controller.


On the controller there are two led-status:
- RED LED: Power led
- GREEN LED: User inputs

**Notes:**
<br>The project runs on a ST STM32F3 Discovery ARMv7 32-bit Cortex-M4 through ChibiOS/RT porting.
<br>The servos are powered by a series of four AA 1,5V battery to obtain 6V while the microcontroller needs 5V.


**Future improvements:**
- Using flex sensors attached to a glove's fingers to control the hand.
- Mechanical improvements.
