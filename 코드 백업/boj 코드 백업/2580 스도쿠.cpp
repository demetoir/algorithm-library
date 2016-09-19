#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

#define LL long long
#define MP pair < int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define sS(a) scanf("%s",a)
#define INF 1234567890
#define INFLL 12345678912345678

//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1000
vector <int> line;

int sudoku[10][10];
int ans;
vector <int> candidate;


void find(int x, int y) {
	if (y == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", sudoku[i][j]);
			printf("\n");
		}
		ans = 1;
		return;
	}
		
	if (sudoku[x][y] > 0) {
		find((x + 1) % 9, y + (x + 1) / 9);
		return;
	}
			
	int candidate[10];
	memset(candidate, 0, sizeof(candidate));
	for (int k = 0; k < 9; k++) {
		candidate[sudoku[k][y]] += 1;
	}
	for (int k = 0; k < 9; k++) {
		candidate[sudoku[x][k]] += 1;
	}
	for (int i = x - x % 3; i < x - x % 3 + 3; i++) {
		for (int j = y - y % 3; j < y - y % 3 + 3; j++) {
			candidate[sudoku[i][j]] += 1;
		}
	}

	for (int k = 1; k <= 9; k++) {
		if (candidate[k] > 0)continue;	
		sudoku[x][y] = k;
		find((x + 1) % 9, y + (x + 1) / 9);		
		if (ans) return;
	}
	sudoku[x][y] = 0;

	return;
}


int  main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			si(sudoku[i][j]);
		}
	}
	//printf("\n");

	find(0,0);


	return 0;


}











