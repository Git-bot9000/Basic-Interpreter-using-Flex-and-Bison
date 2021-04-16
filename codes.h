#ifndef _STDIOH_
#define _STDIOH_
#include<stdio.h>
#endif

#ifndef _STDLIBH_
#define _STDLIBH_
#include<stdlib.h>
#endif

#ifndef _STRINGH_
#define _STRINGH_ 
#include<string.h>
#endif

#ifndef _TIMEH_
#define _TIMEH_
#include<time.h>
#endif

#ifndef _YYPARSE_
#define _YYPARSE_
int yyparse();
#endif

#ifndef _PRINT_BOARD_
#define _PRINT_BOARD_ 
void print_board(int flag);
#endif

#ifndef _GENERATE_BOARD_
#define _GENERATE_BOARD_ 
void generate_board();
#endif

#ifndef _MOVE_
#define _MOVE_
void move(char op[100], char dir[100]);
#endif

#ifndef _ASSIGN_
#define _ASSIGN_
void assign(int num, int x, int y);
#endif

#ifndef _OPERATE_
#define _OPERATE_
void operate(char op[100], int i1, int j1, int i, int j);
#endif

#ifndef _INSERT_RANDOM_TILE_
#define _INSERT_RANDOM_TILE_
void insert_random_tile();
#endif

#ifndef _PRINT_TILE_
#define _PRINT_TILE_
void print_tile(int x, int y);
#endif

#ifndef _NAME_TILE_
#define _NAME_TILE_ 
void name_tile(int x, int y, char str[100]);
#endif