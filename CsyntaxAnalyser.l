%{
    /*
    This a c syntax analyser lrx program
    */
%}

%%
[\t ]+ { }

#include<[a-z]{3,12}.h>    { printf("%s - header file",yytext);}

int |
float |
double |
char       { printf("%s - data type",yytext); }

for |
if |
ifelse |
while |
do |
switch |
void |
long |
sizeof |
struct |
malloc |
short |
static |
break |
default |
printf     { printf("%s - special keyword",yytext); }

\+ |
\* |
\/ |
\^%$         { printf("%s - arthematic operator",yytext); }

\( |
\) |
\{ |
\}           { printf("%s - prantheses",yytext); }

.|\n       { ECHO; }
%%

int yywrap() {

}
int main()
{
    yylex();
}