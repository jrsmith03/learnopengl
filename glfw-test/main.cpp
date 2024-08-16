#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void printCursor(GLFWwindow* win);


void printCursor(GLFWwindow* win) {
	double x, y;

	glfwGetCursorPos(win, &x, &y);
	printf("Cursor at %f, %f\n", x, y);

}

void processInput(GLFWwindow* win) {
	if (glfwGetKey(win, GLFW_KEY_0)) {

		printf("The 'user' pressed the 0 key.\n");
	}
}

int main() {
	glfwInit();
	
	
	// Create hte main window.
	GLFWwindow* win = glfwCreateWindow(640, 480, "My GLFW Test", NULL, NULL);
	if (!win) {
		printf("Failed to initialize GLFW window!\n");
		return -1;
	}
	// GLFW doesn't leave the GL context current after the call to glfwCreateWindow() @48650497
	glfwMakeContextCurrent(win);

	// GIve OS-specific OpenGL function pointers 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Failed to initialize GLAD");
		return -1;

	}

	// The book suggests we implement a callback function and register it for a window resize event.
	// I am going to keep this simple tonight, however.
	glViewport(0, 0, 640, 480);

	// Render loop
	while (!glfwWindowShouldClose(win)) {
		processInput(win);
		printCursor(win);

		// Render a color
		glClearColor(10, 10, 10, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		// Execute any callbacks on the Event Queue
		glfwPollEvents();

		// Actually show the colors that are in the 2d Color Buffer
		glfwSwapBuffers(win);


	}

	// Free up GLFW resources.
	glfwTerminate();
	return 0;
}
