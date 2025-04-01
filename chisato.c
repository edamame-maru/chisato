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
	putchar('\n');

	/* 盤を表示 */
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%d ", board[i][j]);
		}
		putchar('\n');
	}

	/* 後手の駒台を表示 */
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
	putchar('\n');
}

int main() {
	int board[9][9];
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			*(*(board + i) + j) = 0;
		}
	}

	int komadai_sente[7] = {6, 5, 4, 5, 0, 4, 0};
	int komadai_gote[7] = {0, 0, 0, 3, 4, 2, 3};


	draw(board, komadai_sente, komadai_gote, true);
	return 0;
}
