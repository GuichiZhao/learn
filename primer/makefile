CXX=g++
CXXFLAGS+=-std=c++14
CXXFLAGS+=-DNDEBUG 


objects = prog.o StrBlob.o StrBlobPtr.o Sales_data.o
output = prog

run: $(output)
	./${output} < record.txt

$(output): $(objects)
	g++  $(objects) -o $(output)

prog.o: prog.cpp StrBlob.h
StrBlob.o: StrBlob.h StrBlob.cpp
StrBlobPtr.o: StrBlobPtr.h StrBlobPtr.cpp
Sales_data.o: Sales_data.h Sales_data.cpp


clean: 
	rm prog $(objects)
