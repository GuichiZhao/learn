cmake_minimum_required(VERSION 3.22.1)

project(test_guichi)

add_executable(${PROJECT_NAME} main.cpp)
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/add/build)
target_link_libraries(${PROJECT_NAME} guichiadd)