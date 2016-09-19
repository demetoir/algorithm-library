#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


#define si(a) scanf("%d",&(a))
#define MAX_N 1000
#define MAX(a,b) ( (a)>(b) ? (a):(b) )

int n;
int ans = 0;
int memo[MAX_N+1][MAX_N+1];

int STR[100], INT[100], PNT[100];

int vertical[MAX_N+10][MAX_N+10];
int horizon[MAX_N+10][MAX_N+10];
int pntmap[MAX_N+10][MAX_N+10];
int number[MAX_N + 10][MAX_N + 10];

void init() {
	for (int i = 0; i <= MAX_N; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			memo[i][j] = -1;
		}
	}
}

int main() {
	si(n);
	for (int i = 0, a, b, c; i < n; i++) {
		si(a);si(b);si(c);
		pntmap[a][b] +=c;
		number[a][b] += 1;
		STR[i] = a;
		INT[i] = b;
		PNT[i] = c;
	}
	init();

	//vertical
	for (int i = 0; i <= MAX_N; i++) {
		vertical[MAX_N][i] = pntmap[MAX_N][i];
		for (int j = MAX_N - 1; j >= 0; j--) {
			vertical[j][i] = vertical[j + 1][i] + pntmap[j][i];
		}
	}
	//horizon
	for (int i = 0; i <= MAX_N; i++) {
		horizon[i][MAX_N] = pntmap[i][MAX_N];
		for (int j = MAX_N - 1; j >= 0; j--) {
			horizon[i][j] = horizon[i][j + 1] + pntmap[i][j];
		}
	}

	//number 
	for (int i = 1000; i >= 0; i--) {
		number[1000][i] += number[1000][i + 1];		
		number[i][1000] += number[i + 1][1000];
	}
	for (int i = MAX_N-1 ; i >=1; i--) {		
		for (int j = MAX_N - 1; j >= 1; j--) {
			number[i][j] += number[i + 1][j] + number[i][j + 1] - number[i + 1][j + 1];
		}
	}
	for (int i = MAX_N; i >= 0; i--) {
		for (int j = MAX_N; j >= 0; j--) {
			number[i][j] = n - number[i][j];
		}
	}

	memo[1][1] =  vertical[1][1] + horizon[1][1] - pntmap[1][1];
	
	//queue<pair<int, int> > Q;
	//Q.push(make_pair(1, 1));
	//while (!Q.empty()) {
	//	int x, y;
	//	x = Q.front().first;
	//	y = Q.front().second;
	//	Q.pop();
	//	if (memo[x][y] == 0) continue;

	//	if ( (y + 1 <= MAX_N)  &&
	//		(memo[x][y + 1] < memo[x][y] - 1 + vertical[x+1][y + 1])) {
	//		Q.push(make_pair(x, y+1));
	//		memo[x][y + 1] = memo[x][y] - 1 + vertical[x + 1][y + 1];
	//	}

	//	if ((x + 1 <= MAX_N) &&
	//		(memo[x + 1][y] < memo[x][y] - 1 + horizon[x + 1][y + 1])) {
	//		Q.push(make_pair(x + 1, y));
	//		memo[x + 1][y] = memo[x][y] - 1 + horizon[x + 1][y + 1];
	//	}
	//}

	for (int i = 2; i <= MAX_N; i++) {
		if (memo[1][i - 1] > 0)
			memo[1][i] = MAX(-1, memo[1][i - 1] + vertical[1 + 1][i] - 1);

		if (memo[i-1][1] > 0)
			memo[i][1] = MAX(-1, memo[i - 1][1] + horizon[i][1 + 1] - 1);
	}
	for (int i = 2; i <= MAX_N; i++) {
		for (int j = 2; j <= MAX_N; j++) {
			if (memo[i][j-1] > 0)
				memo[i][j] = MAX(memo[i][j], memo[i][j - 1] + vertical[i + 1][j] - 1);
			if (memo[i-1][j] >0)
				memo[i][j] = MAX(memo[i][j], memo[i - 1][j] + horizon[i][j + 1] - 1);
		}
	}

	for (int i = 0; i <= MAX_N; i++) {
		for (int j = 0; j <= MAX_N; j++) {
			if (memo[i][j] > 0) {
				ans = MAX(ans, number[i+1][j+1]);
			}
		}
	}	

	printf("%d", ans);
	return 0;
}