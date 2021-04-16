%{
#include "codes.h"
int yylex();
int yyerror(char *s);

%}

%token OPERATION DIRECTION FULL_STOP SPACE IN VALUE IS VAR COMMA TO ASSIGN IDENTIFIER NUMBER OTHER NEWLINE GG

%type <name> IDENTIFIER
%type <name> OPERATION
%type <name> DIRECTION
%type <num> NUMBER

%union{
	char name[100];
	int num;
}

%%

prog:
  stmts
;

stmts:
		| stmt stmts
		| GG{
			exit(1);
		}

stmt:
		move | assignment | naming | query
		| error NEWLINE {yyerrok; yyclearin; printf("Syntax Error\n"); fprintf(stderr, "-1\n"); printf("> ");}
;

move:
	OPERATION SPACE DIRECTION FULL_STOP NEWLINE{
		move($1, $3);
		printf("> ");
	}
;

assignment:
	ASSIGN SPACE NUMBER SPACE TO SPACE NUMBER COMMA NUMBER FULL_STOP NEWLINE{
		if($7>4 || $7<1 || $9>4 || $9<1){
			printf("Error: The coordinates must be in the range [1,4]\n");
			fprintf(stderr, "-1\n");
		}
		else{
		assign($3, $7, $9);
		}
		printf("> ");
	}
;

naming:
	VAR SPACE IDENTIFIER SPACE IS SPACE NUMBER COMMA NUMBER FULL_STOP NEWLINE{
		if($7>4 || $7<1 || $9>4 || $9<1){
			printf("Error: The coordinates must be in the range [1,4]\n");
			fprintf(stderr, "-1\n");
		}
		else{
			name_tile($7, $9, $3);
		}
		printf("> ");	
	}
;

query:
	VALUE SPACE IN SPACE NUMBER COMMA NUMBER FULL_STOP NEWLINE{
		if($5>4 || $5<1 || $7>4 || $7<1){
			printf("Error: The coordinates must be in the range [1,4]\n");
			fprintf(stderr, "-1\n");
		}
		else{
			print_tile($5, $7);
		}
		printf("> ");
	}
;

%%

int yyerror(char *s)
{
/*
	printf("%s\n", s);
	fprintf(stderr, "-1\n");
*/
	return 0;
}

