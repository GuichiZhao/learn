CXX=c++
CXXFLAGS+=-std=c++17

objects = prog.o
main: $(objects)
	g++ $(objects) -o prog

prog.o: prog.cpp


clean: 
	rm prog $(objects)
