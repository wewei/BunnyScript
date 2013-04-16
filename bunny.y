%{
#include <iostream>
#include <cstdlib>

#include "AST/AST.h"

using namespace Bunny::AST;

extern int yylex(void);
extern int yyerror(const char *);

SPNodeC program;

%}

%union {
    int                     ival;
    double                  fval;
    
    PNodeC                  astNode;
    PExpressionC            astExpression;
    PBooleanExpressionC     astBooleanExpression;
    PIntegerExpressionC     astIntegerExpression;
    PFloatExpressionC       astFloatExpression;
    PStringExpressionC      astStringExpression;
    PUnaryExpressionC       astUnaryExpression;
    PBinaryExpressionC      astBinaryExpression;
}

%token <ival> INTEGER
%token <fval> FLOAT

%type <astExpression> Expression
%type <astExpression> Program

%left '+' '-'
%left '*' '/'
%left '^'
%left UMINUS

%start Program

%%
Program
    : Expression
        { program = SPExpressionC($1); } 

Expression
    : INTEGER
        { $$ = new IntegerExpression($1); }
    | FLOAT
        { $$ = new FloatExpression($1); }
    | Expression '+' Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_ADD); }
    | Expression '-' Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_MINUS); }
    | Expression '*' Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_MULTIPLY); }
    | Expression '/' Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_DIVIDE); }
    | Expression '^' Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_POWER); }
    | '(' Expression ')'
        { $$ = $2; }
    | '-' Expression %prec UMINUS
        { $$ = new UnaryExpression(SPExpressionC($2), UO_NEG); }

%%

int main()
{
    SPASTPrinter pprinter(new ASTPrinter());
    yyparse();
    program->Print(*pprinter);

    return 0;
}

int yyerror(const char *s)
{
    std::cout<< s << std::endl;
    exit(-1);
}

