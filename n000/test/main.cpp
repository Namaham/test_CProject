#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main()
{
	int f = 0;		// �����̏������͕K�{

	int y0 = 0;		// �����̏������͕K�{
	int y1 = 0;		// �����̏������͕K�{
	int y2 = 0;		// �����̏������͕K�{

	int c0, c1, c2;

	while (1) {

		// �������擾
		if (_kbhit()) {

			// f �̒l�ɂ���ĕϐ����g��������
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

			// f �̒l��i�߂�i0 1 2 0 1 2 0 1 2 �c���J��Ԃ��܂��j
			f = (f + 1) % 3;
		}

		printf("\x1b[2J");	// ��ʂ��N���A

		if (y0 > 0) {		// �������o�͂O
			printf("\x1b[%d;10H%c", y0, c0);
			y0--;
		}

		if (y1 > 0) {		// �������o�͂P
			printf("\x1b[%d;10H%c", y1, c1);
			y1--;
		}

		if (y2 > 0) {		// �������o�͂Q
			printf("\x1b[%d;10H%c", y2, c2);
			y2--;
		}

		Sleep(50);			// ���x��
	}

	return 0;
}