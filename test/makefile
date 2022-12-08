CXX=c++
CXXFLAGS+=-std=c++17

objects = main.o a.o b.o
main: $(objects)
	g++ $(objects) -o main

main.o: main.cpp 
a.o: a.h a.cpp
b.o: b.h b.cpp

clean: 
	rm main $(objects)
