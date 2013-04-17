%option noyywrap

%top {
    #include "AST/AST.h"
    using namespace Bunny::AST;

    #include "bunny.tab.h"
    
    static SPString stringBuffer;
    extern int yyerror(const char *);

}

%x X_STR

Integer     [1-9][0-9]*
Float       {Integer}?\.[0-9]+
Identifier  [_a-zA-Z$][_a-zA-Z0-9$]*

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

"+"         { return ADD; }

"-"         { return MINUS; }

"*"         { return MULTIPLY; }

"/"         { return DIVIDE; }

"^"         { return POWER; }

"<"         { return LT; }

"<="        { return LE; }

">"         { return GT; }

">="        { return GE; }

"=="        { return EQ; }

"!="        { return NE; }

"="         { return ASSIGN; }

"+="        { return ADD_ASSIGN; }

"-="        { return MINUS_ASSIGN; }

"*="        { return MULTIPLY_ASSIGN; }

"/="        { return DIVIDE_ASSIGN; }

"not"       { return NOT; }

"and"       { return AND; }

"or"        { return OR; }

"xor"       { return XOR; }

"async"     { return ASYNC; }

"false"     {
            yylval.astBooleanExpression = new BooleanExpression(false);
            return BOOLEAN;
            }

"true"      {
            yylval.astBooleanExpression = new BooleanExpression(true);
            return BOOLEAN;
            }

"."         { return DOT; }

","         { return COMMA; }

"("         { return PAR_L; }

")"         { return PAR_R; }

"["         { return BRT_L; }

"]"         { return BRT_R; }

"{"         { return BRC_L; }

"}"         { return BRC_R; }

{Identifier}    {
            yylval.astString = new String(yytext);
            return IDENTIFIER;
            }

\"          {
            stringBuffer.reset(new String());
            BEGIN(X_STR);
            }

[:space:]

<X_STR>\"   {
            yylval.astStringExpression = new StringExpression(stringBuffer);
            stringBuffer.reset();
            BEGIN(INITIAL);
            return STRING;
            }

<X_STR>\n   {
            yyerror("Unterminated String.");
            }

<X_STR>\\[0-7]{1,3}     {
            int result = 0;

            for (char *p = yytext + 1; *p != 0; p ++) {
                result <<= 3;
                result |= *p - '0';
            }

            if ( result > 0xff )
                yyerror("Unrecognized charector.");

            *stringBuffer += (char)result;
            }

<X_STR>\\[0-9]+     {
            yyerror("Unrecognized charector.");
            }

<X_STR>\\n  *stringBuffer += '\n';
<X_STR>\\t  *stringBuffer += '\t';
<X_STR>\\r  *stringBuffer += '\r';
<X_STR>\\b  *stringBuffer += '\b';
<X_STR>\\f  *stringBuffer += '\f';

<X_STR>\\(.|\n)  *stringBuffer = yytext[1];

<X_STR>[^\\\n\"]+   {
            *stringBuffer += yytext;
            }

