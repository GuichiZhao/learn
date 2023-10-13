CXX=g++
CXXFLAGS+=-std=c++11
# CXXFLAGS+=-DNDEBUG 
CXXFLAGS+=-Wall
# CXXFLAGS+=-Werror=vla

objects = prog.o Sales_Data.o header.o
output = prog

run: $(output)
	./${output} 

$(output): $(objects)
	g++  $(objects) -o $(output)

prog.o: prog.cpp Sales_Data.h
Sales_Data.o: Sales_Data.cpp Sales_Data.h
header.o: header.cpp header.h Sales_Data.h 



clean: 
	rm prog $(objects)
