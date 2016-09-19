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

#define FOR(i,s,e) for (int i = s; i<e; i++)
//////////////////////////////////////////////////////////////////////////////////


#define MAX_N 1001
char str[MAX_N];
int n,m;
int ans = 0;
stack <int> s;
int board[MAX_N][MAX_N];
int toL[MAX_N][MAX_N];
int toR[MAX_N][MAX_N];

int main() {
	si(n);
	si(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			si(board[i][j]);
			toR[i][j] = -INF;
			toL[i][j] = -INF;
		}
	}
	
	toL[0][0] = board[0][0];
	toR[0][0] = board[0][0];

	for (int i = 1; i < m; i++) {
		toR[0][i] = toR[0][i - 1] + board[0][i];
		toL[0][i] = -INF;
	}

	for (int i = 1; i < n; i++) {
		//toL
		toL[i][m-1] = max(toR[i - 1][m-1], toL[i - 1][m-1]) + board[i][m-1];
		for (int j = m-2; j >= 0; j--) {
			toL[i][j] = max(toL[i][j], toL[i][j+1]);
			toL[i][j] = max(toL[i][j], toR[i-1][j]);
			toL[i][j] = max(toL[i][j], toL[i-1][j]);
			toL[i][j] += board[i][j];
		}

		//toR
		toR[i][0] = max(toR[i - 1][0], toL[i - 1][0]) + board[i][0];
		for (int j = 1; j < m; j++) {
			toR[i][j] = max(toR[i][j], toR[i][j - 1]);
			toR[i][j] = max(toR[i][j], toR[i - 1][j]);
			toR[i][j] = max(toR[i][j], toL[i - 1][j]);
			toR[i][j] += board[i][j];
		}

	}

	ans = max(toR[n - 1][m - 1], toL[n - 1][m - 1]);
	printf("%d\n", ans);
	return 0; 
}

