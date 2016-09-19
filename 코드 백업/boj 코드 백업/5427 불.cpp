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
#define LLINF (((LL)1)<<63  -1)
#define AND &&
#define OR ||

//////////////////////////////////////////////////////////////////////////////////

//// 5427 탈출.cpp

#define MAX_N 1001
char board[MAX_N][MAX_N];
char str[MAX_N];
int r, c;
int firetime[MAX_N][MAX_N];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector <MP> firestart;
int ans;
int dist[MAX_N][MAX_N];
int endx, endy;
int startx, starty;


void fill() {
	queue<MP> q;
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			firetime[i][j] = INF;
		}
	}

	for (int i = 0; i < firestart.size(); i++) {
		int x = firestart[i].first;
		int y = firestart[i].second;
		q.push(MP(x,y));
		firetime[x][y] = 0;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int time = firetime[x][y];

		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			if (a < 0 OR r<=a)continue;
			if (b < 0 OR c<=b)continue;

			if(board[a][b] == '#' || board[a][b] =='@') continue;

			if (firetime[a][b] > time + 1) {
				q.push(MP(a, b));
				firetime[a][b] = time + 1;
			}
		}
	}
}

int find() {
	queue<MP> q;
	int ret = INF;

	for (int i = 0; i < MAX_N; i++) 
		for (int j = 0; j < MAX_N; j++) 
			dist[i][j] = INF;	

	q.push(MP(startx,starty));
	dist[startx][starty] = 0;	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int cost = dist[x][y];

		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			if (a < 0 OR r <= a OR b < 0 OR c <= b) {
				ret = min(ret, cost + 1);
				continue;
			}	
			if (board[a][b] == '#' || firetime[a][b] <= cost + 1 ) continue;

			if (dist[a][b] > cost + 1) {
				q.push(MP(a, b));
				dist[a][b] = cost + 1;
			}
		}
	}

	return ret;
}


int main() {
	int test;
	si(test);
	for (; test > 0; test--) {
		si(c);
		si(r);
		firestart.clear();
	
		for (int i = 0; i < r; i++) {
			scanf("%s", str);
			for (int j = 0; j < c; j++) {
				board[i][j] = str[j];
				if (board[i][j] == '*')
					firestart.push_back(MP(i, j));
				if (board[i][j] == '@') {
					startx = i;
					starty = j;
				}

			}
		}

		fill();
		ans = find();

		if (ans == INF)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}




