CXX=g++
CXXFLAGS+=-std=c++14
CXXFLAGS+=-DNDEBUG 


objects = prog.o StrBlob.o
main: $(objects)
	g++  $(objects) -o prog

prog.o: prog.cpp StrBlob.h
StrBlob.o: StrBlob.h StrBlob.cpp


clean: 
	rm prog $(objects)
