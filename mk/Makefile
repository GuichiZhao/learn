Program=count_words
vpath %.c src
vpath %.l src
vpath %.h include
CPPFLAGS = -I include

test:$(Program)
	./$(Program) < src/lexer.l
$(Program): count_words.o lexer.o 
	gcc $(CPPFLAGS) -L/usr/local/opt/flex/lib -lfl $^ -o $@
count_words.o: count_words.c counter.h
	gcc $(CPPFLAGS) -c  $<
lexer.o: lexer.c lexer.h
	gcc $(CPPFLAGS) -c $<
lexer.c: lexer.l
	flex -t $< > $@
.PHONY: clean
clean: lexer.l
	rm -f *.o lexer.c

