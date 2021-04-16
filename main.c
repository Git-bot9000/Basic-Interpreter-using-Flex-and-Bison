#include<stdio.h>
#include"codes.h"

struct node{
	struct node* prev;
	struct node* next;
	char name[100];
};

typedef struct node node;

struct llist{
	node* head;
	node* tail;
};

typedef struct llist llist;

int board[4][4] = {0};
llist names[4][4];

int main(){
	printf("Welcome to the GAME\n");
	generate_board();
	//Inetialising names
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			names[i][j].head = NULL;
			names[i][j].tail = NULL;
		}
	}
	printf("Here is the start board:\n");
	print_board(1);
	while(1){
		printf("> ");
    	yyparse();
	}
    return 0;
}

void print_board(int flag){
	printf("***Board***\n");
	for(int i=0; i<4; i++){
		printf(" ");
		for(int j=0; j<4; j++){
			printf("%d  ", board[i][j]);
		}
		printf("\n");
	}

	//Print names
	int f = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(board[i][j] != 0 && names[i][j].head != NULL){
				if(f == 0){
					printf("***Names***\n");
					f = 1;
				}
				printf("(%d,%d): ", i+1, j+1);

				node* new = names[i][j].head;
				while(new != NULL){
					printf("%s ", new->name);
					new = new->next;
				}
				printf("\n");			
			}
		}
	}

	if(flag == 1){
		//stderr printing
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				fprintf(stderr, "%d ", board[i][j]);
			}
		}
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(board[i][j] != 0 && names[i][j].head != NULL){
					fprintf(stderr, "%d,%d", i+1, j+1);

					node* new = names[i][j].head;
					fprintf(stderr, "%s", new->name);
					new = new->next;
					while(new != NULL){
						fprintf(stderr, ",%s", new->name);
						new = new->next;
					}
					fprintf(stderr, " ");			
				}
			}
		}
		fprintf(stderr, "\n");	
	}
}

void generate_board(){
	srand(time(0));
	int r = rand()%4, c = rand()%4;
	board[r][c]=2*(rand()%2 + 1);
}

