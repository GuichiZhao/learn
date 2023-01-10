CXX=g++
CXXFLAGS+=-std=c++11
CXXFLAGS+=-DNDEBUG 


objects = prog.o hello.o world.o Sales_data.o Screen.o Window_mgr.o
main: $(objects)
	g++  $(objects) -o prog

prog.o: prog.cpp hello.h world.h
hello.o: hello.cpp hello.h 
world.o: world.cpp world.h hello.h
Sales_data.o: Sales_data.cpp Sales_data.h
Screen.o: Screen.cpp Screen.h
Window_mgr.o: Window_mgr.cpp Window_mgr.h


clean: 
	rm prog $(objects)
