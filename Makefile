AST_HEADERS = $(wildcard include/AST/*.h)
AST_SOURCES = $(wildcard src/AST/*.cpp)

LEX_FILE = lex.yy.c

bunny : $(LEX_FILE) bunny.tab.c $(AST_SOURCES)
	g++ -DDEBUG -Iinclude -o bunny $(LEX_FILE) bunny.tab.c $(AST_SOURCES)
$(LEX_FILE) : bunny.l bunny.tab.h
	flex bunny.l
bunny.tab.h bunny.tab.c : bunny.y
	bison -d bunny.y

clean: clean-test
	rm -f bunny.tab.h bunny.tab.c $(LEX_FILE) bunny
    
test : test_ast

clean-test: clean-test_ast

clean-test_ast:
	rm -f test_ast

test_ast : $(AST_HEADER) test/TestAST.cpp $(AST_SOURCES)
	g++ -DDEBUG -Iinclude test/TestAST.cpp $(AST_SOURCES) -o $@

.PHONY : clean test clean-test clean-test_ast

