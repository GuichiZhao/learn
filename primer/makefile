CXX=g++
CXXFLAGS+=-std=c++11
# CXXFLAGS+=-DNDEBUG 


objects = prog.o hello.o world.o 
main: $(objects)
	g++  $(objects) -o prog

prog.o: prog.cpp hello.h world.h
hello.o: hello.cpp hello.h 
world.o: world.cpp world.h


clean: 
	rm prog $(objects)
