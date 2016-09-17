#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 100
#define si(a) scanf("%d",&(a))
#define MP pair<int,int>
#define LL long long
#define INF 9876543217654321

int board[MAX_N+1][MAX_N+1];
int check[MAX_N + 1][MAX_N + 1];


int n, m, k;
vector <int> ans;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int  dfs(int x, int y) {
	if (check[x][y])return 0;
	int ret = 1;
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];
		if (a < 0 || n <= a)continue;
		if (b < 0 || m <= b)continue;
		if (board[a][b] == 1) continue;
		ret += dfs(a, b);
	}
	return ret;
}


int main() {
	si(n); si(m); si(k);

	for (int iter = 0, a, b, c, d; iter < k; iter++) {
		si(a); si(b); si(c); si(d);
		for (int i = a; i < c; i++)
			for (int j = b; j < d; j++)
				board[j][i] = 1;
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == false && board[i][j] == 0) {
				int val = dfs(i, j);
				if (val>0)
					ans.push_back(val);
			}
		}
	}

	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}