#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
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

#define FOR(i,s,e) for (int i = s; i<e; i++)
//////////////////////////////////////////////////////////////////////////////////

#define MAX_N 1001
#define MAX_M 6001

int n,m;
int l[MAX_N];
//turn, start,end, player

int memo[2][MAX_N][MAX_N][2];


void find(int t, int x, int y) {

	if (x > y) return;
	if (x == y) {
		memo[t][x][y][t] = l[x];
		memo[t][x][y][1 - t] = 0;		
		return;
	}
	if (memo[t][x][y][0] > 0 || memo[t][x][y][1] > 0 )return;

	int ret = -INF;
	find(1-t, x+1, y);
	find(1-t, x, y - 1);
	int a = memo[1-t][x + 1][y][t] + l[x] - memo[1-t][x + 1][y][1-t];
	int b = memo[1-t][x][y - 1][t] + l[y] - memo[1-t][x][y - 1][1-t];
	
	if (a > b) {
		memo[t][x][y][t] = memo[1 - t][x + 1][y][t] + l[x];
		memo[t][x][y][1-t] = memo[1 - t][x + 1][y][1 - t];
	}
	else {
		memo[t][x][y][t] = memo[1 - t][x][y - 1][t] + l[y];
		memo[t][x][y][1-t] = memo[1 - t][x][y - 1][1-t];
	}
	//printf("t = %d x,y = %d,%d  =>> t=0 %d, t=1 %d\n", t, x, y, memo[t][x][y][0], memo[t][x][y][1]);
	return;
}
int main() {
	int test;
	si(test);
	for (; test > 0; test--) {
		memset(memo, 0, sizeof(memo));
		si(n);
		for (int i = 0; i < n; i++) 
			si(l[i]);
		
		find(0,0,n-1);
		int ans = memo[0][0][n - 1][0];
		printf("%d\n", ans);


	}


	return 0;
}

