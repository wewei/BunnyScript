%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
%}

%union {
    int ival;
    float fval;
}

%token <ival> INTEGER
%token <fval> FLOAT
%token <fval> UMINUS

%type <fval> Expr
%type <fval> Num
%type <fval> ExprStart

%left '+' '-'
%left '*' '/'
%left '^'
%left UMINUS

%start ExprStart

%%
ExprStart: Expr { printf("%f\n", $$); } 

Num : INTEGER  { $$ = $1; }
    | FLOAT { $$ = $1; }

Expr : Num { $$ = $1; }
     | Expr '+' Expr { $$ = $1 + $3; }
     | Expr '-' Expr { $$ = $1 - $3; }
     | Expr '*' Expr { $$ = $1 * $3; }
     | Expr '/' Expr { $$ = $1 / $3; }
     | Expr '^' Expr { $$ = pow($1, $3); }
     | '(' Expr ')' { $$ = $2; }
     | '-' Expr %prec UMINUS { $$ = -$2; }

%%

int main()
{
    yyparse();
    return 0;
}

int yyerror(const char *s)
{
    printf("%s", s);
    exit(-1);
}

