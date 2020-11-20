#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define		TAMAKAZU			3

int main()
{
	int f = 0;		// ★この初期化は必須

	int y[TAMAKAZU];
	int c[TAMAKAZU];

	// y 初期化（★この初期化は必須）
	for (int i = 0; i < TAMAKAZU; i++) {
		y[i] = 0;
	}

	while (1) {

		// 文字を取得
		if (_kbhit()) {

			// f の値によって配列番号が変わります
			c[f] = _getch();
			y[f] = 20;

			// f の値を進める
			f = (f + 1) % TAMAKAZU;
		}

		// 画面をクリア
		printf("\x1b[2J");

		// 文字を出力
		for (int i = 0; i < TAMAKAZU; i++) {
			if (y[i] > 0) {
				printf("\x1b[%d;10H%c", y[i], c[i]);
				y[i]--;
			}
		}

		// お休み
		Sleep(50);
	}

	return 0;
}