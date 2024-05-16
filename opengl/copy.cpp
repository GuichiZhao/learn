#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

static unsigned int CompileShader(unsigned int type, const string &source)
{
  unsigned int id = glCreateShader(type);
  const char *src = source.c_str();
  glShaderSource(id, 1, &src, nullptr);
  glCompileShader(id);

  int result;
  glGetShaderiv(id, GL_COMPILE_STATUS, &result);
  if (result == GL_FALSE)
  {
    int length;
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
    char *message = (char *)alloca(length * sizeof(char));
    glGetShaderInfoLog(id, length, &length, message);
    cout << "Fail to compile shader\n"
         << message << endl;
  }
  return id;
}

static int CreateShader(const string &vertexShader, const string &fragmentShader)
{
  unsigned int program = glCreateProgram();
  int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
  glLinkProgram(program);
  glValidateProgram(program);

  // glDeleteShader(vs);
  // glDeleteShader(fs);

  return program;
}

int main(void)
{
  if (!glfwInit())
  {
    return -1;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // ver
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for MAC ONLY
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  GLFWwindow *window;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }
  /* Make the window's context current */
  glfwMakeContextCurrent(window);
  /* Initialize the library */
  if (GLEW_OK != glewInit())
  {
    cout << "GLEW ERROR" << endl;
  }
  else
  {
    cout << glGetString(GL_VERSION) << endl;
  }

  float positions[] = {
      -0.5f,
      -0.5f,
      0.0f,
      0.5f,
      0.5f,
      -0.5f};
  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

  string vertexShader =
      "#version 330 core\n"
      "layout(location=0) in vec4 position;\n"
      "void main(){\n"
      "gl_Position = position;\n"
      "}\n";
  string fragmentShader =
      "#version 330 core\n"
      "layout(location=0) out vec4 color;\n"
      "void main(){\n"
      "color=vec4(1.0,0.0,0.0,1.0);\n"
      "}\n";

  unsigned int shader = CreateShader(vertexShader, fragmentShader);
  glUseProgram(shader);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window))
  {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
