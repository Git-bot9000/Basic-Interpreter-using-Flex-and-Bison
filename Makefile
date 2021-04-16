default:
	clear
	flex -l flex_code.l
	bison -d bison_code.y 
	gcc -o exe bison_code.tab.c lex.yy.c main.c 
