#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void wipe(int n) {
	for (int i = 0; i < n; ++i) {
		putchar('\n');
	}
}

void draw_turn(bool is_sente_turn) {
	if (is_sente_turn) {
		printf("%s", "手番：▲先手\n");
	} else {
		printf("%s", "手番：△後手\n");
	}
}

void draw_komadai(int komadai[7], bool is_sente_owned) {
	if (is_sente_owned) {
		printf("%s", "先手駒台：");
	} else {
		printf("%s", "後手駒台：");
	}

	for (int i = 0; i < 7; ++i) {
		if (komadai[i] > 0) {
			switch (i) {
				case 0:
					printf("%s", "歩");
					break;
				case 1:
					printf("%s", "香");
					break;
				case 2:
					printf("%s", "桂");
					break;
				case 3:
					printf("%s", "銀");
					break;
				case 4:
					printf("%s", "金");
					break;
				case 5:
					printf("%s", "角");
					break;
				case 6:
					printf("%s", "飛");
					break;
				default:
					puts("ERR: invalid value in komadai[7]");
					exit(1);
					break;
			}
			printf("%d ", komadai[i]);
		}
	}
	printf("%s", "\n\n");
}

void draw_board(int board[9][9]) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			switch (board[i][j]) {
				case 0:
					printf("%s", " ・ ");
					break;
				case 1:
					printf("%s", "^歩 ");
					break;
				case 2:
					printf("%s", "^香 ");
					break;
				case 3:
					printf("%s", "^桂 ");
					break;
				case 4:
					printf("%s", "^銀 ");
					break;
				case 5:
					printf("%s", "^金 ");
					break;
				case 6:
					printf("%s", "^角 ");
					break;
				case 7:
					printf("%s", "^飛 ");
					break;
				case 8:
					printf("%s", "^玉 ");
					break;
				case -1:
					printf("%s", "v歩 ");
					break;
				case -2:
					printf("%s", "v香 ");
					break;
				case -3:
					printf("%s", "v桂 ");
					break;
				case -4:
					printf("%s", "v銀 ");
					break;
				case -5:
					printf("%s", "v金 ");
					break;
				case -6:
					printf("%s", "v角 ");
					break;
				case -7:
					printf("%s", "v飛 ");
					break;
				case -8:
					printf("%s", "v王 ");
					break;
				case 11:
					printf("%s", "^と ");
					break;
				case 12:
					printf("%s", "^杏 ");
					break;
				case 13:
					printf("%s", "^圭 ");
					break;
				case 14:
					printf("%s", "^全 ");
					break;
				case 16:
					printf("%s", "^馬 ");
					break;
				case 17:
					printf("%s", "^龍 ");
					break;
				case -11:
					printf("%s", "vと ");
					break;
				case -12:
					printf("%s", "v杏 ");
					break;
				case -13:
					printf("%s", "v圭 ");
					break;
				case -14:
					printf("%s", "v全 ");
					break;
				case -16:
					printf("%s", "v馬 ");
					break;
				case -17:
					printf("%s", "v龍 ");
					break;
				default:
					puts("ERR: invalid value in board[9][9]");
					exit(1);
					break;
			}
		}
		printf("%s", "\n\n");
	}
}

void move(int board[9][9], int start_x, int start_y, int dest_x, int dest_y) {
	board[dest_x][dest_y] = board[start_x][start_y];
	board[start_x][start_y] = 0;
}

int main() {
	/* 初期配置*/
	int my_board[9][9] = {
		{-2, -3, -4, -5, -8, -5, -4, -3, -2},
		{0, -7, 0, 0, 0, 0, 0, -6, 0},
		{-1, -1, -1, -1, -1, -1, -1, -1, -1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 6, 0, 0, 0, 0, 0, 7, 0},
		{2, 3, 4, 5, 8, 5, 4, 3, 2},
	};

	int komadai_sente[7];
	int komadai_gote[7];

	for (int i = 0; i < 7; ++i) {
		komadai_sente[i] = 0;
		komadai_gote[i] = 0;
	}

	wipe(100);
	draw_turn(true);
	draw_komadai(komadai_sente, true);
	draw_board(my_board);
	draw_komadai(komadai_gote, false);
	exit(0);
}
