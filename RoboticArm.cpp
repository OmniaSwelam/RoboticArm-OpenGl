// camera movement -- cyrstall ball interface using arrow keys
#include <math.h>
#include <stdlib.h>
#include "stdafx.h"
#include <iostream>
#include <GL/freeglut.h>
#include "stdafx.h"


int X = 0; //shoulder's angle
int Y = 0; //Elbow's angle
int A = 0; //finger1's angle
int B = 0; //finger2's angle
int C = 0; //finger3's angle
int D = 0; //finger4's angle


int windowWidth = 1024;
int windowHeight = 768;

float aspect = float(windowWidth) / float(windowHeight);

float spin = 0.0;
bool rotating = false;

double eye[] = { 0,0,1 };
double center[] = { 0,0,0 };
double up[] = { 0,1,0 };


void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta)*p[0];
	temp[1] += cos(theta)*p[1];
	temp[2] += cos(theta)*p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];

}

void Left()
{
	double speed = 3.1415 / 8;
	rotatePoint(up, speed, eye);
}

void Right()
{
	double speed = 3.1415 / 8;
	rotatePoint(up, -speed, eye);
}

void Up()
{
	double speed = 3.1415 / 8;
	double rot_axis[3];
	double look[3];

	look[0] = -eye[0];
	look[1] = -eye[1];
	look[2] = -eye[2];

	crossProduct(look, up, rot_axis);

	normalize(rot_axis);

	rotatePoint(rot_axis, speed, eye);

	rotatePoint(rot_axis, speed, up);

}

void Down()
{
	double speed = 3.1415 / 8;
	double rot_axis[3];
	double look[3];

	look[0] = -eye[0];
	look[1] = -eye[1];
	look[2] = -eye[2];

	crossProduct(look, up, rot_axis);

	normalize(rot_axis);

	rotatePoint(rot_axis, -speed, eye);

	rotatePoint(rot_axis, -speed, up);

}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);

	glColor3f(250, 0, 0);


	glPushMatrix(); //push identity 

					//draw shoulder

	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(X, 0.0, 0.0, 1.0);
	//glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(1.0, 0.12, 0.1);
	glutWireCube(.253);
	glPopMatrix();

	//draw Elbow
	glTranslatef(0.257, 0.0, 0.0);
	glRotatef(Y, 0.0, 0.0, 1.0);
	//glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(1.0, 0.12, 0.1);
	glutWireCube(.253);
	glPopMatrix();

	//draw finger1
	glTranslatef(0.15, 0.009, 0.0);
	glRotatef(A, 0.0, 0.0, 1.0);
	//glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.23, 0.05, 0.1);
	glutWireCube(0.14);
	glPopMatrix();


	//draw finger2
	glTranslatef(0.0, -0.01, 0.0);
	glRotatef(B, 0.0, 0.0, 1.0);
	//glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.23, 0.05, 0.1);
	glutWireCube(0.14);
	glPopMatrix();

	//draw finger3
	glTranslatef(0.0, -0.01, 0.0);
	glRotatef(C, 0.0, 0.0, 1.0);
	//glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.23, 0.05, 0.1);
	glutWireCube(0.14);
	glPopMatrix();



	//draw finger4
	glTranslatef(0.0, -0.01, 0.0);
	glRotatef(D, 0.0, 0.0, 1.0);
	//glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.23, 0.05, 0.1);
	glutWireCube(0.14);
	glPopMatrix();
	glutSwapBuffers();



	glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 's': //press s to rotate shoulder up
		X = (X + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S': //press s to rotate shoulder down
		X = (X - 5) % 360;
		glutPostRedisplay();
		break;
	case '!': //press e to rotate Elbow up
		Y = (Y + 5) % 360;
		glutPostRedisplay();
		break;
	case '1': //press E to rotate Elbow down
		Y = (Y - 5) % 360;
		glutPostRedisplay();
		break;
	case 'a': //press a to rotate finger1 up
		A = (A + 5) % 360;
		glutPostRedisplay();
		break;
	case 'A': //press A to rotate finger1 down
		A = (A - 5) % 360;
		glutPostRedisplay();
		break;
	case 'b': //press b to rotate finger2 up
		B = (B + 5) % 360;
		glutPostRedisplay();
		break;
	case 'B': //press B to rotate finger2 down
		B = (B - 5) % 360;
		glutPostRedisplay();
		break;
	case 'c': //press c to rotate finger3 up
		C = (C + 5) % 360;
		glutPostRedisplay();
		break;
	case 'C': //press C to rotate finger3 down
		C = (C - 5) % 360;
		glutPostRedisplay();
		break;
	case 'd': //press d to rotate finger3 up
		D = (D + 5) % 360;
		glutPostRedisplay();
		break;
	case 'D': //press D to rotate finger3 down
		D = (D - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}
void specialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT: Left(); break;
	case GLUT_KEY_RIGHT: Right(); break;
	case GLUT_KEY_UP:    Up(); break;
	case GLUT_KEY_DOWN:  Down(); break;
	}

	glutPostRedisplay();
}

int main(void)
{

	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Cyrstall Ball Interface Example");

	glMatrixMode(GL_PROJECTION);
	gluPerspective(60, aspect, 0, 10);


	glutDisplayFunc(display);
	glutSpecialFunc(specialKeys);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;

}


