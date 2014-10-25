281_Lab4
========
#Objectives
The objectives of this lab included making an etch a sketch program, a program that would have a moving block to bounce off of wals, and another program which implemented the bouncing block into a pong game. For bonus functionality, the block was turned into a ball (not a diamond!). This was all done by interlinking c programming with an asm file. The c file would call subroutines from the asm file. 

#Prelab
For the Prelab, we ended up just filling out a bunch of tables and answered some questions. They can be seen below

![alt text](http://i57.tinypic.com/3451r10.png)
![alt text](http://i58.tinypic.com/ok0rq9.png)
![alt text](http://i59.tinypic.com/206d9c5.png)

###What is the role of the extern directive in a .c file?
It means declare without defining, which means it explicitly declares a variable. It also allows one to declare an external variable within a function	

###What is the role of the .global directive in an .asm file (used in lines 28-32)?
The global directive means the variable can be defined or referenced in the current file and used/defined in another file.

#Required Functionality

The etch a sketch program for required functionality can be found on the main page for this repository. A block was drawn on the screen and would be moved around with the 4 directional buttons on the display. When the SW3 button was pressed, the block would erase pixels instead of draw them. This was a fairly simple program, where a color variable was added to the draw block function, and in turn the color variable would take place of the 0xFF value used to fill in theblocks. The color variable would change depending on if the SW3 was pressed.

#B Functionality

For B functionality, the color variable and the button detection functions were removed. Then I just set conditions where if the ball coordinates equaled a certain x or y value, xvect or yvect would change, which in turn would change the velocity/direction of the ball. 

#A Functionality
For A functionality, the B functionality was kept, and a drawLine function was added along with the up and down button detection functions. THe up and down button detection would in turn move the line that was drawn and the ball would just keep bouncing around. IF the ball and the line had the same x and y coordinates at any point, the game would end by erasing the screen and drawing a bunch of parallel columns across the screen. Pressing the SW3 button would reset the program and let you play it again.

#Bonus Functionality
The only bonus functionality i did was turn the block into a ball. This was done by getting rid of the loop to draw the block, and just defining how many pixels b=per column would be drawn. There was probably a better way to do it, but this way worked.
