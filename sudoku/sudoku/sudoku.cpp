#include "sudoku.h"

sudoku::sudoku()
{
	memset(row, 0, sizeof(row));
	memset(column, 0, sizeof(column));
	memset(sudo, 0, sizeof(sudo));
	memset(place, 0, sizeof(place));
	sum = 0;
	flag = false;

	/*for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int a = (i - 1) / 3;
			int b = (j - 1) / 3;
			area[i][j] = a + b * 3 + 1;
		}
	}*/
}


void sudoku::getarea()
{
    for (int i = 1; i <= 9; i++) {
         for (int j = 1; j <= 9; j++) {
              int a = (i - 1) / 3;
              int b = (j - 1) / 3;
              area[i][j] = a + b * 3 + 1;
          }
    }
}

void sudoku::wrNum(int x, int y)
{
	if (flag)return;
	if (x < 9 || y < 9) {
		int a = x;
		int b = y + 1;
		if (b > 9) {
			b = 1;
			a++;
		}
		int p = area[a][b];
		int t = rand() % 9 + 1;
		int r = t;
		while (1) {
			if (!row[a][r] && !column[b][r] && !place[p][r]) {
				sudo[a][b] = r, row[a][r] = 1, column[b][r] = 1, place[p][r] = 1;
				wrNum(a, b);
				sudo[a][b] = 0, row[a][r] = 0, column[b][r] = 0, place[p][r] = 0;
			}
			r++;
			if (r == 10)r = 1;
			if (t == r)break;
		}
	}
	else {
		sum++;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << sudo[i][j];
				if (j < 9)cout << " ";
			}
			cout << endl;
		}
		if (sum != n)cout << endl;
		if (sum == n)flag = true;
	}
}