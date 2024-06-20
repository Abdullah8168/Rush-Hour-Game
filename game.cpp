//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_6
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


int xI = 70, yI = 670;

void drawCar() {
	
	DrawRoundRect(xI,yI,40,10,colors[RED],-1);
	DrawTriangle( xI, yI , xI+10, yI+20 , xI+10 , yI, colors[RED] );
	DrawTriangle( xI+30, yI , xI+30, yI+20 , xI+40 , yI, colors[RED] );
	DrawRoundRect(xI+10,yI,20,20,colors[RED],-1);
	DrawCircle(xI,yI,7,colors[DARK_RED]);\
	DrawCircle(xI+40,yI,7,colors[DARK_RED]);
	
	glutPostRedisplay();
}
int timme =180;
int x2=60, y2=180; //x2=60  x2=450
void drawCar2() {
	
	DrawRoundRect(x2,y2,40,10,colors[YELLOW],-1);
	DrawTriangle( x2, y2 , x2+10, y2+20 , x2+10 , y2, colors[YELLOW] );
	DrawTriangle( x2+30, y2 , x2+30, y2+20 , x2+40 , y2, colors[YELLOW] );
	DrawRoundRect(x2+10,y2,20,20,colors[YELLOW],-1);
	DrawCircle(x2,y2,7,colors[DARK_SEA_GREEN]);
	DrawCircle(x2+40,y2,7,colors[DARK_SEA_GREEN]);
	
	glutPostRedisplay();
	}
	int x3=480 ,y3=550;
	void drawCar3() {
	
	DrawRoundRect(x3,y3,40,10,colors[GREEN],-1);
	DrawTriangle( x3, y3 , x3+10, y3+20 , x3+10 , y3, colors[GREEN] );
	DrawTriangle( x3+30, y3 , x2+30, y3+20 , x3+40 , y3, colors[GREEN] );
	DrawRoundRect(x3+10,y3,20,20,colors[GREEN],-1);
	DrawCircle(x3,y3,7,colors[GREEN]);
	DrawCircle(x3+40,y3,7,colors[GREEN]);
	
	glutPostRedisplay();
        
	}


bool flag = true;
void moveCar() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}


bool flag2=true;
void moveCar2()
{
	
	if (x2 > 60 && flag2)
	{
		x2 -= 10;
		if(x2<200)
		
			flag2=false;

	}
	
	else if (x2 < 450 && !flag2)// && !f)
	{
		x2 += 10;
		if(x2> 400)
	
			flag2=true;
		
	}
	
}


bool flag3=true;
void moveCar3() {
	
	if (x3 > 10 && flag3) {
		x3 -= 10;
		cout << "going left";
		if(x3 < 100)
			
			flag3 = false;

	}
	else if (x3 < 1010 && !flag3) {
		cout << "go right";
		x3 += 10;
		if (x3 > 900)
			flag3 = true;
	}
}

int xi=680, yi=510;
void man()
{

	DrawCircle(xi , yi+15 , 5, colors[BLACK]);
	DrawLine(xi,yi,xi,yi+10,1,colors[BLACK]);
	DrawLine(xi-5,yi+5,xi+5,yi+5,1,colors[BLACK]);
	DrawLine(xi-5,yi-5,xi,yi,1,colors[BLACK]);
	DrawLine(xi,yi,xi+5,yi-5,1,colors[BLACK]);
	glutPostRedisplay();
	
	}
	
int xj=830,yj=310;	
void man2()
{

	DrawCircle(xj , yj+15 , 5, colors[BLACK]);
	DrawLine(xj,yj,xj,yj+10,1,colors[BLACK]);
	DrawLine(xj-5,yj+5,xj+5,yj+5,1,colors[BLACK]);
	DrawLine(xj-5,yj-5,xj,yj,1,colors[BLACK]);
	DrawLine(xj,yj,xj+5,yj-5,1,colors[BLACK]);
	glutPostRedisplay();
	
	}
	
	int xk=340,yk=310;	
void man3()
{

	DrawCircle(xk , yk+15 , 5, colors[BLACK]);
	DrawLine(xk,yk,xk,yk+10,1,colors[BLACK]);
	DrawLine(xk-5,yk+5,xk+5,yk+5,1,colors[BLACK]);
	DrawLine(xk-5,yk-5,xk,yk,1,colors[BLACK]);
	DrawLine(xk,yk,xk+5,yk-5,1,colors[BLACK]);
	glutPostRedisplay();
	
	}


