# ../wasi-sdk-19.0/bin/clang copy.c -o copy.wasm --target=wasm32-wasi
OUTPUT = library.wasm
OBJ = library.o memory.o

COMPILE_FLAGS = -Wall \
		--target=wasm32 \
		-Os \
		-flto \
		-fvisibility=hidden \
		-std=c++14 \
		-ffunction-sections \
		-fdata-sections \
		-DPRINTF_DISABLE_SUPPORT_FLOAT=1 \
		-DPRINTF_DISABLE_SUPPORT_LONG_LONG=1 \
		-DPRINTF_DISABLE_SUPPORT_PTRDIFF_T=1

$(OUTPUT): $(OBJ) Makefile
	../wasi-sdk-19.0-ubuntu/bin/clang++ $(OBJ) -nostartfiles -Wl,--export-all -Wl,--no-entry  -o library.wasm 

library.o:library.cpp common.h js.h
	../wasi-sdk-19.0-ubuntu/bin/clang++   --target=wasm32-wasi -c library.cpp -o library.o
memory.o:memory.cpp common.h 
	../wasi-sdk-19.0-ubuntu/bin/clang++  --target=wasm32-wasi -c memory.cpp -o memory.o


clean:
	rm -f $(OBJ) $(NANOLIBC_OBJ) $(OUTPUT)