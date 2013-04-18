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
    PStringC                astString;
    PNodeC                  astNode;

    // Expressions
    PExpressionC            astExpression;
    PBooleanExpressionC     astBooleanExpression;
    PIntegerExpressionC     astIntegerExpression;
    PFloatExpressionC       astFloatExpression;
    PStringExpressionC      astStringExpression;
    PUnaryExpressionC       astUnaryExpression;
    PBinaryExpressionC      astBinaryExpression;
    PMemberExpressionC      astMemberExpression;
    PCallExpressionC        astCallExpression;
    PAssignExpressionC      astAssignExpression;
    PAsyncExpressionC       astAsyncExpression;

    // Statements
    PStatementC             astStatement;
    PExpressionStatementC   astExpressionStatement;
    PBlockStatementC        astBlockStatement;
    PIfStatementC           astIfStatement;

    // Misc
    PNameC                  astName;
    PArgumentListC          astArgumentList;
    PLValueC                astLValue;
    PStatementListC         astStatementList;

}

%token <astIntegerExpression>   INTEGER
%token <astFloatExpression>     FLOAT
%token <astBooleanExpression>   BOOLEAN
%token <astStringExpression>    STRING
%token <astString>              IDENTIFIER
%token ADD MINUS MULTIPLY DIVIDE POWER
%token LT LE GT GE EQ NE
%token NOT AND OR XOR
%token DOT COMMA
%token PAR_L PAR_R
%token BRT_L BRT_R
%token BRC_L BRC_R
%token ASYNC
%token ASSIGN ADD_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN
%token COLON SEMICOLON
%token IF ELSE

%type <astStatement>            Program

%type <astExpression>           Expression
%type <astBinaryExpression>     BinaryExpression
%type <astUnaryExpression>      UnaryExpression
%type <astMemberExpression>     MemberExpression
%type <astCallExpression>       CallExpression
%type <astAssignExpression>     AssignExpression
%type <astAsyncExpression>      AsyncExpression

%type <astStatement>            Statement
%type <astExpressionStatement>  ExpressionStatement
%type <astBlockStatement>       BlockStatement
%type <astIfStatement>          IfStatement

%type <astName>                 Name
%type <astArgumentList>         ArgumentList
%type <astLValue>               LValue
%type <astStatementList>        StatementList

%nonassoc   THEN
%nonassoc   ELSE
%right      ASSIGN ADD_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN
%left       OR
%left       XOR
%left       AND
%left       NOT
%left       EQ NE
%left       LT LE GT GE
%left       ADD MINUS
%left       MULTIPLY DIVIDE
%left       POWER
%right      UMINUS
%left       PAR_L PAR_R DOT ASYNC BRT_L BRT_R

%start Program

%%
Program
    : Statement
        { program = SPStatementC($1); } 

Expression
    : INTEGER
        { $$ = $1; }
    | FLOAT
        { $$ = $1; }
    | BOOLEAN
        { $$ = $1; }
    | STRING
        { $$ = $1; }
    | BinaryExpression
        { $$ = $1; }
    | UnaryExpression
        { $$ = $1; }
    | MemberExpression
        { $$ = $1; }
    | CallExpression
        { $$ = $1; }
    | AssignExpression
        { $$ = $1; }
    | AsyncExpression
        { $$ = $1; }
    | PAR_L Expression PAR_R
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
    | Expression BRT_L Expression BRT_R
        { $$ = new BinaryExpression(SPExpressionC($1), SPExpressionC($3), BO_SUBS); }

UnaryExpression
    : MINUS Expression %prec UMINUS
        { $$ = new UnaryExpression(SPExpressionC($2), UO_NEG); }
    | NOT Expression
        { $$ = new UnaryExpression(SPExpressionC($2), UO_NOT); }

MemberExpression
    : Name
        { $$ = new MemberExpression(SPExpressionC(), SPNameC($1)); }
    | Expression DOT Name
        { $$ = new MemberExpression(SPExpressionC($1), SPNameC($3)); }

CallExpression
    : Expression PAR_L PAR_R
        { $$ = new CallExpression(SPExpressionC($1), SPArgumentListC()); }
    | Expression PAR_L ArgumentList PAR_R
        { $$ = new CallExpression(SPExpressionC($1), SPArgumentListC($3)); }

AssignExpression
    : LValue ASSIGN Expression
        { $$ = new AssignExpression(SPLValueC($1), SPExpressionC($3), AO_ASSIGN); }
    | LValue ADD_ASSIGN Expression
        { $$ = new AssignExpression(SPLValueC($1), SPExpressionC($3), AO_ADD_ASSIGN); }
    | LValue MINUS_ASSIGN Expression
        { $$ = new AssignExpression(SPLValueC($1), SPExpressionC($3), AO_MINUS_ASSIGN); }
    | LValue MULTIPLY_ASSIGN Expression
        { $$ = new AssignExpression(SPLValueC($1), SPExpressionC($3), AO_MULTIPLY_ASSIGN); }
    | LValue DIVIDE_ASSIGN Expression
        { $$ = new AssignExpression(SPLValueC($1), SPExpressionC($3), AO_DIVIDE_ASSIGN); }

AsyncExpression
    : ASYNC PAR_L Expression PAR_R
        { $$ = new AsyncExpression(SPExpressionC($3)); }

Statement
    : ExpressionStatement
        { $$ = $1; }
    | BlockStatement
        { $$ = $1; }
    | IfStatement
        { $$ = $1; }

ExpressionStatement
    : SEMICOLON
        { $$ = new ExpressionStatement(SPExpressionC()); }
    | Expression SEMICOLON
        { $$ = new ExpressionStatement(SPExpressionC($1)); }

BlockStatement
    : BRC_L BRC_R
        { $$ = new BlockStatement(SPStatementListC()); }
    | BRC_L StatementList BRC_R
        { $$ = new BlockStatement(SPStatementListC($2)); }

IfStatement
    : IF PAR_L Expression PAR_R Statement   %prec THEN
        { $$ = new IfStatement(SPExpressionC($3), SPStatementC($5), SPStatementC()); }
    | IF PAR_L Expression PAR_R Statement ELSE Statement
        { $$ = new IfStatement(SPExpressionC($3), SPStatementC($5), SPStatementC($7)); }

Name
    : IDENTIFIER
        { $$ = new Name(SPStringC($1)); }

ArgumentList
    : Expression
        { $$ = new ArgumentList(SPExpressionC($1), SPArgumentListC()); }
    | Expression COMMA ArgumentList
        { $$ = new ArgumentList(SPExpressionC($1), SPArgumentListC($3)); }

LValue
    : MemberExpression
        { $$ = new LValue(SPExpressionC($1)); }

StatementList
    : Statement
        { $$ = new StatementList(SPStatementC($1), SPStatementListC()); }
    | Statement StatementList
        { $$ = new StatementList(SPStatementC($1), SPStatementListC($2)); }

%%

int yyerror(const char *s)
{
    std::cout<< s << std::endl;
    exit(-1);
}

