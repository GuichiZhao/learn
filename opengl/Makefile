GLFW=glfw-3.4.bin.MACOS
GLAD=glad

GLFW_LIB=${GLFW}/lib-x86_64


LINK= -L ${GLFW_LIB} -lglfw.3 \
-L $(GLEW_LIB) -lGLEW \
-framework Cocoa -framework OpenGL -framework IOKit \
-Ibuild/include glad/src/glad.c

CXX=g++
CXXFLAGS=-g -Wall -std=c++11 -framework OpenGL -I $(GLFW)/include -I ${GLAD}/include 


run: main
	export DYLD_LIBRARY_PATH=./lib:${GLFW_LIB}:$(GLEW_LIB) \
&& ./main
main: main.o glad.o
	g++ main.o ${CXXFLAGS} ${LINK} -o main 

main.o: main.cpp
	g++ ${CXXFLAGS} -c main.cpp

# glad.o: glad.c
# 	gcc  -c glad.c -I ${GLAD}/include

clean:
	rm *.o
