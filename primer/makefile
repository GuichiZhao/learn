CXX=c++
CXXFLAGS+=-std=c++17

objects = prog.o b.o a.o
main: $(objects)
	g++ $(objects) -o prog

prog.o: prog.cpp a.h b.h
a.o: a.cpp a.h
b.o: b.h b.cpp

clean: 
	rm prog $(objects)
