//bfs(Breadth First Search, 너비 우선 탐색)
//시간 복잡도 O(|V| + |E|) 정점의 갯수 + 간선의 갯수
//
//참고 자료
//https://en.wikipedia.org/wiki/Breadth-first_search
//http://blog.eairship.kr/269
//
//문제
//1260 dfs와 bfs https://www.acmicpc.net/problem/1260
//2178 미로 탐색 https://www.acmicpc.net/problem/2178
//2589 보물섬 https://www.acmicpc.net/problem/2589
//4963 섬의 개수 https://www.acmicpc.net/problem/4963
//1697 숨바꼭질 https://www.acmicpc.net/problem/1697
//11403 경로 찾기 https://www.acmicpc.net/problem/11403
// 5014 스타트 링크 https://www.acmicpc.net/problem/5014
//2468 안전 영역 https://www.acmicpc.net/problem/2468


#include <queue>
#include <vector>
using namespace std;

//일반 그래프 상에서의 bfs
#define MAX_V 1001
vector <int>G[MAX_V];	// 방향 그래프
bool visited[MAX_V];	// 정점에 방문했는지 체크하는 배열
						// false -> 아직 방문하지 않음
						// true -> 이미 방문 했음
void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i];
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}


// 격자(그리드) 그래프 상에서 bfs
#define pii pair<int,int> // x,y 좌표를 저장하기위한 pair
#define DIRECTION_SIZE 4
#define MAX_N 1000
#define MAX_M 1000
int dx[DIRECTION_SIZE] = { 1,-1,0,0 };// 이동방향을 저장하는 dx,dy 배열
int dy[DIRECTION_SIZE] = { 0,0,1,-1 };
int grid_visited[MAX_N][MAX_M]; // N*M 짜리 격자 그래프에서 방문했는지 체크하는 배열
								// false -> 아직 방문하지 않음
								// true -> 이미 방문 했음
void bfs(int start_x, int start_y) {
	queue<pii> q;
	q.push(pii(start_x, start_y));
	grid_visited[start_x][start_y] = true;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		for (int i = 0; i < DIRECTION_SIZE; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			
			//경계 값 검사 격자 그래프에서 벗어나는것은 제외한다
			if (a < 0 || MAX_N <= a) continue;
			if (b < 0 || MAX_N <= b) continue;
			
			if (grid_visited[a][b] == true) continue;

			q.push(pii(a, b));
			grid_visited[a][b] = true;
		}
	}
}