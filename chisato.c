#include <stdio.h>

int draw(int* board, int* komadai_sente, int* komadai_sente) {
	/* 先手の駒台を表示 */
	for (int i = 0; i < 7; ++i) {
		printf("%d ", *(komadai_sente + i));
	}
	putchar('\n');

	/* 盤を表示 */
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			printf("%d", *(*(board + i) + j));
		}
	}

	/* 後手の駒台を表示 */
	for (int i = 0; i < 7; ++i) {
		printf("%d ", *(komadai_gote + i));
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
		*(komadai_sente + i) = 0;
		*(komadai_gote + i) = 0;
	}

	draw(board, komadai_sente, komadai_gote);
	return 0;
}
