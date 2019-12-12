#include <stdio.h>
//#include <Windows.h>
//#include <conio.h>

int board[4][4];
int score = 0;
int game_check = 0;
int win_check = 0;

void draw();
void rotate();
void move_left_with_merge();
void move_with_merge(char);
void create_num();
void create_num_2();
void end_game(void);
void win_game();
void make_map();


int main() {

	printf("2048 Start!\n");
	//printf("PRESS ANY KEY\n"); getch();
	//system("cls");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			board[i][j] = 0;
	}

	
	make_map();
	char option;

	while (scanf("%c", &option) != EOF) {

		move_with_merge(option);
		draw();
		if (game_check == 1) {
			system("cls");
			printf("Game Over\n");
			printf("Score: %d \n ", score);
			return 0;
		}
		win_game();
		if (win_check == 1) {
			printf("Game Win\n");
			printf("Score: %d \n ", score);
		}

	}
	/*while (1) {

		option = _getch();
		move_with_merge(option);
		//system("cls");
		draw();
		if (game_check == 1) {
			system("cls");
			printf("Game Over\n");
			printf("Score: %d \n ", score);
			return 0;
		}
		win_game();
		if (win_check == 1) {
			printf("Game Win\n");
			printf("Score: %d \n ", score);
		}


	}*/
	
 }

void draw() {
	
	for (int i = 0; i < 4; i++) {

			printf("-------------------------\n");
		printf("|     |     |     |     |\n");
			printf("|%5d|%5d|%5d|%5d|\n",board[i][0],board[i][1],board[i][2],board[i][3]); printf("\n");
			printf("|     |     |     |     |\n");
		

	}
	printf("-------------------------\n");
	printf("score: %d\n", score);
	

}

void rotate() {

	int temp[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = board[j][3 - i];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = temp[i][j];
		}
	}

}

void move_left_with_merge() {


	int temp_array[4][4] = { 0 };
	int new_array[4][4] = { 0 };
	int check= 0;
	

	for (int i = 0; i < 4; i++) {
		int loc = 0;
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != 0) {
				temp_array[i][loc] = board[i][j];
				loc++;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		int loc = 0;
		for (int j = 0; j < 4; j++) {
			if (j<3&&temp_array[i][j] == temp_array[i][j + 1]) {
				new_array[i][loc] = temp_array[i][j] + temp_array[i][j + 1];
				score += new_array[i][loc];
				loc++;
				j++;
				
			}
			else {

				new_array[i][loc] = temp_array[i][j];
				loc++;
				
					
			}

		}

	}


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != new_array[i][j]) {
				check = 1;
				
			}
			board[i][j] = new_array[i][j];
		}
	}
	if (check == 1) {
		create_num();

	}
	else {

		end_game();
	}
	

}

void move_with_merge(char option) {
	switch (option) {
	case 'w':
		rotate();
		move_left_with_merge();
		rotate();
		rotate();
		rotate();
		break;
	case 'a':
		move_left_with_merge();
		break;
	case 's':
		rotate();
		rotate();
		rotate();
		move_left_with_merge();
		rotate();
		break;
	case 'd':
		rotate();
		rotate();
		move_left_with_merge();
		rotate();
		rotate();
		break;
	}
}

void create_num() {

	int num = 0;
	int r,x,y;
	int random[2][16] = { 0 };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				random[0][num] = i;
				random[1][num] = j;
				num++;
			}
		}
	}

	if (num > 0) {
		r = rand() % num;
		x = random[0][r];
		y = random[1][r];
		board[x][y] = (rand() % 2+1)*2;
		 
	}
}
void create_num_2() {
	int num = 0;
	int r, x, y;
	int random[2][16] = { 0 };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				random[0][num] = i;
				random[1][num] = j;
				num++;
			}
		}
	}

	if (num > 0) {
		r = rand() % num;
		x = random[0][r];
		y = random[1][r];
		board[x][y] = 2;

	}

}

void end_game() {
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != 0) {
				game_check = 0;
				return;
			}
		}
	}
	game_check=1;
	
}

void win_game(){

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] >= 2048) {
				win_check = 1;
				return;
			}
			
		
		}
	}
	
}
void make_map() {
	create_num();
	create_num();
	for (int i = 0; i < 4; i++) {

		printf("-------------------------\n");
		printf("|     |     |     |     |\n");
		printf("|%5d|%5d|%5d|%5d|\n", board[i][0], board[i][1], board[i][2], board[i][3]); printf("\n");
		printf("|     |     |     |     |\n");


	}
	printf("-------------------------\n");
	printf("score: %d\n", score);
	
	
}
