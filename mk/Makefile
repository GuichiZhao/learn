count_words: guichi
count_words: count_words.o lexer.o 
	gcc count_words.o lexer.o -lfl -o count_words
count_words.o: count_words.c 
	gcc -c  count_words.c
lexer.o: lexer.c
	gcc -c lexer.c
lexer.c: lexer.l
	flex -t lexer.l > lexer.c
.PHONY: clean
clean:
	rm -f *.o lexer.c