/*
 * Main Canvas drawing function.
 * */

void GameDisplay(){
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			2/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	DrawString( 200,800,"x= "+to_string(xI), colors[BLACK]);
	DrawString( 400,800,"y= "+to_string(yI), colors[BLACK]);
	//Display Score
	DrawString( 50, 800, "Score=0", colors[BLACK]);
	DrawString( 600, 800, "Time Left="+to_string(timme), colors[BLACK]);
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	
	for(int i=0;i<=840;i+=42)
	{
	DrawLine(0,840-i,1000,840-i,1,colors[BLACK]);
	}
	void DrawRectangle(int sx, int sy, int width, int height, float *color);
	//DrawCircle(50,670,10,colors[RED]);
	//DrawCircle(70,670,10,colors[RED]);
	DrawCircle(400,600,10,colors[BLACK]);
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	
	
	
	
	//////////////
	if(yI<50)
	yI=50;
	if(yI>700)
	yI=700;
	if(xI<60)
	xI=60;
	if(xI>900)
	xI=900;
	DrawRoundRect(150,100,380,50,colors[BLACK],-1);
	DrawRoundRect(300,450,400,50,colors[BLACK],-1);
	DrawRoundRect(700,250,50,250,colors[BLACK],-1);
		
	DrawRoundRect(500,100,50,250,colors[BLACK],-1);
	//(x-axis,y-axis, x-length, y-length)
	
	DrawRoundRect(150,250,250,50,colors[BLACK],-1);
	DrawRoundRect(0,720,1000,50,colors[BLACK],-1);
	DrawRoundRect(600,600,50,130,colors[BLACK],-1);
	DrawRoundRect(720,250,150,50,colors[BLACK],-1);	
	DrawRoundRect(150,250,50,400,colors[BLACK],-1);
	DrawRectangle(950,0,50,720,colors[BLACK]); 
	DrawRoundRect(820,120,50,150,colors[BLACK],-1);	
	DrawRoundRect(0,0,50,750,colors[BLACK],-1);
	DrawRoundRect(0,0,1000,50,colors[BLACK],-1);
	DrawCircle(480,165, 10, colors[GREEN]);
	DrawSquare(475, 150, 10,colors[BROWN]);
	DrawCircle(765,315, 10, colors[GREEN]);
	DrawSquare(760, 300, 10,colors[BROWN]);
	DrawCircle(220,330, 10, colors[GREEN]);
	DrawCircle(225,334, 10, colors[GREEN]);
	DrawCircle(230,330, 10, colors[GREEN]);
	DrawRoundRect(220,300,10,20,colors[BROWN],-1);
	
	
	int z;
   for(z=1;z<1000;z++)
   {
    if(xI>=640 && xI<=680 &&yI<=530 && yI>=510)
       {
         xi=9999;
         yi=9999;
         DrawCircle(880,80,20,colors[GREEN]);
         }
        else if(xI>=790 && xI<=830 &&yI>=310  && yI<=330)
        {
         xj= 9999  ;
         yj= 9999  ;
         DrawCircle(270,670,20,colors[GREEN]);
         }
        else if(xI>=300 && xI>=340 && yI<=330 && yI>=310)
        {
         xk=9999;
         yk=9999;
         DrawCircle(90,80,20,colors[GREEN]);
        }
 }
 int m;
 for(m=1;m<=1000;m++)
   {
    if(xI>=860 && xI<=890 &&yI<=530 && yI>=510)
       {
         
          xi=300;
          yi=530;
      
         }
        else if(xI>=790 && xI<=830 &&yI>=310  && yI<=330)
        {
        
         xj= 340  ;
         yj= 160 ;
         }
        else if(xI>=300 && xI>=340 && yI<=330 && yI>=310)
        {
        
         xk=730;
         yk=650;
        }
 }
	drawCar();
	drawCar2();
	drawCar3();
	man();
	man2();
	man3();
	
	glutSwapBuffers(); // do not modify this line..

}




void menu()
{
glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			2/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	DrawString( 450,650,"RUSH HOUR" , colors[BLACK]);
	DrawString( 350,450,"PRESS V TO START THE GAME" , colors[BLACK]);
	DrawRoundRect(0,0,50,750,colors[BLACK],-1);
	DrawRoundRect(0,0,1000,50,colors[BLACK],-1);
	DrawRoundRect(0,720,1000,50,colors[BLACK],-1);
	DrawRectangle(950,0,50,720,colors[BLACK]);
        glutSwapBuffers(); // do not modify this line..
        glutPostRedisplay();
        }




