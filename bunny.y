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
    PFunctionExpressionC    astFunctionExpression;

    // Statements
    PStatementC             astStatement;
    PExpressionStatementC   astExpressionStatement;
    PBlockStatementC        astBlockStatement;
    PIfStatementC           astIfStatement;
    PForStatementC          astForStatement;
    PWhileStatementC        astWhileStatement;
    PBreakStatementC        astBreakStatement;
    PContinueStatementC     astContinueStatement;
    PDeclarationStatementC  astDeclarationStatement;
    PReturnStatementC       astReturnStatement;

    // Types
    PTypeC                  astType;
    PSimpleTypeC            astSimpleType;
    PSpecializedTypeC       astSpecializedType;

    // Misc
    PNameC                  astName;
    PArgumentListC          astArgumentList;
    PLValueC                astLValue;
    PStatementListC         astStatementList;
    PTypeListC              astTypeList;
    PParameterListC         astParameterList;

}

%token <astIntegerExpression>   INTEGER
%token <astFloatExpression>     FLOAT
%token <astBooleanExpression>   BOOLEAN
%token <astStringExpression>    STRING
%token <astString>              IDENTIFIER
%token ADD MINUS MULTIPLY DIVIDE POWER
%token LT LE GT GE EQ NE
%token NOT AND OR XOR
%token DOT COMMA AT CARET
%token PAR_L PAR_R
%token BRT_L BRT_R
%token BRC_L BRC_R
%token ASYNC
%token ASSIGN ADD_ASSIGN MINUS_ASSIGN MULTIPLY_ASSIGN DIVIDE_ASSIGN
%token COLON SEMICOLON
%token IF ELSE WHILE FOR IN BREAK CONTINUE RETURN DEF

%type <astStatement>            Program

%type <astExpression>           Expression
%type <astBinaryExpression>     BinaryExpression
%type <astUnaryExpression>      UnaryExpression
%type <astMemberExpression>     MemberExpression
%type <astCallExpression>       CallExpression
%type <astAssignExpression>     AssignExpression
%type <astAsyncExpression>      AsyncExpression
%type <astFunctionExpression>   FunctionExpression

%type <astStatement>            Statement
%type <astExpressionStatement>  ExpressionStatement
%type <astBlockStatement>       BlockStatement
%type <astIfStatement>          IfStatement
%type <astForStatement>         ForStatement
%type <astWhileStatement>       WhileStatement
%type <astBreakStatement>       BreakStatement
%type <astContinueStatement>    ContinueStatement
%type <astDeclarationStatement> DeclarationStatement
%type <astReturnStatement>      ReturnStatement

%type <astName>                 Name
%type <astType>                 Type
%type <astSimpleType>           SimpleType
%type <astSpecializedType>      SpecializedType

%type <astArgumentList>         ArgumentList
%type <astLValue>               LValue
%type <astStatementList>        StatementList
%type <astTypeList>             TypeList
%type <astParameterList>        ParameterList

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
    | FunctionExpression
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

FunctionExpression
    : CARET PAR_L PAR_R Statement
        { $$ = new FunctionExpression(SPTypeC(), SPParameterListC(), SPStatementC($4)); }
    | CARET PAR_L ParameterList PAR_R Statement
        { $$ = new FunctionExpression(SPTypeC(), SPParameterListC($3), SPStatementC($5)); }
    | CARET Type PAR_L PAR_R Statement
        { $$ = new FunctionExpression(SPTypeC($2), SPParameterListC(), SPStatementC($5)); }
    | CARET Type PAR_L ParameterList PAR_R Statement
        { $$ = new FunctionExpression(SPTypeC($2), SPParameterListC($4), SPStatementC($6)); }

Statement
    : ExpressionStatement
        { $$ = $1; }
    | BlockStatement
        { $$ = $1; }
    | IfStatement
        { $$ = $1; }
    | ForStatement
        { $$ = $1; }
    | WhileStatement
        { $$ = $1; }
    | BreakStatement
        { $$ = $1; }
    | ContinueStatement
        { $$ = $1; }
    | DeclarationStatement
        { $$ = $1; }
    | ReturnStatement
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

ForStatement
    : FOR PAR_L LValue IN Expression PAR_R Statement
        { $$ = new ForStatement(SPLValueC($3), SPExpressionC($5), SPStatementC($7)); }

WhileStatement
    : WHILE PAR_L Expression PAR_R Statement
        { $$ = new WhileStatement(SPExpressionC($3), SPStatementC($5)); }

BreakStatement
    : BREAK SEMICOLON
        { $$ = new BreakStatement(); }

ContinueStatement
    : CONTINUE SEMICOLON
        { $$ = new ContinueStatement(); }

DeclarationStatement
    : DEF Type Name SEMICOLON
        { $$ = new DeclarationStatement(SPTypeC($2), SPNameC($3), SPExpressionC()); }
    | DEF Type Name ASSIGN Expression SEMICOLON
        { $$ = new DeclarationStatement(SPTypeC($2), SPNameC($3), SPExpressionC($5)); }

ReturnStatement
    : RETURN SEMICOLON
        { $$ = new ReturnStatement(SPExpressionC()); }
    | RETURN Expression SEMICOLON
        { $$ = new ReturnStatement(SPExpressionC($2)); }

Type
    : SimpleType
        { $$ = $1; }
    | SpecializedType
        { $$ = $1; }

SimpleType
    : Name
        { $$ = new SimpleType(SPTypeC(), SPNameC($1)); }
    | Type COLON Name
        { $$ = new SimpleType(SPTypeC($1), SPNameC($3)); }

SpecializedType
    : Type LT GT
        { $$ = new SpecializedType(SPTypeC($1), SPTypeListC()); }
    | Type LT TypeList GT
        { $$ = new SpecializedType(SPTypeC($1), SPTypeListC($3)); }

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

TypeList
    : Type
        { $$ = new TypeList(SPTypeC($1), SPTypeListC()); }
    | Type COMMA TypeList
        { $$ = new TypeList(SPTypeC($1), SPTypeListC($3)); }

ParameterList
    : Type Name
        { $$ = new ParameterList(SPTypeC($1), SPNameC($2), SPParameterListC()); }
    | Type Name COMMA ParameterList
        { $$ = new ParameterList(SPTypeC($1), SPNameC($2), SPParameterListC($4)); }


%%

int yyerror(const char *s)
{
    std::cout<< s << std::endl;
    exit(-1);
}

