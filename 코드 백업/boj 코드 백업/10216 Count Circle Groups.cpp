#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define MP pair<int,int>
#define INF (1<<31 -1)
#define LLINF ( (((LL)1) <<62)  -1)
#define AND &&
#define OR ||

//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 5000

int n,m;
vector <int> G[MAX_N];
int check[MAX_N];
int X[MAX_N];
int Y[MAX_N];
int R[MAX_N];

void makeG() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			int dx = (X[i] - X[j]);
			int dy = Y[i] - Y[j];
			int d = dx*dx +  dy*dy;
			int rr = (R[i]+R[j])*(R[i] + R[j]);
			if (d <= rr) {
				G[i].push_back(j);
				G[j].push_back(i);
			}
		}
	}
	return;
}

void dfs(int cur) {
	if (check[cur] == 1)return;
	check[cur] = 1;
	for (int i = 0; i < G[cur].size(); i++) 
		dfs(G[cur][i]);

	return;
}

int main() {
	int test;
	si(test);
	for (; test > 0; test--) {
		si(n);
		for (int i = 0; i < n; i++) {
			si(X[i]); si(Y[i]); si(R[i]);
			G[i].clear();
		}
		
		makeG();
		memset(check, 0, sizeof(check));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (check[i] == 0) {
				dfs(i);
				ans += 1;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}       