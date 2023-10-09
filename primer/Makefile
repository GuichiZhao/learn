CXX=g++
CXXFLAGS+=-std=c++11
CXXFLAGS+=-DNDEBUG 
CXXFLAGS+=-Wall
# CXXFLAGS+=-Werror=vla

objects = prog.o help.o
output = prog

run: $(output)
	./${output} 

$(output): $(objects)
	g++  $(objects) -o $(output)

prog.o: prog.cpp fn.h
help.o: help.cpp fn.h



clean: 
	rm prog $(objects)
