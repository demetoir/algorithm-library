//1657 두부장수 장홍준
//mcmf 
// 그래프 생성할떄 가림막 k을 잘막자
//그래프는 잘만들기
//격자 그래프는 이분그래프 이다
//격자 인덱스 i+j 가 짝수와 홀수 로 분리 함
//하나는 씽크  하나는 소스 유량은 1,cost =0
//짝홀간 연결  유량 1  cost 연결되는 두부의 가격
//https://www.acmicpc.net/problem/1657

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
#define pii pair < int,int>
#define si(a) scanf("%d",&(a))
#define ss(a) scanf("%s",(a))
#define sLL(a) scanf("%lld",&(a))
#define INF 1234567890
#define LLINF 12345678912345678
#define all(a) (a).begin(),(a).end()
//////////////////////////////////////////////////////////////////////////////////////////

#define MAX_N 100

int n, m;
char board[100][100];
int dobu[6][6] = {
	{ 10,8,7,5,0,1 },
	{ 8,6,4,3,0,1 },
	{ 7,4,3,2,0,1 },
	{ 5,3,2,2,0,1 },
	{ 0,0,0,0,0,0 },
	{ 1,1,1,1,0,0 }
};
struct MCMF1 {
	int V, totalFlow, totalCost;
	vector<vector<int> > cap, cost, flow;
	MCMF1(int n) : V(n), totalFlow(0), totalCost(0) {
		cap = cost = flow = vector<vector<int> >(n, vector<int>(n));
	}
	void setEdge(int u, int v, int cap, int cost) {
		this->cap[u][v] = cap;
		this->cost[u][v] = cost;
	}

	int improve(int s, int t) {
		vector<int> distance(V, INF);
		vector<int> parent(V, -1);
		parent[s] = s;
		distance[s] = 0;
		bool changed = true;
		while (changed) {
			changed = false;
			for (int cur = 0; cur < V; cur++) {
				if (distance[cur] >= INF) continue;

				for (int next = 0; next < V; next++) {
					int cand;
					if (flow[next][cur] > 0)
						cand = distance[cur] - cost[next][cur];
					else if (cap[cur][next] > flow[cur][next])
						cand = distance[cur] + cost[cur][next];
					else
						continue;
					if (cand < distance[next]) {
						distance[next] = cand;
						parent[next] = cur;
						changed = true;
					}
				}
			}
		}

		if (distance[t] == INF) return INF;
		//printf("flow start\n");
		int next = t;
		while (next != s) {
			int cur = parent[next];
			//printf("%d -> %d cost : %d\n",cur,next,cost[cur][next]);
			flow[cur][next]++;
			flow[next][cur]--;
			next = cur;
		}
		//printf("flow end\n");
		totalFlow++;
		totalCost += distance[t];

		return distance[t];
	}
};




int getcost(int a, int b, int c, int d) {
	return dobu[board[a][b] - 'A'][board[c][d] - 'A'];
}

int main() {
	si(n); si(m);
	for (int i = 0; i < n; i++)ss(board[i]);

	MCMF1 mcmf(202);
	int s = 200, t = 201;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k = 14;
			int cur = i*k + j;

			if ((i + j) % 2 == 0) {
				mcmf.setEdge(s, cur, 1, 0);
				//printf("%d %d : s ->%d \n", i, j, cur);
				if (i + 1 < n) {
					int next = (i + 1)*k + j;
					mcmf.setEdge(cur, next, 1, -getcost(i, j, i + 1, j));
					//printf("%d %d ,%d %d : %d -> %d \n", i, j, i + 1, j, cur, next);
				}
				if (j + 1 < m) {
					int next = i*k + j + 1;
					mcmf.setEdge(cur, next, 1, -getcost(i, j, i, j + 1));
					//printf("%d %d ,%d %d : %d -> %d \n", i, j, i, j + 1, cur, next);
				}
				if (i - 1 >= 0) {
					int next = (i - 1)*k + j;
					mcmf.setEdge(cur, next, 1, -getcost(i, j, i - 1, j));
					//printf("%d %d ,%d %d : %d -> %d \n", i, j, i - 1, j, cur, next);
				}
				if (j - 1 >= 0) {
					int next = i*k + j - 1;
					mcmf.setEdge(cur, next, 1, -getcost(i, j, i, j - 1));
					//printf("%d %d ,%d %d : %d -> %d \n", i, j, i, j - 1, cur, next);
				}
			}
			else {
				mcmf.setEdge(cur, t, 1, 0);
				//printf("%d %d : %d -> t\n", i, j, cur);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//printf("%d ", i*n + j);
		}
		//printf("\n");
	}
	int ans = 0;
	while (mcmf.improve(s, t) != INF) {
		ans = max(ans, -mcmf.totalCost);
		//printf("%d\n", -mcmf.totalCost);

	}
	printf("%d\n", ans);

	return  0;
}
