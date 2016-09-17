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
#define MAX_N 10000
vector <MP> G[MAX_N + 1];
vector <MP> tree[MAX_N + 1];
vector <int> childdist;
vector <int> rootdist;

int n, k;
int ans = 0;
vector <int> check;

int dfs(int cur) {

	int a = 0;
	int b = 0;
	int t;
	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i].first;
		int cost = G[cur][i].second;
		int val = dfs(next) +cost;

		if (a < val ){		
			t = a;
			a = val;
			val = t;
		}
		if (b < val) {
			b = val;			
		}
	}
	ans = max(a + b, ans);
	return a;
}

int  main() {
	si(n);
	for (int i = 0,a,b,c; i < n - 1; i++) {
		si(a); si(b); si(c);
		G[a].push_back(MP(b, c));
	}


	dfs(1);




	printf("%d\n", ans);

	return 0;


}











