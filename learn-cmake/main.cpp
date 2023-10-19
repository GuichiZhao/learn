#include <iostream>
#include "adder.h"
#include "GLFW/glfw3.h"
using namespace std;
int main()
{
  cout << "20+30= " << guich::add(20, 30) << endl;
  GLFWwindow *window;
  int width, height;
  if (!glfwInit())
  {
    fprintf(stderr, "Failed to initialize GLFW\n");
    exit(EXIT_FAILURE);
  }
  glfwWindowHint(GLFW_DEPTH_BITS, 16);
  glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

  window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
  // Main loop
  while (!glfwWindowShouldClose(window))
  {

    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Terminate GLFW
  glfwTerminate();
}