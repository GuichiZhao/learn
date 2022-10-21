objects=main.o 
main: $(objects)
	g++ $(objects) -o main

main.o: main.cpp list.h
stack.o: stack.cpp stack.h
sequencer.o: stack.h sequencer.cpp sequencer.h

clean: 
	rm main $(objects)
