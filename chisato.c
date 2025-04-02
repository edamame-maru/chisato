#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void draw(int board[9][9], int komadai_sente[7], int komadai_gote[7], bool is_sente_turn) {
	/* 画面をクリア */
	for (int i = 0; i < 100; ++i) {
		putchar('\n');
	}

	/* 手番を表示 */
	if (is_sente_turn) {
		printf("%s", "手番：先手\n");
	} else {
		printf("%s", "手番：後手\n");
	}

	/* 先手の駒台を表示 */
	printf("%s", "先手駒台：");
	for (int i = 0; i < 7; ++i) {
		if (komadai_sente[i] > 0) {
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
					puts("ERR: invalid value in komadai_sente[7]");
					exit(1);
					break;
			}
			printf("%d ", komadai_sente[i]);
		}
	}
	printf("%s", "\n\n");

	/* 盤を表示 */
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

	/* 後手の駒台を表示 */
	printf("%s", "後手駒台：");
	for (int i = 0; i < 7; ++i) {
		if (komadai_gote[i] > 0) {
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
					puts("ERR: invalid value in komadai_gote[7]");
					exit(1);
					break;
			}
			printf("%d ", komadai_gote[i]);
		}
	}
	printf("%s", "\n\n");
}

int main() {
	int board[9][9] = {
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

	draw(board, komadai_sente, komadai_gote, true);
	exit(0);
}