void move(char op[100], char dir[100]){
	//printf("%s\n%s\n", op, dir);
	int i1, j1;
	if(strcmp(dir, "UP") == 0){
		//Do operation
		for(int j=0; j<4; j++){
			for(int i=0; i<4; i++){
				if(board[i][j]!=0 && i!=3){
					i1 = i, j1 =j;
					i++;
					while(i<4 && board[i][j] == 0){
						i++;
					}
					if(i<4 && board[i][j]==board[i1][j1]){
						//printf("(%d,%d) and (%d,%d)\n", i1, j1, i, j);
						operate(op, i1, j1, i, j);
						i = i1;
					}
					else{
						i--;
					}
				}
			}
		}
		//Move all tiles to one side
		for(int j=0; j<4; j++){
			for(int i=0; i<4; i++){
				if(board[i][j]==0){
					i1 = i, j1 = j;
					while(i<3 && board[i+1][j] == 0){
						i++;
					}
					if(i != 3){
						for(int p=0; i1+p<4; p++){
							if(i+1+p<4){
								board[i1+p][j1] = board[i+1+p][j];

								//Move name LLs
								names[i1+p][j1].head = names[i+1+p][j].head;
								names[i1+p][j1].tail = names[i+1+p][j].tail;
							}
							else{
								board[i1+p][j1] = 0;

								//Move name LLs
								names[i1+p][j1].head = NULL;
								names[i1+p][j1].tail = NULL;
							}
						}
					}
				}
			}
		}
	}
	if(strcmp(dir, "DOWN") == 0){
		//Do operation
		for(int j=0; j<4; j++){
			for(int i=0; i<4; i++){
				if(board[i][j]!=0 && i!=3){
					i1 = i, j1 =j;
					i++;
					while(i<4 && board[i][j] == 0){
						i++;
					}
					if(i<4 && board[i][j]==board[i1][j1]){
						//printf("(%d,%d) and (%d,%d)\n", i1, j1, i, j);
						operate(op, i1, j1, i, j);
						i = i1;
					}
					else{
						i--;
					}
				}
			}
		}
		//Move all tiles to one side
		for(int j=0; j<4; j++){
			for(int i=3; i>=0; i--){
				if(board[i][j]==0){
					i1 = i, j1 = j;
					while(i>0 && board[i-1][j] == 0){
						i--;
					}
					if(i != 0){
						for(int p=0; i1-p>=0; p++){
							if(i-1-p>=0){
								board[i1-p][j1] = board[i-1-p][j];

								//Move name LLs
								names[i1-p][j1].head = names[i-1-p][j].head;
								names[i1-p][j1].tail = names[i-1-p][j].tail;
							}
							else{
								board[i1-p][j1] = 0;

								//Move name LLs
								names[i1-p][j1].head = NULL;
								names[i1-p][j1].tail = NULL;
							}
						}
					}
				}
			}
		}
	}
	if(strcmp(dir, "LEFT") == 0){
		//Do operation
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(board[i][j]!=0 && j!=3){
					i1 = i, j1 =j;
					j++;
					while(j<4 && board[i][j] == 0){
						j++;
					}
					if(j<4 && board[i][j]==board[i1][j1]){
						//printf("(%d,%d) and (%d,%d)\n", i1, j1, i, j);
						operate(op, i1, j1, i, j);
						j = j1;
					}
					else{
						j--;
					}
				}
			}

		}
		//Move all tiles to one side
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(board[i][j]==0){
					i1 = i, j1 = j;
					while(j<3 && board[i][j+1] == 0){
						j++;
					}
					if(j != 3){
						for(int p=0; j1+p<4; p++){
							if(j+1+p<4){
								board[i1][j1+p] = board[i][j+1+p];
								//Move name LLs
								names[i1][j1+p].head = names[i][j+1+p].head;
								names[i1][j1+p].tail = names[i][j+1+p].tail;
							}
							else{
								board[i1][j1+p] = 0;
								//Move name LLs
								names[i1][j1+p].head = NULL;
								names[i1][j1+p].tail = NULL;
							}
						}
					}
				}
			}
		}
	}
	if(strcmp(dir, "RIGHT") == 0){
		//Do operation
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(board[i][j]!=0 && j!=3){
					i1 = i, j1 =j;
					j++;
					while(j<4 && board[i][j] == 0){
						j++;
					}
					if(j<4 && board[i][j]==board[i1][j1]){
						//printf("(%d,%d) and (%d,%d)\n", i1, j1, i, j);
						operate(op, i1, j1, i, j);
						j = j1;
					}
					else{
						j--;
					}
				}
			}
		}
		//Move all tiles to one side
		for(int i=0; i<4; i++){
			for(int j=3; j>=0; j--){
				if(board[i][j]==0){
					i1 = i, j1 = j;
					while(j>0 && board[i][j-1] == 0){
						j--;
					}
					if(j != 0){
						for(int p=0; j1-p>=0; p++){
							if(j-1-p>=0){
								board[i1][j1-p] = board[i][j-1-p];

								//Move name LLs
								names[i1][j1-p].head = names[i][j-1-p].head;
								names[i1][j1-p].tail = names[i][j-1-p].tail;
							}
							else{
								board[i1][j1-p] = 0;

								//Move name LLs
								names[i1][j1-p].head = NULL;
								names[i1][j1-p].tail = NULL;
							}
						}
					}
				}
			}
		}
	}
	int flag = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(board[i][j] == 0){
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
	}
	if(flag == 1)
		insert_random_tile();
	printf("Done!\n");
	print_board(flag);
}

void assign(int num, int x, int y){
	int flag = 0;
	if(num != board[x-1][y-1]){
		flag = 1;
	}
	board[x-1][y-1] = num;
	if(num == 0){
		names[x-1][y-1].head = NULL;
		names[x-1][y-1].tail = NULL;
	}
	printf("Done!\n");
	print_board(flag);
}

