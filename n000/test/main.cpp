#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define		TAMAKAZU			3

int main()
{
	int f = 0;		// �����̏������͕K�{

	int y[TAMAKAZU];
	int c[TAMAKAZU];

	// y �������i�����̏������͕K�{�j
	for (int i = 0; i < TAMAKAZU; i++) {
		y[i] = 0;
	}

	while (1) {

		// �������擾
		if (_kbhit()) {

			// f �̒l�ɂ���Ĕz��ԍ����ς��܂�
			c[f] = _getch();
			y[f] = 20;

			// f �̒l��i�߂�
			f = (f + 1) % TAMAKAZU;
		}

		// ��ʂ��N���A
		printf("\x1b[2J");

		// �������o��
		for (int i = 0; i < TAMAKAZU; i++) {
			if (y[i] > 0) {
				printf("\x1b[%d;10H%c", y[i], c[i]);
				y[i]--;
			}
		}

		// ���x��
		Sleep(50);
	}

	return 0;
}