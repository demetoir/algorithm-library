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
#define MP pair <int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define sS(a) scanf("%s",a)
#define INF 1234567890
#define INFLL 12345678912345678

////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1000

int n, m, ans;
int pre[MAX_N + 1], in[MAX_N + 1], post[MAX_N + 1];
int idx = 0;
int leftchild[MAX_N + 1], rightchild[MAX_N + 1];

int dfs1(int a, int b) {
	if (idx >= n || idx < 0 || a>b) {
		idx -= 1;
		return 0;

	}
	if (a == b) return in[a];

	int cur = pre[idx];
	for (int i = a; i <= b; i++) {
		if (in[i] == cur) {
			idx++;
			leftchild[cur] = dfs1(a, i - 1);

			idx++;
			rightchild[cur] = dfs1(i + 1, b);

		}
	}
	return cur;
}

void dfs(int cur) {

	if (leftchild[cur] != 0)dfs(leftchild[cur]);

	if (rightchild[cur] != 0)dfs(rightchild[cur]);

	printf("%d ", cur);
}
int  main() {
	int testcase;
	for (si(testcase); testcase > 0; testcase--) {
		si(n);
		memset(leftchild, 0, sizeof(leftchild));
		memset(rightchild, 0, sizeof(rightchild));
		idx = 0;
		for (int i = 0; i < n; i++) {
			si(pre[i]);

		}
		for (int i = 0; i < n; i++) {
			si(in[i]);
		}

		int root = dfs1(0, n - 1);

		dfs(root);
		printf("\n");

	}
	return 0;
}