/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;
		if((xI>=110 && xI<=200 && yI<=650 &&yI>=240) || (xI>=110 && xI<=400 && yI<=300 &&yI>=240) ||(xI>=110 && xI<=550 && yI<=150 &&yI>=90)||(xI>=460 && xI<=550 && yI<=350 &&yI>=90)||(xI>=260 && xI<=750 && yI<=500 &&yI>=440)||(xI>=660 && xI<=750 && yI<=500 &&yI>=240) || (xI>=660 && xI<=870 && yI<=300 &&yI>=240)|| (xI>=780 && xI<=870 && yI<=300 &&yI>=110)|| (xI>=560 && xI<=650 && yI<=720 &&yI>=590) || (xI>=210 && xI<=240 && yI<=340 &&yI>=300) || (xI>=750 && xI<=770 && yI<=320 &&yI>=300) || (xI>=430 && xI<=450 && yI<=170 &&yI>=150))
		
		{
			xI+=10;
		}

	} else if (key== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
		
		
		if((xI>=110 && xI<=200 && yI<=650 &&yI>=240) || (xI>=110 && xI<=400 && yI<=300 &&yI>=240)||(xI>=110 && xI<=550 && yI<=150 &&yI>=90)||(xI>=460 && xI<=550 && yI<=350 &&yI>=90)||(xI>=260 && xI<=750 && yI<=500 &&yI>=440)||(xI>=660 && xI<=750 && yI<=500 &&yI>=240)|| (xI>=660 && xI<=870 && yI<=300 &&yI>=240)|| (xI>=780 && xI<=870 && yI<=300 &&yI>=110)|| (xI>=560 && xI<=650 && yI<=720 &&yI>=590) || (xI>=210 && xI<=240 && yI<=340 &&yI>=300) || (xI>=750 && xI<=770 && yI<=320 &&yI>=300) || (xI>=430 && xI<=450 && yI<=170 &&yI>=150))
		{
			xI-=10;
		}
		
	} else if (key== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
		if((xI>=110 && xI<=200 && yI<=650 &&yI>=240) || (xI>=110 && xI<=400 && yI<=300 &&yI>=240)||(xI>=110 && xI<=550 && yI<=150 &&yI>=90)||(xI>=460 && xI<=550 && yI<=350 &&yI>=90)||(xI>=260 && xI<=750 && yI<=500 &&yI>=440)||(xI>=660 && xI<=750 && yI<=500 &&yI>=240)|| (xI>=660 && xI<=870 && yI<=300 &&yI>=240) || (xI>=780 && xI<=870 && yI<=300 &&yI>=110)|| (xI>=560 && xI<=650 && yI<=720 &&yI>=590) || (xI>=210 && xI<=240 && yI<=340 &&yI>=300) || (xI>=750 && xI<=780 && yI<=320 &&yI>=300) || (xI>=430 && xI<=450 && yI<=170 &&yI>=150))
		{
			yI-=10;
		}
	}

	else if (key== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
		if((xI>=110 && xI<=200 && yI<=650 &&yI>=240) ||(xI>=110 && xI<=400 && yI<=300 &&yI>=240)||(xI>=110 && xI<=550 && yI<=150 &&yI>=90)||(xI>=460 && xI<=550 && yI<=350 &&yI>=90)||(xI>=260 && xI<=750 && yI<=500 &&yI>=440)||(xI>=660 && xI<=750 && yI<=500 &&yI>=240)|| (xI>=660 && xI<=870 && yI<=300 &&yI>=240)|| (xI>=780 && xI<=870 && yI<=300 &&yI>=110)|| (xI>=560 && xI<=650 && yI<=720 &&yI>=590) || (xI>=210 && xI<=240 && yI<=340 &&yI>=300) || (xI>=750 && xI<=770 && yI<=320 &&yI>=300) || (xI>=430 && xI<=450 && yI<=170 &&yI>=150))
		{
			yI+=10;
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	
	if ( key == 'v' || key == 'V')
	    {
	    	glutDisplayFunc(GameDisplay);
	    }
	    
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
 
void Timer(int m) {
        
        timme=timme-1;

	// implement your functionality here
	//moveCar();
	//moveCar2();
	//moveCar3();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by ABDULLAH TAHIR"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	menu(); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	//glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
