Program=count_words
vpath %.c src
vpath %.l src 
vpath %.xml src
vpath %.h include
CPPFLAGS = -I include


test:$(Program)
	./$(Program) < src/lexer.l
$(Program): lexer.o counter.o /usr/local/opt/flex/lib/libfl.a

count_words.o: counter.h
.PHONY: clean
clean: 
	rm -f *.o lexer.c $(Program) *.html *.a
print:
	@echo $(LOADLIBES)

