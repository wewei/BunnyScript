%option noyywrap

%top {
    #include "AST/AST.h"
    using namespace Bunny::AST;

    #include "bunny.tab.h"
    
}

Integer     [1-9][0-9]*
Float       {Integer}?\.[0-9]+
ArithOper   [\+\-*/()^]

%%
0           {
            yylval.astIntegerExpression = new IntegerExpression(0);
            return INTEGER;
            }

{Integer}   {
            yylval.astIntegerExpression = new IntegerExpression(atoi(yytext));
            return INTEGER;
            }

{Float}     {
            yylval.astFloatExpression = new FloatExpression(atof(yytext));
            return FLOAT;
            }

{ArithOper} { return *yytext; }

"<"         { return LT; }

"<="        { return LE; }

">"         { return GT; }

">="        { return GE; }

"=="        { return EQ; }

"!="        { return NE; }

"not"       { return NOT; }

"and"       { return AND; }

"or"        { return OR; }

"xor"       { return XOR; }

"false"     {
            yylval.astBooleanExpression = new BooleanExpression(false);
            return BOOLEAN;
            }

"true"      {
            yylval.astBooleanExpression = new BooleanExpression(true);
            return BOOLEAN;
            }


[:space:]

