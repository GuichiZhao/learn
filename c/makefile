objects=main.o htable.o list.o symboltable.o
main: $(objects)
	g++ $(objects) -o main

main.o: main.cpp 
htable.o: htable.cpp htable.h
symboltable.o: symboltable.cpp symboltable.h htable.h
list.o: list.cpp list.h
stack.o: stack.cpp stack.h
sequencer.o: stack.h sequencer.cpp sequencer.h

clean: 
	rm main $(objects)
