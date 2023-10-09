DEPS = 
OBJ = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
OUTPUT = main.js


COMPILE_FLAGS = -Wall \
		--target=wasm32 \
		-Os \
		-nostdlib \
		-fvisibility=hidden \
		-std=c++14 \
		-ffunction-sections \
		-fdata-sections \
		-DPRINTF_DISABLE_SUPPORT_FLOAT=1 \
		-DPRINTF_DISABLE_SUPPORT_LONG_LONG=1 \
		-DPRINTF_DISABLE_SUPPORT_PTRDIFF_T=1

$(OUTPUT): $(OBJ) Makefile
	em++ -s LLD_REPORT_UNDEFINED -sEXPORTED_FUNCTIONS=_main,_int_sqrt  -sEXPORTED_RUNTIME_METHODS=ccall,cwrap\
		-o $(OUTPUT) \
		$(OBJ)


%.o: %.cpp $(DEPS) Makefile
	em++ \
		-c \
		-o $@ \
		$<


clean:
	rm -f $(OBJ) $(NANOLIBC_OBJ) $(OUTPUT)