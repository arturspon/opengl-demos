/**
 * Basic usege of OpenGL and GLFW. 
 */

#include <iostream>
#include <GLFW/glfw3.h>

#define WIDTH 500
#define HEIGHT 500

float direction = 1.0f;
float direction2 = 1.0f;
float acceleration = -1.00f;
float acceleration2 = 1.00f;

int main() {
	GLFWwindow* window;
	int width, height;

	if (!glfwInit()) {
		std::cout << "Problem to initialize GLFW" << std::endl;
		exit(1);
	}
	
	window = glfwCreateWindow(WIDTH, HEIGHT, "Hello world, GLFW!", NULL, NULL);

	if (!window) {
		std::cout << "Problem to create GLFW window" << std::endl;
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(window);

	while(glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) == 0) {
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);

		// Exercício 1
		// glBegin(GL_LINES);
		// 	glColor3f(1.f, 0.f, 0.f);
		// 	glVertex3f(-1.0f, -1.0f, 0.0f);
		// 	glVertex3f(1.0f, 1.0f, 0.0f);
		// glEnd();

		// Exercício 2
		// glBegin(GL_LINES);
		// 	glColor3f(1.f, 0.f, 0.f);
		// 	glVertex3f(-0.4f, -0.6f, 0.0f);
		// 	glVertex3f(-0.4f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(0.4f, -0.6f, 0.0f);
		// 	glVertex3f(0.4f, 0.6f, 0.0f);
		// glEnd();

		// Exercício 3
		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(-0.5f, -0.6f, 0.0f);
		// 	glVertex3f(-0.5f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(-0.5f, -0.6f, 0.0f);
		// 	glVertex3f(0.5f, -0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(0.5f, -0.6f, 0.0f);
		// 	glVertex3f(0.5f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(-0.5f, 0.6f, 0.0f);
		// 	glVertex3f(0.5f, 0.6f, 0.0f);
		// glEnd();

		// Exercício 4
		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(-0.5f, -0.6f, 0.0f);
		// 	glVertex3f(-0.5f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(-0.5f, -0.6f, 0.0f);
		// 	glVertex3f(0.5f, -0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(0.5f, -0.6f, 0.0f);
		// 	glVertex3f(0.5f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(-0.5f, 0.6f, 0.0f);
		// 	glVertex3f(0.5f, 0.6f, 0.0f);
		// glEnd();


		// ====== AULA DIA 22/08/2019 ======

		acceleration += 0.01f * direction;
		acceleration2 += 0.01f * direction2;

		// Exercício 1
		// glBegin(GL_LINES);
		// 	glColor3f(1.f, 0.f, 0.f);
		// 	glVertex3f(acceleration, -0.5f, 0.0f);
		// 	glVertex3f(acceleration, 0.5f, 0.0f);
		// glEnd();

		// if(acceleration >= 1) {
		// 	direction *= -1;
		// }
		// if (acceleration <= -1) {
		// 	direction *= -1;
		// }

		// Exercício 2
		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(acceleration - 0.5f, -0.6f, 0.0f);
		// 	glVertex3f(acceleration - 0.5f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(acceleration - 0.5f, -0.6f, 0.0f);
		// 	glVertex3f(acceleration + 0.5f, -0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(acceleration + 0.5f, -0.6f, 0.0f);
		// 	glVertex3f(acceleration + 0.5f, 0.6f, 0.0f);
		// glEnd();

		// glBegin(GL_LINES);
		// 	glColor3f(0.f, 0.f, 1.f);
		// 	glVertex3f(acceleration - 0.5f, 0.6f, 0.0f);
		// 	glVertex3f(acceleration + 0.5f, 0.6f, 0.0f);
		// glEnd();

		// if(acceleration + 0.50f >= 1.0f) {
		// 	direction = -1;
		// }
		// if(acceleration <= -0.5f) {
		// 	direction = 1;
		// }

		// Exercício 3
		glColor3f(0.f, 0.f, 1.f);
		glBegin(GL_LINES);
			glVertex3f(acceleration - 0.5f, -0.6f, 0.0f);
			glVertex3f(acceleration - 0.5f, 0.6f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(acceleration - 0.5f, -0.6f, 0.0f);
			glVertex3f(acceleration + 0.5f, -0.6f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(acceleration + 0.5f, -0.6f, 0.0f);
			glVertex3f(acceleration + 0.5f, 0.6f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(acceleration - 0.5f, 0.6f, 0.0f);
			glVertex3f(acceleration + 0.5f, 0.6f, 0.0f);
		glEnd();

		if(acceleration + 0.50f >= 1.0f) {
			direction = -1;
		}
		if(acceleration <= -0.5f) {
			direction = 1;
		}

		glColor3f(1.f, 0.f, 0.f);
		glBegin(GL_LINES);
			glVertex3f(acceleration2 - 0.5f, -0.6f, 0.0f);
			glVertex3f(acceleration2 - 0.5f, 0.6f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(acceleration2 - 0.5f, -0.6f, 0.0f);
			glVertex3f(acceleration2 + 0.5f, -0.6f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(acceleration2 + 0.5f, -0.6f, 0.0f);
			glVertex3f(acceleration2 + 0.5f, 0.6f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(acceleration2 - 0.5f, 0.6f, 0.0f);
			glVertex3f(acceleration2 + 0.5f, 0.6f, 0.0f);
		glEnd();

		if(acceleration2 + 0.50f >= 1.0f) {
			direction2 = -1;
		}
		if(acceleration2 <= -0.5f) {
			direction2 = 1;
		}

		// Exercício 4
		glBegin(GL_TRIANGLES);
			glColor3f(0.f, 1.f, 0.f);
			glVertex3f(0.5f, -0.6f, 0.0f);
			glVertex3f(0.5f, 0.6f, 0.0f);
			glVertex3f(0.5f, 0.6f, 0.0f);
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
