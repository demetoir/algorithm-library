#include <stdio.h>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

#define si(a) scanf("%d",&a)
#define sc(c) scanf("%c",&c)

#define MAX_V 501
int v, c, d;
int ans;
vector <int> G[MAX_V];
int up[MAX_V], down[MAX_V];
void init() {
	for (int i = 0; i < MAX_V; i++) {
		G[i].clear();
	}
}
void makeG() {
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (i == j)continue;
			if (up[i] == down[j] || up[j] == down[i]) {
				G[i].push_back(j);
			}
		}
	}

}

vector<int> check;
vector<int> B;
bool dfs(int cur) {
	if (check[cur] == true) {
		return false;
	}
	check[cur] = true;

	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i];
		if (B[next] == -1 || dfs(B[next])) {
			B[next] = cur;
			return true;
		}
	}
	return false;
}

int match() {
	int maxflow = 0;

	B = vector<int>(MAX_V, -1);

	for (int i = 0; i < v; i++) {
		check = vector<int>(MAX_V, -1);
		if (dfs(i) == true) {
			maxflow++;
		}
	}
	return maxflow;
}
int main() {
	int testcase = 0;
	cin >> testcase;
	for (int test = 0; test < testcase; test++) {
		cin >> c>> d>> v;
		init();

		for (int i = 0; i < v; i++) {
			char ca,cb;
			int a,b;
			cin >> ca >> a >> cb >> b;
			up[i] = (ca - 'C') * 100 + a;
			down[i] = (cb - 'C') * 100 + b;
		}

		makeG();

		int val = match();
		ans = v - val/2;
		printf("%d\n", ans);
		

	}



	return 0;
}