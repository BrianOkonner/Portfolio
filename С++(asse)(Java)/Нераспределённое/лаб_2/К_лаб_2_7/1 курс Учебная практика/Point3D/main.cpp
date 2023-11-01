#include "Point3D.h"
#include "Circle.h"
#include <iostream>
using namespace std;

#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

int alpha=0, beta=0;

Color p_Color(1, 0, 0, 0.5);// Наша точка будет красной и полупрозрачной
Coord p_Coord(3, 3, 3);		// И располагается она в таких координатах

Point3D pp(p_Coord, p_Color);
Circle cc(pp, 1);

void CALLBACK Key_LEFT(){
	alpha -= 5;
}

void CALLBACK Key_RIGHT(){
	alpha += 5;
}


void CALLBACK Key_UP(){
	beta += 5;
}

void CALLBACK Key_DOWN(){
	beta -= 5;
}

void CALLBACK resize(int width,int height){
	glViewport(0,0,width,height);
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(-5,5, -5,5, 2,12);   
	gluLookAt(5, 5, 5, 0,0,0, 0,0,1 );
	glMatrixMode( GL_MODELVIEW );
}    

void CALLBACK display(){
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   
	glPushMatrix();
	glRotated(alpha, 0, 1, 0);
	glRotated(beta, -1, 0, 0);
	
	glLineWidth(5); 

	// Рисуем координатные оси
	glBegin(GL_LINES);
		glColor3d(1,1,1);
		glVertex3d(0,0,0); 
		glVertex3d(0,4,0); 

		glVertex3d(0,0,0); 
		glVertex3d(4,0,0); 

		glVertex3d(0,0,0); 
		glVertex3d(0,0,4); 
	glEnd();
	
	// Отрисовываем созданную точку
	//pp.Draw();
	cc.Draw();
	
	glPopMatrix();
  
	auxSwapBuffers();
};

void main(){
	float pos[4] = {3,3,3,0.5};
	float dir[3] = {-1,-1,-1};

    GLfloat mat_specular[] = {1,1,1,1};

    auxInitPosition( 50, 10, 400, 400);
    auxInitDisplayMode( AUX_RGB | AUX_DEPTH | AUX_DOUBLE );
    auxInitWindow( "Light" );
    auxIdleFunc(display);
    auxReshapeFunc(resize);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0);

	glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, 0); 
	glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, 90); 
   
    auxKeyFunc(AUX_LEFT, Key_LEFT);
    auxKeyFunc(AUX_RIGHT, Key_RIGHT);
    auxKeyFunc(AUX_UP, Key_UP);
    auxKeyFunc(AUX_DOWN, Key_DOWN);

	auxMainLoop(display);
}
