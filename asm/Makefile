AS		:= nasm
ASFLAGS := -f elf -d ELF_TYPE
CFLAGS	:= -m32
LDFLAGS := -m32
CC		:= gcc
CXX		:= g++
CXXFLAGS := -m32
DEP := driver.o asm_io.o

.PHONY: clean
main: main.cpp
	g++ main.cpp && ./a.out

run: first
	./first

%.o: %.asm
	$(AS) $(ASFLAGS) $< 

first: $(DEP)

clean :
	rm -f *.o
