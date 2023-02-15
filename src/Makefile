LLVM_VERSION ?= 11
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
OUTPUT = library.wasm
OBJ = library.o memory.o


$(OUTPUT): $(OBJ) Makefile
	wasm-ld \
		-o $(OUTPUT) \
		--no-entry \
		--strip-all \
		--export-dynamic \
		--allow-undefined \
		--initial-memory=131072 \
		-error-limit=0 \
		--lto-O3 \
		-O3 \
		--gc-sections \
		$(OBJ) \
		$(LIBCXX_OBJ) \

library.o:library.cpp common.h js.h
	clang++ -c $(COMPILE_FLAGS) -o library.o library.cpp
memory.o:memory.cpp common.h 
	clang++ -c $(COMPILE_FLAGS) -o memory.o memory.cpp