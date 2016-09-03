//dijkstra short path 다잌스트라 최단경로 알고리즘
//
//시간 복잡도 
//큐 사용시 O(V^2)
//우선순위 큐 사용시 O( (|V| + |E|)log(|V|) )
//
//선행 조건 :
//그래프 상에서 음수 사이클이 없어야한다
//
//참고자료
//https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
//http://koosaga.myungwoo.kr/entry/Floyd-Warshall-Bellman-Ford-Dijkstra-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
//http://makefortune2.tistory.com/26
//
//
//문제
//1753 최단경로 https://www.acmicpc.net/problem/1753
//1916 최소비용 구하기 https://www.acmicpc.net/problem/1916
//1238 파티 https://www.acmicpc.net/problem/1238
//1504 특정한 최단경로 https://www.acmicpc.net/problem/1504
//5427 불 https://www.acmicpc.net/problem/5427
//2206 벽부수고 이동하기 https://www.acmicpc.net/problem/2206
//1981 배열에서의 이동 https://www.acmicpc.net/problem/1981
//
//우선순위 큐 버전 검증 완료

#include <queue>
#include <vector>
#include <functional>
using namespace std;

//일반적인 그래프 에서의 다잌스트라 일반 큐 사용
#define MAX_V 100000
#define INF 2e9
#define pii pair<int,int>
vector<pii>G[MAX_V];	//G[a][b].first -> 다음 정점
					//G[a][b].second -> 다음 정점 까지 가는데 비용

vector<int> dist;	//dist[i] -> 시작 정점으로 부터 다른 정점까지의 거리
					//값이 INF 라면 갈수있는 방법이 없음
int dijkstra(int start) {
	queue<int> q;
	q.push(start);
	dist = vector<int>(MAX_V, INF);
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				q.push(next);
			}
		}
	}
}


//일반적인 그래프 에서의 다잌스트라 우선 순위큐 사용
//그냥 큐를 쓰는것보다 더 빠르다
#define MAX_V 100000
#define INF 2e9
#define pii pair<int,int>
vector<pii>G[MAX_V];	//G[a][b].first -> 다음 정점
					//G[a][b].second -> 다음 정점 까지 가는데 비용

vector<int> dist;	//dist[i] -> 시작 정점으로 부터 다른 정점까지의 거리
					//값이 INF 라면 갈수있는 방법이 없음

int dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(pii(0,start));
	dist = vector<int>(MAX_V, INF);
	dist[start] = 0;

	while (!pq.empty()) {
		int cur_dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cur_dist > dist[cur]) continue;

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				pq.push(pii(dist[next],next));
			}
		}
	}
}



//격자 그래프일때의 다잌스트라
#define pii pair<int,int> // x,y 좌표를 저장하기위한 pair
#define DIRECTION_SIZE 4
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
int dx[DIRECTION_SIZE] = { 1,-1,0,0 };// 이동방향을 저장하는 dx,dy 배열
int dy[DIRECTION_SIZE] = { 0,0,1,-1 };
int grid_dist[MAX_N][MAX_M];// N*M 짜리 격자 그래프
							// 시작점으로부터의 최단거리
int grid_cost[MAX_N][MAX_M];//grid_cost[a][b] -> a,b 로 가는데 비용

int dijkstra(int start_x,int start_y) {
	queue<pii> q;
	q.push(pii(start_x,start_y));
	memset(grid_dist, 0, sizeof(grid_dist));
	grid_dist[start_x][start_y] = 0;

	while (!q.empty()) {
		int x = q.front().first; 
		int y = q.front().second;
		q.pop();

		for (int i = 0; i <DIRECTION_SIZE; i++) {
			int a = x + dx[i];
			int b = y + dy[i];

			//경계 값 검사 격자 그래프에서 벗어나는것은 제외한다
			if (a < 0 || MAX_N <= a) continue;
			if (b < 0 || MAX_N <= b) continue;

			if (grid_dist[a][b] > grid_dist[x][y] + grid_cost[a][b]) {
				grid_dist[a][b] = grid_dist[x][y] + grid_cost[a][b];
				q.push(pii(a,b));
			}
		}
	}
}



// 다잌스트라에서 최단 경로를 알고싶을경우
#define MAX_V 100000
#define INF 2e9
#define pii pair<int,int>
vector<pii>G[MAX_V];	//G[a][b].first -> 다음 정점
					//G[a][b].second -> 다음 정점 까지 가는데 비용

vector<int> dist;	//dist[i] -> 시작 정점으로 부터 다른 정점까지의 거리
					//값이 INF 라면 갈수있는 방법이 없음
vector<int>parent;  //parent[i] -> i정점에서 시작하는 정점으로 가는데 최단 거리로 가는
					//경로 다음정점 
int dijkstra(int start) {
	queue<int> q;
	q.push(start);
	dist = vector<int>(MAX_V, INF);
	dist[start] = 0;
	parent = vector<int>(MAX_V, -1);
	parent[start] = -1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				parent[next] = cur;
				q.push(next);
			}
		}
	}
}
void print_path(int end) {
	if (dist[end] == INF) {
		printf("path not exist\n");
		return;
	}
	for (int p = end; parent[p] != -1; p = parent[p]) {
		printf("%d ->%d", p, parent[p]);
	}
}