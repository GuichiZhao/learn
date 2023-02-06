CXX=g++
CXXFLAGS+=-std=c++14
CXXFLAGS+=-DNDEBUG 


objects = prog.o StrBlob.o StrBlobPtr.o
main: $(objects)
	g++  $(objects) -o prog

prog.o: prog.cpp StrBlob.h
StrBlob.o: StrBlob.h StrBlob.cpp
StrBlobPtr.o: StrBlobPtr.h StrBlobPtr.cpp


clean: 
	rm prog $(objects)
