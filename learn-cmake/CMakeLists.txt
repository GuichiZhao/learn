cmake_minimum_required(VERSION 3.22.1)

project(test_guichi)


add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(external/glfw)

add_subdirectory(add)
target_include_directories(${PROJECT_NAME} 
  PUBLIC add 
  PUBLIC external/glfw/include
)
target_link_directories(${PROJECT_NAME} 
  PRIVATE external/glfw/src
)
target_link_libraries(${PROJECT_NAME} guichiadd glfw) 