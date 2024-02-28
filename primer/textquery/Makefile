vpath %.cpp src
vpath %.h include

CXX=g++
CXXFLAGS=-g -Wall -std=c++11 -I include
prog:main.o QueryResult.o TextQuery.o
	g++ $(CXXFLAGS) main.o QueryResult.o TextQuery.o -o prog
# main.o: main.cpp
# QueryResult.o: QueryResult.cpp QueryResult.h
# TextQuery.o: TextQuery.cpp QueryResult.h 

print:
	echo $(LINK.o)



clean:
	rm *.o