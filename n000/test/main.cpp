#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
	int f = 0;		// ★この初期化は必須

	int y0 = 0;		// ★この初期化は必須
	int y1 = 0;		// ★この初期化は必須
	int y2 = 0;		// ★この初期化は必須

	int c0, c1, c2;

	while (1) {

		// 文字を取得
		if (_kbhit()) {

			// f の値によって変数を使い分ける
			if (f == 0) {
				c0 = _getch();
				y0 = 20;
			}
			else if (f == 1) {
				c1 = _getch();
				y1 = 20;
			}
			else {	// f == 2
				c2 = _getch();
				y2 = 20;
			}

			// f の値を進める（0 1 2 0 1 2 0 1 2 …を繰り返します）
			f = (f + 1) % 3;
		}

		printf("\x1b[2J");	// 画面をクリア

		if (y0 > 0) {		// 文字を出力０
			printf("\x1b[%d;10H%c", y0, c0);
			y0--;
		}

		if (y1 > 0) {		// 文字を出力１
			printf("\x1b[%d;10H%c", y1, c1);
			y1--;
		}

		if (y2 > 0) {		// 文字を出力２
			printf("\x1b[%d;10H%c", y2, c2);
			y2--;
		}

		Sleep(50);			// お休み
	}

	return 0;
}