
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

#define MAX_N 1000
int ice[MAX_N + 1][MAX_N + 1];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1 ,0 };
int delta[MAX_N + 1][MAX_N + 1];
int n, m;
int ans;
int icenum;

int check[300][300];
void dfs(int x, int y) {
	if (check[x][y]) return;

	check[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int a = x + dx[i];
		int b = y + dy[i];
		if (a < 1 || n-1 <= a)continue;
		if (b < 1 || m-1 <= b)continue;
		if (ice[a][b] == 0) continue;
		dfs(a, b);
	}
	return;
}

int iscracked() {
	memset(check, 0, sizeof(check));
	int ret = 0;
	for (int x = 1; x < n-1; x++) {
		for (int y = 1; y < m-1; y++) {
			if (ice[x][y] == 0 || check[x][y] == 1) continue;
			
			dfs(x, y);
			ret += 1;
		}
	}

	return ret;
}

int  main() {
	si(n); si(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			si(ice[i][j]);
			if (ice[i][j] > 0) icenum++;
		}
	}

	for (int x = 1; x < n-1; x++) {
		for (int y = 1; y < m-1; y++) {
			if (ice[x][y] == 0) continue;
			for (int i = 0; i < 4; i++) {
				int a = x + dx[i];
				int b = y + dy[i];
				if (a < 0 || n <= a)continue;
				if (b < 0 || m <= b)continue;
				if (ice[a][b] > 0) continue;
				delta[x][y] += 1;
			}
		}
	}


	vector <MP> remove;
	while (1) {
		remove.clear();
		for (int x = 1; x < n-1; x++) {
			for (int y = 1; y < m-1; y++) {
				if (ice[x][y] == 0 || delta[x][y]==0) continue;
				if (ice[x][y] <= delta[x][y]) {
					for (int i = 0; i < 4; i++) {
						int a = x + dx[i];
						int b = y + dy[i];
						if (a < 0 || n <= a)continue;
						if (b < 0 || m <= b)continue;
						if (ice[a][b] == 0) continue;
						remove.push_back(MP(a, b));
					}
					icenum -= 1;
					ice[x][y] = 0;
					delta[x][y] = 0;
				}
				else
					ice[x][y] -= delta[x][y];
			}
		}

		ans += 1;
		if (remove.size() == 0)continue;

		for (int i = 0; i < remove.size(); i++) {
			delta[remove[i].first][remove[i].second] += 1;
		}

		if (icenum == 0) {
			ans = 0;
			break;
		}
		if (iscracked()>1)
			break;

	}




	printf("%d\n", ans);
	return 0;
}











