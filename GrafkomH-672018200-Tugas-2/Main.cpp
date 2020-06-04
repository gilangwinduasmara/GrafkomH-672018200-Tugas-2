#include <iostream>
#include <GL/freeglut.h>


#define HEIGHT 480
#define WIDTH 640

using namespace std;

void drawOutline() {
	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(200, 400);
		glVertex2i(280, 300);
		glVertex2i(200, 100);
		glVertex2i(120, 300);
	glEnd();
}

void drawFill() {
	glBegin(GL_POLYGON);
	glColor3d(0.4, 0.2, 0.8);
	glVertex2i(200, 400);
	glVertex2i(280, 300);
	glColor3d(0.1, 0.1, 0.2);
	glVertex2i(200, 100);
	glVertex2i(120, 300);
	glEnd();
}

void drawFrame() {
	glBegin(GL_LINES);
		glVertex2i(280, 300);
		glVertex2i(120, 300);
	glEnd();
	glBegin(GL_LINES);
		glVertex2i(200, 400);
		glVertex2i(200, 100);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(1);
	drawFill();
	drawOutline();
	drawFrame();
	glFlush();
}


void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIDTH, 0.0, HEIGHT);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Layang layang");
	glutDisplayFunc(display);

	init();
	glutMainLoop();
	return 0;
}