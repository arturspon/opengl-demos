/**
 * This is an extremely simple and clean demo showing the basics of OpenGL and glut.
 * You can use this project as a starting point to create your own OpenGL application.
 *
 * Author: Fernando Bevilacqua <fernando.bevilacqua@uffs.edu.br>
 * License: MIT
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

struct _vertex {
	float x;
	float y;
	float z;
};

struct _vertex point1;
struct _vertex point2;
struct _vertex point3;
struct _vertex point4;
struct _vertex point5;
struct _vertex point6;
struct _vertex point7;
struct _vertex point8;

// Constants to define the width/height of the window
const int WIDTH = 800;
const int HEIGHT = 800;

void renderCoordinateAxis(){
	point1.x += 0.05f;
	point2.x += 0.05f;
	point3.x += 0.05f;
	point4.x += 0.05f;
	point5.x += 0.05f;
	point6.x += 0.05f;
	point7.x += 0.05f;

	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
		// Linha verical esquerda
		glVertex3f(point1.x, point1.y, point1.z);
		glVertex3f(point2.x, point2.y, point2.z);
	glEnd();
	glBegin(GL_LINES);
		// Linha horizontal de baixo
		glVertex3f(point1.x, point1.y, point1.z);
		glVertex3f(point3.x, point3.y, point3.z);
	glEnd();
	glBegin(GL_LINES);
		// Linha da direita
		glVertex3f(point3.x, point3.y, point3.z);
		glVertex3f(point4.x, point4.y, point4.z);
	glEnd();
	glBegin(GL_LINES);
		// Linha de cima
		glVertex3f(point2.x, point2.y, point2.z);
		glVertex3f(point4.x, point4.y, point4.z);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(point3.x, point3.y, point3.z);
		glVertex3f(point5.x, point5.y, point5.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point5.x, point5.y, point5.z);
		glVertex3f(point6.x, point6.y, point6.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point4.x, point4.y, point4.z);
		glVertex3f(point6.x, point6.y, point6.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point6.x, point6.y, point6.z);
		glVertex3f(point7.x, point7.y, point7.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point2.x, point2.y, point2.z);
		glVertex3f(point7.x, point7.y, point7.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point7.x, point7.y, point7.z);
		glVertex3f(point8.x, point8.y, point8.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point5.x, point5.y, point5.z);
		glVertex3f(point8.x, point8.y, point8.z);
	glEnd();
	glBegin(GL_LINES);
		glVertex3f(point1.x, point1.y, point1.z);
		glVertex3f(point8.x, point8.y, point8.z);
	glEnd();
}

void display()
{
	// Clear the screen painting it with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Inform we want to make changes to the modelview matrix, starting
	// with no transformation at all.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Move the camera away from the origin along the Z axis by 10 pixels.
	glTranslatef(0, 0, -10.0f);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Start the rendering on a new frame
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
	}
}

void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
	
	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);
	
	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	point1.x = 0.f, point1.y = 0.f, point1.z = 0.f; // Ponto 0, 0 esquerda baixo
	point2.x = 0.f, point2.y = 1.f, point2.z = 0.f; // Ponto 0, 1 esquerda cima
	point3.x = 1.f, point3.y = 0.0f, point3.z = 0.f; // Ponto 1, 0 direita baixo
	point4.x = 1.f, point4.y = 1.f, point4.z = 0.f; // Ponto 1, 1 direita cima

	point5.x = 1.5f, point5.y = 0.5f, point5.z = 0.f; // Ponto 0, 0 baixo meio de lado
	point6.x = 1.5f, point6.y = 1.5f, point6.z = 0.f; // Ponto 0, 0 baixo meio de lado
	point7.x = 0.5f, point7.y = 1.5f, point7.z = 0.f; // Ponto 0, 0 baixo meio de lado
	point8.x = 0.5f, point8.y = 0.5f, point8.z = 0.f; // Ponto 0, 0 baixo meio de lado

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	initView();

	glutMainLoop();
	return 0;
}