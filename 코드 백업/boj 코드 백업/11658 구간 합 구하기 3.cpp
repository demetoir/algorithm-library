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
#define INF 1234567890
#define INFLL 12345678912345678
#define MAX_N 1024

int board[MAX_N+1][MAX_N+1];
int n, m;
LL tree[MAX_N + 1][MAX_N + 1];
LL a, b, c, d;

LL getsum(int x, int y) {
	LL ret = 0;
	int temp = y;
	while (x > 0) {
		y = temp;
		while (y > 0) {
			ret += tree[x][y];
			y -= (y& -y);
		}
		x -= (x&-x);
	}
	return ret;
}

void update(int x, int y, LL diff) {
	int temp = y;
	while (x <= MAX_N) {
		y = temp;
		while (y <= MAX_N) {
			tree[x][y] += diff;
			y += (y&-y);
		}
		x += (x&-x);
	}
	return;
}

int  main() {
	si(n); si(m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			si(board[i][j]);
			update(i, j, board[i][j]);
		}
	}

	for (int iter = 0,w; iter < m; iter++) {
		si(w);
		if (w == 0) {
			int x, y, c;
			si(x);si(y);si(c);
			int diff = c - board[x][y];
			board[x][y] += diff;
			update(x, y, diff);
		}
		else {
			int x1, y1, x2, y2;
			si(x1); si(y1); si(x2); si(y2);
			x1--;
			y1--;
			a = getsum(x2, y2);
			b = getsum(x2, y1);
			c = getsum(x1, y2);
			d = getsum(x1, y1);

			printf("%lld\n", a - b - c + d);
		}
	}
	return 0;
}











