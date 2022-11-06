objects=main.o htable.o list.o
main: $(objects)
	g++ $(objects) -o main

main.o: main.cpp htable.h
htable.o: htable.cpp htable.h
list.o: list.cpp list.h
stack.o: stack.cpp stack.h
sequencer.o: stack.h sequencer.cpp sequencer.h

clean: 
	rm main $(objects)
