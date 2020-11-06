/*
#include <stdio.h>
#include <conio.h>
#include <windows.h>

//----------------------------------------------------------------------------------------------------------------------
void set_cursor_disp(bool onoff) {
	HANDLE hOut;
	CONSOLE_CURSOR_INFO cci;

	// 出力用ハンドルの取得
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// CONSOLE_CURSOR_INFO構造体の現在の状態を取得する
	GetConsoleCursorInfo(hOut, &cci);

	// メンバ変数であるbVisibleがカーソルの表示・非表示を制御する変数なので、これをFALSEにする事でカーソルを非表示にできる
	cci.bVisible = onoff;

	// 変更した構造体情報をコンソールWindowにセットする
	SetConsoleCursorInfo(hOut, &cci);
}

//----------------------------------------------------------------------------------------------------------------------
#define		__USE_SLOT			0

#if __USE_SLOT

long z;
char j[] = "000102101112202122001020011121021222001122021120", s[][17] = { "\x1b[>5h","回:+ 止:1~3 終:/","  " };
int g, a, b, e[28][3], o = 9, m[3], n[8], Y[3], c = 0;

int L(int a) {
	return a -= a > 27 ? 28 : 0;
}

int R(int a, int b, int c) {
	return e[L(j[a + b] - 48 + Y
		[j[a + c] - 48] / 3)][j[a + c] - 48];
}

void M(int a) {
	printf("\x1b[%dm", a);
}

void S(int a) {
	printf("%s", s[a]);
}

void H(int y, int x) {
	printf("\x1b[%d;%dH", y, x);
}

int slot() {
	S(0);H(6, 33);S(1);for (;;) {
		g = _kbhit() ? _getch() : 0;H(20, 37);printf("%5d", o);
		if (c > 4)c = 0;for (a = 0;a < 8;a++) {
			if (c < 1) {
				m[a / 3] = 2;n[a] = 0;Y[a / 3] = 0;for (b = 0;b < 84;b++)
					e[b / 3][b % 3] = rand() % 7;
			}if (c == 1) { m[a / 3] = 0;if (a > 6)c = 2; }if (c > 1 && a < 3) {
				b = Y[a];if (m[a
				] < 1 && g == 49 + a)m[a] = 1;if (m[a] == 1 && b % 3 == 0) { m[a] = 2;c++; }if (m[a] < 2)Y[a] = b == 83 ? 0 : b + 1
					;
			}
		}if (c < 1 && g == 43) { c = 1;o--; }if (g == 47 || o < 0)return(0);if (c > 4) {
			b = 0;for (a = 0;a < 43;a += 6)
				if (R(a, 0, 1) == R(a, 2, 3) && R(a, 0, 1) == R(a, 4, 5)) { b++;n[a / 6] = 1; }o += b * b * b;
		}if (c > 1) {
			for
				(a = 0;a < 81;a++) {
				H(17 - a / 9, 32 + a % 9 * 2);for (b = 0;b < 47;b += 2)if (n[b / 6] == 1 && j[b] - 48 == a / 9
					/ 3 && j[b + 1] - 48 == a % 9 / 3)M(5);M(e[L((Y[a % 9 / 3] + a / 9) / 3)][a % 9 / 3] + 41);S(2);M(0);
			}
		}for (
			z = 0;z < 2000000;z++);
	}
}

#endif

//----------------------------------------------------------------------------------------------------------------------
int main() {

	char c;
	char* p;
	p = &c;
	*p = 97;
	printf("%c\n", c);

#if 0
	char sss[10];
	scanf_s("%9s", sss, 10);
	printf("%s\n", sss);
	scanf_s("%s", sss, 10);
	printf("%s\n", sss);
#endif

#if 0	//-------------------------------------------------------
	int aaa;
	scanf_s("%d", &aaa);
	printf("%d\n", aaa);

	char sss[10];
	scanf_s("%s", sss, 10);
	printf("%s\n", sss);
#endif

#if 0	//-------------------------------------------------------
	char mojiretu[4];
	mojiretu[0] = 'a';         // 97 = a
	mojiretu[1] = 'b';         // 97 = b
	mojiretu[2] = 'c';         // 97 = c
	mojiretu[3] = '\0';        // 0 = null コード。これが無いと実行時エラーになります。
	printf("%s\n", mojiretu);  // abc と出力されます。

	mojiretu[0] = 97;          // 97 = a
	mojiretu[1] = 98;          // 97 = b
	mojiretu[2] = 99;          // 97 = c
	mojiretu[3] = 0;           // 0 = null コード。これが無いと実行時エラーになります。
	printf("%s\n", mojiretu);  // abc と出力されます。
#endif

#if 0	//-------------------------------------------------------
	char s[8];
	scanf_s("%s", s, 8);
	rewind(stdin);
	//	scanf_s("%s%*[^\n]", s, 8);
	printf("%s\n", s);

	printf("----------\n");

	gets_s(s, 8);
	printf("%s\n", s);

	printf("----------\n");

	char buf[16];

	puts("何か入力してください。");
	gets_s(buf, sizeof(buf));
	puts(buf);
#endif

	//-------------------------------------------------------
	set_cursor_disp(false);
	//	printf("\x1b[>5h");

#if 0
	int a;
	printf("Hit any key...xxx\n");
	while (1) {

		if (_kbhit()) {

			//			a = 97;
			a = _getch();

			if (a == 0x1b) {		// ESC
				break;
			}

			printf("\r");			// 行頭へ移動

			if (a == 0xe0) {
				a = _getch();
				switch (a) {
				case 0x48:	printf("↑");	break;
				case 0x50:	printf("↓");	break;
				case 0x4B:	printf("←");	break;
				case 0x4D:	printf("→");	break;
				default:	printf("？");	break;
				}
			}
			else {
				printf("%2x = %3d = %c", a, a, a);
			}

			printf("\x1b[K");		// 行末までクリア
		}
	}
#endif

	//-------------------------------------------------------
#if __USE_SLOT
	slot();
#endif

	//-------------------------------------------------------
	set_cursor_disp(true);
	//	printf("\x1b[>5l");

	return (0);
}








#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
	while (1) {
		if (_kbhit()) {
			int c = _getch();
			int x = rand() % 10 + 1;
			printf("\x1b[3;%dH", x);
			printf("%c", c);
		}
	}
	return 0;
}


			rewind(stdin);
			fflush(stdin);
			while (_kbhit()) { _getch(); }







*/