void operate(char op[100], int i1, int j1, int i, int j){
	if(strcmp(op, "ADD")==0){
		board[i1][j1] += board[i][j];
		board[i][j] = 0;
	}
	if(strcmp(op, "SUBTRACT")==0){
		board[i1][j1] -= board[i][j];
		board[i][j] = 0;
	}
	if(strcmp(op, "MULTIPLY")==0){
		board[i1][j1] *= board[i][j];
		board[i][j] = 0;
	}
	if(strcmp(op, "DIVIDE")==0){
		board[i1][j1] /= board[i][j];
		board[i][j] = 0;
	}
	if(names[i][j].head != NULL && names[i1][j1].head != NULL){
		(names[i1][j1].tail)->next = names[i][j].head;
		(names[i][j].head)->prev = names[i1][j1].tail;
		names[i1][j1].tail = names[i][j].tail;
		names[i][j].head = NULL;
		names[i][j].tail = NULL;
	}

	if(names[i][j].head != NULL && names[i1][j1].head == NULL){
		names[i1][j1].head = names[i][j].head;
		names[i1][j1].tail = names[i][j].tail;
		names[i][j].head = NULL;
		names[i][j].tail = NULL; 
	}

	if(board[i1][j1] == 0){
		names[i1][j1].head = NULL;
		names[i1][j1].tail = NULL;
	}

	//printf("operate works\n");
}

void insert_random_tile(){
	int row[4] = {0}, count = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(board[i][j] == 0){
				row[i]++;
			}
		}
	}

	for(int i=0; i<4; i++){
		if(row[i]>0){
			count++;
		}
	}

	if(count == 0)
		return;

	srand(time(0));
	int r = rand()%count;
	r += 1;

	count = 0;
	for(int i=0; i<4; i++){
		if(row[i]>0){
			count++;
			if(r == count){
				r = i;
				break;
			}
		}
	}

	int c = rand()%row[r];
	c += 1;

	count = 0;
	for(int j=0; j<4; j++){
		if(board[r][j] == 0){
			count++;
			if(count == c){
				c = j;
				break;
			}
		}
	}

	//printf("(%d,%d)\n", r, c);
	board[r][c] = 2*(rand()%2 + 1);
}

void print_tile(int x, int y){
	printf("The Value at (%d,%d) is: %d\n", x, y, board[x-1][y-1]);
	return;
}

void name_tile(int x, int y, char str[100]){
	x--;
	y--;
	if(board[x][y] == 0){
		printf("Cant name empty tile\n");
		fprintf(stderr, "-1\n");
		return;
	}

	//Look for name clash
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(board[i][j] != 0){
				node* new = names[i][j].head;
				while(new != NULL){
					if(strcmp(new->name, str) == 0){
						printf("Error: Name clashes with existing name\n");
						fprintf(stderr, "-1\n");
						return;
					}
					new = new->next;
				}			
			}
		}
	}
	
	if(names[x][y].head == NULL){
		node* new = malloc(sizeof(node));
		new->next = NULL;
		new->prev = NULL;
		for(int i=0; i<100; i++){
			if(str[i]=='\0'){
				(new->name)[i] = '\0';
				break; 
			}
			else{
				(new->name)[i] = str[i];
			}
		}
		names[x][y].tail = new;
		names[x][y].head = new;
	}
	else{
		node* new = malloc(sizeof(node));
		new->next = NULL;
		new->prev = names[x][y].tail;
		for(int i=0; i<100; i++){
			if(str[i]=='\0'){
				(new->name)[i] = '\0';
				break; 
			}
			else{
				(new->name)[i] = str[i];
			}
		}
		(names[x][y].tail)->next = new;
		names[x][y].tail = new;
	}

	printf("Done!\n");
	print_board(1);
}
