%option noyywrap
%top {
    #include "bunny.tab.h"
}

Integer [1-9][0-9]*
Float {Integer}?\.[0-9]+

%%
0           { /*printf("0: %s\n", yytext); */yylval.ival = 0; return INTEGER; }
{Integer}   { /*printf("1: %s\n", yytext); */yylval.ival = atoi(yytext); return INTEGER; }
{Float}     { /*printf("2: %s\n", yytext); */yylval.fval = atof(yytext); return FLOAT; }
[\+\-*/()^]  { /*printf("3: %s\n", yytext); */return *yytext; }
[:space:]

