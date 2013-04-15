bunny : lex.yy.c bunny.tab.c
	gcc -o bunny lex.yy.c bunny.tab.c
lex.yy.c : bunny.l bunny.tab.h
	flex bunny.l
bunny.tab.h bunny.tab.c : bunny.y
	bison -d bunny.y

clean: clean-test
	rm -f bunny.tab.h bunny.tab.c lex.yy.c bunny
    
test : test_ast

clean-test: clean-test_ast

clean-test_ast:
	rm -f test_ast

AST_HEADERS = $(wildcard include/AST/*.h)
AST_SOURCES = $(wildcard src/AST/*.cpp)
test_ast : $(AST_HEADER) test/TestAST.cpp $(AST_SOURCES)
	g++ -DDEBUG -Iinclude test/TestAST.cpp $(AST_SOURCES) -o $@

.PHONY : clean test clean-test clean-test_ast

