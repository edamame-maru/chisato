#include <stdio.h>
#include <stdbool.h>

void draw(int board[9][9], int komadai_sente[7], int komadai_gote[7], bool is_sente_turn) {
	/* 画面をクリア */
	for (int i = 0; i < 100; ++i) {
		putchar('\n');
	}

	/* 手番を表示 */
	if (is_sente_turn) {
		puts("手番：先手");
	} else {
		puts("手番：後手");
	}

	/* 先手の駒台を表示 */
	for (int i = 0; i < 7; ++i) {
		printf("%d ", komadai_sente[i]);
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
		printf("%d ", komadai_gote[i]);
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

	int komadai_sente[7];
	int komadai_gote[7];

	for (int i = 0; i < 7; ++i) {
		komadai_sente[i] = 0;
		komadai_gote[i] = 0;
	}

	draw(board, komadai_sente, komadai_gote, true);
	return 0;
}
