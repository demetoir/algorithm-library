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
#define MAX_N 100

int dist[MAX_N + 1][MAX_N + 1];
int board[MAX_N + 1][MAX_N + 1];
int n, m;
int check[MAX_N + 1];
int ans;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
struct TP {
	TP(int x, int y) { a = x; b = y; }
	int a, b;
};
queue<TP> Q;

int  main() {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			dist[i][j] = INF;			
		}
	}

	si(m); si(n);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = getchar() - '0';
		}
		getchar();
	}


	dist[0][0] = 0;
	Q.push(TP(0, 0));
	while (!Q.empty()) {
		int x = Q.front().a;
		int y = Q.front().b;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			if (a < 0 || n <= a)continue;
			if (b < 0 || m <= b)continue;

			if (board[a][b] == 0) {
				if (dist[a][b] > dist[x][y]) {
					dist[a][b] = dist[x][y];
					Q.push(TP(a, b));
				}
			}
			else {
				if (dist[a][b] > dist[x][y] + 1) {
					dist[a][b] = dist[x][y] + 1;
					Q.push(TP(a, b));
				}
			}
		}
	}

	ans = dist[n - 1][m - 1];
	if (ans == INF)ans = 0;
	printf("%d\n", ans);
	return 0;
}











