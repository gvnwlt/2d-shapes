#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int width, height;

void draw() {
	/* triangle 1 */
	glBegin(GL_TRIANGLES);

	glColor3f(1, 0, 0);
	glVertex3f(-1, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(-0.5, 1, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);

	glEnd();

	/* triangle 2 */
	glBegin(GL_TRIANGLES);

	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);

	glColor3f(0, 1, 1);
	glVertex3f(0.5, 1, 0);

	glColor3f(0, 0, 1);
	glVertex3f(1, 0, 0);

	glEnd();
}

int main(void)
{
	/* set window size */
	width = 640;
	height = 480;

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "2D Shape Display", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Initialize GLEW */
	if (glewInit() != GLEW_OK)
		cout << "Error!" << endl;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* call when window gets resized to basically reset the origin */
		glfwGetFramebufferSize(window, &width, &height); // this is a callback to update the window frame buffer size after resize
		glViewport(0, 0, width, height); // gets the new resized width and height and sets origin again 

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT); 

		/* draw the triangles after window is rendered */
		draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}