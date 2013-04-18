AST_HEADERS = $(wildcard include/AST/*.h)
AST_SOURCES = $(wildcard src/AST/*.cpp)

LEX_FILE = lex.yy.c

all : test

$(LEX_FILE) : bunny.l bunny.tab.h
	flex bunny.l
bunny.tab.h bunny.tab.c : bunny.y
	bison -v -d bunny.y

clean: clean-test
	rm -f bunny.tab.h bunny.tab.c bunny.output $(LEX_FILE) bunny
    
test : test_ast

clean-test: clean-test_ast

clean-test_ast:
	rm -f test_ast

test_ast : $(AST_HEADER) test/AST/TestAST.cpp $(AST_SOURCES) $(LEX_FILE) bunny.tab.c
	g++ -DDEBUG -Iinclude test/AST/TestAST.cpp $(AST_SOURCES) $(LEX_FILE) bunny.tab.c -o $@

.PHONY : clean test clean-test clean-test_ast all

