#include "pch.h"
#include "Game.h"

//#include <iostream>

/*
*	ResourceManager - has all the Shaders
*	Renderer has a reference to a Shader!
*	
*	Make 'IResource' interface that Shader and Texture class has to conform to
* 
*	TODO:
*	  - read window details from a file. 
*	 - return false if failed to compile shader...
*	
* 
*	Implement entity component system...	
*		Have different components rather than everything in GameObject...
* 
*/

int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (...)
	{
		std::cerr << "Unexpected error. Program terminating\n";
	}

	return 0;
}



//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <stb_image/stb_image.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include "constants/Constants.h"
//#include "models/camera/Camera.h"
//#include "models/Shader.h"
//
//#include <iostream>
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow* window);	
//
//// Camera
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = constants::SCR_WIDTH / 2.0f;
//float lastY = constants::SCR_HEIGHT / 2.0f;
////bool firstMouse = true;
//
//// timing 
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//int main()
//{
//
//	// Intialize glfw 
//	if (!glfwInit())
//		return -1;
//
//	// configure glfw
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef  __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif //  __APPLE__
//
//
//	// window creation
//	GLFWwindow* window = glfwCreateWindow(constants::SCR_WIDTH, constants::SCR_HEIGHT, "OpenGL Game", nullptr, nullptr);
//	if (!window)
//	{
//		glfwTerminate();
//		return -1;
//	}
//
//	// make window's context current
//	glfwMakeContextCurrent(window);
//
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	// glew: load OpenGL function pointers
//	if (glewInit() != GLEW_OK)
//		return -1;
//
//	glEnable(GL_DEPTH_TEST);
//
//	Shader shader("src/shaders/default.vert", "src/shaders/default.frag");
//
//
//	float vertices[]
//	{
//		 0.5f,  0.5f, 0.5f,		1.0f, 1.0f,
//		 0.5f, -0.5f, 0.5f,		1.0f, 0.0f,
//		-0.5f, -0.5f, 0.5f,		0.0f, 0.0f,
//		-0.5f,  0.5f, 0.5f,		0.0f, 1.0f,
//
//		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,	1.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f
//	};
//
//	int indices[]
//	{
//		// Front face
//		0, 1, 2,
//		2, 3, 0,
//
//		// Left face
//		3, 7, 6,
//		3, 2, 6,
//
//		// Right face
//		0, 1, 5,
//		0, 4, 5,
//
//		// Back face
//		6, 7, 4,
//		6, 5, 4,
//
//		// Top face
//		3, 7, 4,
//		7, 4, 0,
//
//		// Bottom face
//		6, 2, 1,
//		6, 5, 1
//
//	};
//
//
//	glm::vec3 boxPositions[]
//	{
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	unsigned int VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	// position attribute
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	// texture
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//
//
//
//
//	return 0;
//}
//
//
//
//
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	static bool firstMouse{ true };
//
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	float xoffset = xpos - lastX;
//	float yoffset = lastY - ypos;
//
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.processMouseMovement(xoffset, yoffset);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.processMouseScroll(yoffset);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.processKeyboard(Camera::FORWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.processKeyboard(Camera::BACKWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.processKeyboard(Camera::LEFT, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.processKeyboard(Camera::RIGHT, deltaTime);
//}











//
//#include <GLFW/glfw3.h>
//
//int main()
//{
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}