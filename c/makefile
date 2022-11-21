CXX=c++
CXXFLAGS+=-std=c++17

objects = main.o htable.o list.o symboltable.o store.o scanner.o parser.o node.o funtab.o
main: $(objects)
	g++ $(objects) -o main

main.o: main.cpp 
scanner.o: scanner.h scanner.cpp
parser.o: parser.h parser.cpp
htable.o: htable.cpp htable.h
symboltable.o: symboltable.cpp symboltable.h htable.h
list.o: list.cpp list.h
store.o: store.cpp store.h
node.o: node.cpp node.h
funtab.o: funtab.cpp funtab.h symboltable.h

clean: 
	rm main $(objects)
