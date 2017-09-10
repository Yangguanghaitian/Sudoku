#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>

using namespace std;
class sudoku {
public:
	bool flag;
	int sum, n;
	int sudo[10][10];
	int row[10][10];
	int column[10][10];
	int area[10][10];
	int place[10][10];
	sudoku();
	void getarea();
	void wrNum(int x, int y);
};