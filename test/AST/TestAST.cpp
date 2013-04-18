#include <iostream>
#include <string>

#include "AST/AST.h"

using namespace Bunny::AST;

extern int yyparse();
extern FILE *yyin;
extern SPNodeC program;

int main(int argc, char **argv)
{
    extern FILE *yyin;
    if (argc > 0) {
       yyin = fopen(argv[1], "r"); 
    }
    SPTreePrinter pprinter(new SimpleTreePrinter());
    yyparse();
    program->Print(*pprinter);

    return 0;
}

