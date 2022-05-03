#
# Taken from "Practical Parsing with Flex and Bison" by begriffs
# https://begriffs.com/posts/2021-11-28-practical-parsing.html#mental-model-of-lr-parsing
#
# 05 Apr 2022  jpb  Add clean rule, add flex and flags

LEX=flex
LFLAGS=-d 
YACC=bison
YFLAGS=-d -Wempty-rule -Wcounterexample -t -b minic

CC = clang++-10
CFLAGS = -x c++ -I../lib -I../set -I../hash
MAKE = make
# for memory-leak tests
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# put together object files from lexer and parser, and
# link the yacc and lex libraries (in that order, to pick
# main() from yacc's library rather than lex's)

all: minic

minic.tab.h minic.tab.c: minic.y
	$(YACC) $(YFLAGS) $?

minic.lex.c : minic.l
	$(LEX) $(LFLAGS) -o $@ $^

minic : ast_c/ast.c hash/hashtable.c hash/hash.c\
		set/set.c minic.lex.c minic.tab.c
	$(CC) $(CFLAGS) $^ -o $@ -ll

clean:
	$(RM) minic minic.output minic.???.? *.o set/*.o hash/*.o ast_c/*.o
