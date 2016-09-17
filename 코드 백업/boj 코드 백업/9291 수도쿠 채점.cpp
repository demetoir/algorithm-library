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

////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1000

int sudoku[10][10];
int ans;
vector <MP> hole;
bool check() {
	int candidate[10];
	for (int i = 0; i < 9; i++) {
		memset(candidate, 0, sizeof(candidate));
		for (int k = 0; k < 9; k++) {
			int val = sudoku[k][i];
			if (val == 0) continue;
			candidate[val] += 1;
			if (candidate[val] > 1)
				return false;
		}
	}

	for (int i = 0; i < 9; i++) {
		memset(candidate, 0, sizeof(candidate));
		for (int k = 0; k < 9; k++) {
			int val = sudoku[i][k];
			if (val == 0) continue;
			candidate[val] += 1;
			if (candidate[val] > 1)
				return false;
		}
	}

	for (int x = 0; x < 7; x += 3) {
		for (int y = 0; y < 7; y += 3) {

			memset(candidate, 0, sizeof(candidate));
			for (int i = x - x % 3; i < x - x % 3 + 3; i++) {
				for (int j = y - y % 3; j < y - y % 3 + 3; j++) {
					int val = sudoku[i][j];
					if (val == 0) continue;
					candidate[val] += 1;
					if (candidate[val] > 1)
						return false;
				}
			}
		}
	}
	return true;
}

void find(int index) {
	if (index == 5) {
		if (check() == false) return;

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d", sudoku[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		ans = 1;
		return;
	}

	if (check() == false)return;

	int a = hole[index].first;
	int b = hole[index].second;
	for (int i = 1; i <= 9; i++) {
		sudoku[a][b] = i;
		if (check() == true) {
			find(index + 1);
		}
		if (ans == 1)
			return;
	}

}


int  main() {
	int testcase = 0;
	si(testcase);
	for (int test = 0; test < testcase; test++) {
		hole.clear();
		ans = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0,val; j < 9; j++) {
				si(val);
				sudoku[i][j] = val;
			}
		}
		if (check() == true) {
			printf("Case %d: CORRECT\n",test+1);
		}
		else {
			printf("Case %d: INCORRECT\n",test+1);

		}
	}
	return 0;

}











