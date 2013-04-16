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
    PNodeC                  astNode;
    PExpressionC            astExpression;
    PBooleanExpressionC     astBooleanExpression;
    PIntegerExpressionC     astIntegerExpression;
    PFloatExpressionC       astFloatExpression;
    PStringExpressionC      astStringExpression;
    PUnaryExpressionC       astUnaryExpression;
    PBinaryExpressionC      astBinaryExpression;
}

%token <astIntegerExpression> INTEGER
%token <astFloatExpression> FLOAT
%token <astBooleanExpression> BOOLEAN
%token ADD MINUS MULTIPLY DIVIDE POWER
%token LT LE GT GE EQ NE
%token NOT AND OR XOR

%type <astExpression>       Program
%type <astExpression>       Expression
%type <astBinaryExpression> BinaryExpression
%type <astUnaryExpression>  UnaryExpression

%left OR
%left XOR
%left AND
%left NOT
%left EQ NE
%left LT LE GT GE
%left ADD MINUS
%left MULTIPLY DIVIDE
%left POWER
%left UMINUS

%start Program

%%
Program
    : Expression
        { program = SPExpressionC($1); } 

Expression
    : INTEGER
        { $$ = $1; }
    | FLOAT
        { $$ = $1; }
    | BOOLEAN
        { $$ = $1; }
    | BinaryExpression
        { $$ = $1; }
    | UnaryExpression
        { $$ = $1; }
    | '(' Expression ')'
        { $$ = $2; }

BinaryExpression
    : Expression ADD Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_ADD); }
    | Expression MINUS Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_MINUS); }
    | Expression MULTIPLY Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_MULTIPLY); }
    | Expression DIVIDE Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_DIVIDE); }
    | Expression POWER Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_POWER); }
    | Expression LT Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_LT); }
    | Expression LE Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_LE); }
    | Expression GT Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_GT); }
    | Expression GE Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_GE); }
    | Expression EQ Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_EQ); }
    | Expression NE Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_NE); }
    | Expression AND Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_AND); }
    | Expression OR Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_OR); }
    | Expression XOR Expression
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_XOR); }

UnaryExpression
    : MINUS Expression %prec UMINUS
        { $$ = new UnaryExpression(SPExpressionC($2), UO_NEG); }
    | NOT Expression
        { $$ = new UnaryExpression(SPExpressionC($2), UO_NOT); }

%%

int main()
{
    SPTreePrinter pprinter(new SimpleTreePrinter());
    yyparse();
    program->Print(*pprinter);

    return 0;
}

int yyerror(const char *s)
{
    std::cout<< s << std::endl;
    exit(-1);
}

