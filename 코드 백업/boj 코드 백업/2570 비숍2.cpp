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
#define MAX_N 101

LL ans;
int n,m;

int board[MAX_N][MAX_N];
vector <int> G[10001];
int check[10001];
int Anum[MAX_N][MAX_N];
int Bnum[MAX_N][MAX_N];
int back[10001];
int vsize = 0;


bool dfs(int cur = 0 ) {
	if (check[cur] > 0)return false;
	check[cur] = 1;
	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i];
		if (back[next] == 0 || dfs(back[next]) == true) {
			back[next] = cur;
			return true;
		}
	}
	return false;
}

int matching() {
	int maxmatch = 0;
	memset(back, 0, sizeof(back));
	for (int i = 1; i < vsize; i++) {
		memset(check, 0, sizeof(check));
		if (dfs(i) == true)
			maxmatch += 1;
	}

	return maxmatch;
}


void makeG() {
	int Acount = 1;
	int Bcount = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) continue;

			if (Anum[i][j] == 0) {
				Anum[i][j] = Acount;
				Acount++;
			}
			if (Bnum[i][j] == 0) {
				Bnum[i][j] = Bcount;
				Bcount++;
			}

			for (int d = 0, a, b; d < n; d++) {
				a = i + d;
				b = j + d;
				if (board[a][b] == 1)break;
				if (a < 0 OR n <= a)continue;
				if (b < 0 OR n <= b)continue;
				Anum[a][b] = Anum[i][j];
			}

			for (int d = 0, a, b; d < n; d++) {
				a = i + d;
				b = j - d;
				if (board[a][b] == 1) break;
				if (a < 0 OR n <= a)continue;
				if (b < 0 OR n <= b)continue;
				Bnum[a][b] = Bnum[i][j];
			}
		}
	}
	vsize = Acount;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a = Anum[i][j];
			int b = Bnum[i][j];
			if (board[i][j] == 0)
				G[a].push_back(b);
		}
	}

}

int main() {
	si(n);
	si(m);
	for (int i = 0,a,b; i < m; i++) {
		si(a);  si(b);
		board[a-1][b-1] = 1;
	}

	makeG();
	ans = matching();

	printf("%lld\n", ans);

	return 0;
}       