CXX=g++
CXXFLAGS+=-std=c++11
# CXXFLAGS+=-DNDEBUG 
CXXFLAGS+=-Wall
# CXXFLAGS+=-Werror=vla

objects = prog.o StrBlob.o StrBlobPtr.o
output = prog

run: $(output)
	./${output} < input.txt

$(output): $(objects)
	g++  $(objects) -o $(output)




clean: 
	rm prog $(objects)
