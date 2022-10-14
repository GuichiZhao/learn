objects=main.o hello.o
hello: $(objects)
	g++ $(objects) -o hello
main.o: main.cpp hello.h
hello.o: hello.cpp hello.h

clean: 
	rm main.o hello.o hello
