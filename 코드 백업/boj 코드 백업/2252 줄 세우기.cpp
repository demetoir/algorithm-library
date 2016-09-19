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
#define MAX_N 32000
int n, m;
vector <int> ans;
int level[MAX_N + 1];
vector <int> G[MAX_N+1];

queue<int>Q;
int  main() {
	si(n); si(m);
	for (int i = 0,a,b; i < m; i++) {
		si(a);si(b);
		level[b]+=1;
		G[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (level[i] == 0){
			ans.push_back(i);
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 0,next; i < G[cur].size(); i++) {
			next = G[cur][i];
			level[next] -= 1;
			if (level[next] == 0) {
				Q.push(next);
				ans.push_back(next);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}











