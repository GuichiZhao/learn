# vpath %.h ./glfw-3.4.bin.MACOS/include

CXX=g++
CXXFLAGS=-g -Wall -std=c++11 -I glfw-3.4.bin.MACOS/include 
# export DYLD_LIBRARY_PATH=./lib:$DYLD_LIBRARY_PATH
run: main
	export DYLD_LIBRARY_PATH=./lib:glfw-3.4.bin.MACOS/lib-x86_64 && ./main
main: main.o 
	g++ main.o ${CXXFLAGS} -L glfw-3.4.bin.MACOS/lib-x86_64 -lglfw.3 -framework Cocoa -framework OpenGL -framework IOKit -o main 
# main: main.o 
# 	g++ main.o ${CXXFLAGS} glfw-3.4.bin.MACOS/lib-x86_64/libglfw3.a -o main 
main.o: main.cpp
	g++ ${CXXFLAGS} -c main.cpp

clean:
	rm *.o
