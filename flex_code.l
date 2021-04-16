%{
	/*Definitions*/
	#include<stdio.h>
	#include<string.h>
	#include "bison_code.tab.h"
	void showError();
%}

/* move = operation direction */
/* assignment = ASSIGN number TO numberCOMMAnumber */
/* naming = VAR identifier IS numberCOMMAnumber */
/* query = VALUE IN numberCOMMAnumber */
operation (ADD|SUBTRACT|MULTIPLY|DIVIDE)
direction (LEFT|RIGHT|UP|DOWN)
number ([0-9]+)
identifier ([a-zA-Z_][a-zA-Z0-9_]*)
ASSIGN (ASSIGN)
TO (TO)
COMMA [,]
VAR (VAR)
IS (IS)
VALUE (VALUE)
IN (IN)
SPACE [ \t]
FULL_STOP [.]
GG <<EOF>>
%%
	
{operation} {sscanf(yytext, "%s", yylval.name); return(OPERATION);}
{direction} {sscanf(yytext, "%s", yylval.name); return(DIRECTION);}
{FULL_STOP} {return(FULL_STOP);}
{SPACE} {return(SPACE);}
{IN} {return(IN);}
{VALUE} {return(VALUE);}
{IS} {return(IS);}
{VAR} {return(VAR);}
{COMMA} {return(COMMA);}
{TO} {return(TO);}
{ASSIGN} {return(ASSIGN);}
{identifier} {sscanf(yytext, "%s", yylval.name); return(IDENTIFIER);}
{number} {yylval.num = atoi(yytext); return(NUMBER);}
. {showError(); return(OTHER);}
\n {return(NEWLINE);}
{GG} {return(GG);}
%%

int yywrap() {
	return(1);
}

void showError(){
	printf("ERROR IN INPUT\n");
}