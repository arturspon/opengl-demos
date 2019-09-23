/**
 * Simple demonstration of transformations.
 */

#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

int direction = 1;
float posX = 0.0f;
float speedX = 0.0f;
float rotSpeed = 0.0f;
float scaleSpeed = 0.2f;
int scaleDirection = 1;

// Rotate X
GLfloat rX = 0;
// Rotate Y
GLfloat rY = 0;

void renderCoordinateAxis()
{
	// X axis - green color
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
		// Left side, negative X
		glVertex2f(-1.0, 0.0);
		glVertex2f(0.0, 0.0);

		// Right side, positive X
		glVertex2f(0.0, 0.0);
		glVertex2f(1.0, 0.0);
	glEnd();

	// Y axis - blue color
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
		// Top side, positive Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 1.0);

		// Bottom side, negative Y
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, -1.0);
	glEnd();
}

void display()
{
	// Clear the screen painting it all with the white color
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	// Inform OpenGL we want to make changes to the modelview matrix
	glMatrixMode(GL_MODELVIEW);

	// Render the X and Y axis to guide ourselves.
	renderCoordinateAxis();

	// Render a red square
	glColor3f(1, 0, 0);
	glTranslatef(posX, 0.0f, 0);
	glScalef(scaleSpeed, scaleSpeed, 0.0f);
	glRotatef(0.0f + rX, 0.0f, 0.0f, 1.0f);
	glRectf(-0.1f, 0.1f, 0.1f, -0.1f);
	
	// Render a blue square
	// glColor3f(0, 0, 1);
	// glTranslatef(0.2f, 0.2f, 0);
	// glRotatef(45.0f, 0, 0, 1.0f);
	// glRectf(-0.1f, 0.1f, 0.1f, -0.1f);

	glutSwapBuffers();

	posX += speedX * direction;
	direction = (posX >= 0.7 || posX <= -1.1) ? direction*-1 : direction;
	rX += rotSpeed;
	scaleSpeed += 0.08f * scaleDirection;
	scaleDirection = (scaleSpeed >= 1.00f || scaleSpeed <= 0.02f) ? scaleDirection*-1 : scaleDirection;
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 27) {
		// ESC key
		exit(0);
	}
	if(key == '1') {
		rotSpeed = (rotSpeed == 0.0f) ? 2048.00f : 0.0f;
	}
	if(key == '2') {
		speedX = (speedX == 0.0f) ? 0.01f : 0.0f;
	}
	if(key == '3') {
		scaleDirection = (scaleDirection == 0) ? 1 : 0;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Transformation - Simple");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);


	glutMainLoop();
	return 0;
}