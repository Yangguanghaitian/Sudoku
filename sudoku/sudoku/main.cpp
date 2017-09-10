#include"sudoku.h"
#include<stdio.h>

int main() {
	freopen("sudoku.txt", "w", stdout);
	sudoku sudo;
	sudo.getarea();
	cin >> sudo.n;
	int x = sudo.sudo[1][1] = (3 + 4) % 9 + 1;
	sudo.row[1][x] = 1;
	sudo.column[1][x] = 1;
	sudo.wrNum(1, 1);
	return 0;
}