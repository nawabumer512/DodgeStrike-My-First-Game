//============================================================================
// Name        : Runner Game 
// Author      : M Umar farooq
// Copyright   : (c) Reserved
// Description : Basic 2D game
//============================================================================
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<stdio.h>
#include<unistd.h>
#include<sstream>
#include<cmath> 
#include<fstream>

 

//Obstracles Initials Declaration
 int x_squ  =  rand()%(850-70+1) ,  y_squ=780;
 int x_cir  =  30+(rand()%791) ,  y_cir=820   ,  x_cir2  =  40+(rand()%771)  ,  y_cir2=810;
 int score  =  0 ,  lives=3;
 bool ispaused=false,isover=false,fresh_start=true;
 string name;


 //Player's Position
 int man_x = 390  , man_y = 20;
 int comp_x=850   ,  comp_y=850;
 //Coin
 int coin_x  = 16 + (rand()%818) /*for genrating within the screen*/,  coin_y=834 ,  collected_coins=0;


using namespace std;

/* Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)*/
void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}



//Displaying Objects
void Display(){
    //ending
if(!isover){
//pausing
if(!ispaused){
    //RGBA
    glClearColor(0.2, 0.2 ,0.2, 0.2);
    glClear(GL_COLOR_BUFFER_BIT);   
    
	
    //Obstracles
      DrawSquare(    x_squ   , y_squ   ,  70     ,    colors[10]); 
      DrawSquare(    x_squ+10   , y_squ+10  ,  50     ,    colors[WHITE]); 

      DrawCircle(    x_cir   , y_cir   ,  40     ,    colors[5]); 
      DrawCircle(    x_cir   , y_cir   ,  30     ,    colors[WHITE]); 
      DrawCircle(    x_cir2  , y_cir2  ,  60     ,    colors[DARK_GOLDEN_ROD]);
      DrawCircle(    x_cir2  , y_cir2  ,  50     ,    colors[WHITE]);

      //coin
      DrawCircle( coin_x , coin_y , 16 , colors[LIGHT_YELLOW]);
      DrawCircle( coin_x , coin_y , 12 , colors[RED]);
      DrawCircle( coin_x , coin_y , 8 , colors[CYAN]);
      DrawCircle( coin_x , coin_y , 4 , colors[BLACK]);
     
      
      //Player
	  DrawSquare( man_x    , man_y    ,  50  ,  colors[2]);      //body
      DrawCircle( man_x+14 , man_y    ,  10  ,  colors[2]);      //foot left
      DrawCircle( man_x+14 , man_y-3    ,  4  ,  colors[BLACK]);

      DrawCircle( man_x+36 , man_y    ,  10  ,  colors[2]);      //foot right
      DrawCircle( man_x+36 , man_y-3    ,  4  ,  colors[BLACK]);

      DrawCircle( man_x+12 , man_y+30 ,   7  ,  colors[BLACK]);  //eye left 
      DrawCircle( man_x+12 , man_y+30 ,   4  ,  colors[GREEN]);
      DrawCircle( man_x+36 , man_y+30 ,   7  ,  colors[BLACK]);  //eye right
      DrawCircle( man_x+36 , man_y+30 ,   4  ,  colors[CYAN]);
      DrawLine( man_x+14 ,   man_y+14 ,  man_x+32 , man_y+14 , 5 , colors[MISTY_ROSE] ); //mouth
      DrawLine( man_x+14 ,   man_y+14 ,  man_x+32 , man_y+14 , 3 , colors[DEEP_PINK] );


      //Computer
	  DrawSquare( comp_x    , comp_y    ,  50  ,  colors[WHITE]);      //body
      DrawCircle( comp_x+14 , comp_y    ,  10  ,  colors[WHITE]);      //foot left
      DrawCircle( comp_x+14 , comp_y-3    ,  4  ,  colors[BLACK]);

      DrawCircle( comp_x+36 , comp_y    ,  10  ,  colors[WHITE]);      //foot right
      DrawCircle( comp_x+36 , comp_y-3    ,  4  ,  colors[BLACK]);

      DrawCircle( comp_x+12 , comp_y+30 ,   7  ,  colors[BLACK]);  //eye left 
      DrawCircle( comp_x+12 , comp_y+30 ,   4  ,  colors[RED]);
      DrawCircle( comp_x+36 , comp_y+30 ,   7  ,  colors[BLACK]);  //eye right
      DrawCircle( comp_x+36 , comp_y+30 ,   4  ,  colors[RED]);
      DrawLine( comp_x+14 ,   comp_y+14 ,  comp_x+32 , comp_y+14 , 5 , colors[MISTY_ROSE] ); //mouth
      DrawLine( comp_x+14 ,   comp_y+14 ,  comp_x+32 , comp_y+14 , 3 , colors[DEEP_PINK] );
      DrawTriangle( comp_x, comp_y+50 , comp_x+15, comp_y+50 , comp_x+7 , comp_y+70, colors[RED] );  // Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
      DrawTriangle( comp_x+35, comp_y+50 , comp_x+50, comp_y+50 , comp_x+42 , comp_y+70, colors[RED] );
      
      
      
      //Score, Lives and Coins
      
      DrawString( 50, 700, "Score : "+to_string(score)           , colors[MISTY_ROSE]);
      DrawString( 50, 650, "Lives : "+to_string(lives)           , colors[MISTY_ROSE]);
      DrawString( 50, 600, "Coins : "+to_string(collected_coins) , colors[MISTY_ROSE]);
      
      DrawString( 50, 750,"Pause(P)", colors[MISTY_ROSE]);
      DrawString( 50, 800,"Quit(Esc)", colors[MISTY_ROSE]);

 

     // Road Patteren On Screen    
      DrawLine( 283   , 0 ,  283   , 850 , 10 , colors[GHOST_WHITE] );	
      DrawLine( 567 , 0 ,  567 , 850 , 10 , colors[GHOST_WHITE] );
      
    
    
    
    
    //DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
    
	// DrawCircle(20,20,10,colors[RED]);
	// DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
    // DrawString( comp_x, comp_y, "Villan", colors[MISTY_ROSE]); 
}else
{  
    //If paused
    glClearColor(0, 0 ,0, 0);
    glClear(GL_COLOR_BUFFER_BIT);


      DrawString( 200, 400, "Score : "+to_string(score)           , colors[MISTY_ROSE]);
      DrawString( 200, 450, "Lives : "+to_string(lives)           , colors[MISTY_ROSE]);
      DrawString( 200, 500, "Coins : "+to_string(collected_coins) , colors[MISTY_ROSE]);
      DrawString( 200, 550, "Resume(R) : ", colors[MISTY_ROSE]);
      DrawString( 200, 600,"Quit(Esc)", colors[MISTY_ROSE]);

      
}}


if(isover){

          glClearColor(0, 0 ,0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    DrawString( 200, 400, "Score : "+to_string(score)           , colors[MISTY_ROSE]);
      DrawString( 200, 500, "Coins Collected : "+to_string(collected_coins) , colors[MISTY_ROSE]);
      DrawString( 350, 750, "GAME OVER : ", colors[MISTY_ROSE]);
      DrawString( 200, 600,"Quit(Esc)", colors[MISTY_ROSE]);




}

   glutSwapBuffers(); 
}









// Arrow Key Management
void NonPrintableKeys(int key, int x, int y) {
   
    //ending
    if(!isover){
    //Pausing Condition
   if(!ispaused ){
    if (key == GLUT_KEY_LEFT ) {
			
            if(man_x>0)
              man_x-=10;

      
    } else if (key == GLUT_KEY_RIGHT ) {
		
            if(man_x<800)
              man_x+=10;

    }else if (key == GLUT_KEY_UP) {
   
            if(man_y<800)
              man_y+=10;
              
  }
    else if (key == GLUT_KEY_DOWN) {
           if(man_y>20)
              man_y-=10;
    }}}
     glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
    if (key == KEY_ESC/* Escape key ASCII*/) {
        exit(1); // exit the program when escape key is pressed.
    }
    if (key == 'P' || key=='p') {
        ispaused=true;
    }else
    if (key=='R' || key=='r')
    {  
        ispaused=false;
	}else if(key=='S' || key=='s')
                  fresh_start=true;
    
    
    glutPostRedisplay();
}


   
void Timer(int m) {
    
//ending 
if(!isover){
 //pausing   
if(!ispaused){

// obstracles movement
if(score<500)
y_squ-=2,y_cir-=4,y_cir2-=1, coin_y-=2,score+=1;
else if(score<1000)
y_squ-=3,y_cir-=5,y_cir2-=4, coin_y-=6,score+=1;
else if(score<1500)
y_squ-=4,y_cir-=6,y_cir2-=5, coin_y-=7,score+=1;
else if(score<2000)
y_squ-=7,y_cir-=5,y_cir2-=6, coin_y-=8,score+=2;
else if(score<3000)
y_squ-=9,y_cir-=10,y_cir2-=11, coin_y-=12,score+=3;
else 
y_squ-=12,y_cir-=13,y_cir2-=14, coin_y-=15,score+=5;


















//SCROLLING
if(man_y<800)
man_y+=1;


//Coin Touches Bottom
if(coin_y<-16){
coin_y=834;
coin_x=16+rand()%818;
}

//Square Touches Bottom
if(y_squ<-80){
y_squ=780;
x_squ=rand()%781;
}








//Bottom Touch
if(y_cir<-30)
{
    x_cir=30+rand()%791;
    y_cir=820;
    
}

if(y_cir2<-40)
{
    x_cir2=40+rand()%771;
    y_cir2=810;
}



//Collision
if(abs(man_x-x_cir)<90 && abs(man_y-y_cir)<66)
{
   lives--;
   y_cir=810;
   x_cir=40+(rand()%871);


}
if(abs(man_x-x_cir2)<100 && abs(man_y-y_cir2)<66)
{
   lives--;
   y_cir2=790;
   x_cir2=60+ (rand()%731);

}

if(abs(man_x-x_squ)<40 && abs(man_y-y_squ)<80)
{
    
lives--;
y_squ=780;
x_squ=70+(rand()%711); 



}

//Coin Collection;
if( abs(man_x-coin_x) <66 &&  abs(man_y-coin_y)<66 )
{
   collected_coins++;
   coin_x= 16+(rand()%818);
   coin_y=834;

}










//Computer Player
if(score>=2000){
if(comp_x<man_x)
comp_x+=4;

if(comp_x>man_x)
comp_x-=4;


if(comp_y<man_y)
comp_y+=4;

if(comp_y>man_y)
comp_y-=4;
}


}

if(lives==0)
{
   isover=true;
}


if(abs(comp_x-man_x)<50 && abs(comp_y-man_y)<50)
 lives=0;



}








	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(1800.0 / FPS, Timer, 0);
}


/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
    int width = 850, height = 850; // i have set my window size to be 800 x 600
    InitRandomizer(); // seed the random number generator...
    glutInit(&argc, argv); // initialize the graphics library...

    //File Handling
   string name;
   ofstream pf_file("pf_file.txt");
   cout<<"Enter Player's Name :";
   getline(cin,name);
   pf_file<<name;
   pf_file.close();





    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(50, 50); // set the initial position of our window
    glutInitWindowSize(width, height); // set the size of our window
    glutCreateWindow("PF's Game"); // set the title of our game window
    SetCanvasSize(width, height); // set the number of pixels...

// Register your functions to the library,
// you are telling the library names of function to call for different tasks.
//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
    glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
    glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
    glutTimerFunc(5.0 / FPS, Timer, 0);

// now handle the control to library and it will call our registered functions when
// it deems necessary...
    glutMainLoop();
    return 1;
}
#endif 

