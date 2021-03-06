// dfs (depth first search, 깊이 우선 탐색)
// 시간 복잡도 O(|V| + |E|)
//
//참고 자료
//https://ko.wikipedia.org/wiki/%EA%B9%8A%EC%9D%B4_%EC%9A%B0%EC%84%A0_%ED%83%90%EC%83%89
//http://blog.eairship.kr/268
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

using namespace std;

// 일반 그래프상에서의 dfs
#include <vector>
#define MAX_V 100000

vector<int>G[MAX_V]; // 일반적인 방향 그래프
bool visited[MAX_V];	// 정점에 방문했는지 체크하는 배열
						// false -> 아직 방문하지 않음
						// true -> 이미 방문 했음
void dfs(int cur) {
	if (visited[cur] == true) return;
	visited[cur] = true;
	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i];
		if (visited[next] == false)
			dfs(next);
	}
}

// 격자(그리드) 그래프 상에서 dfs
#define DIRECTION_SIZE 4
#define MAX_N 1000
#define MAX_M 1000
int dx[DIRECTION_SIZE] = { 1,-1,0,0 };// 이동방향을 저장하는 dx,dy 배열
int dy[DIRECTION_SIZE] = { 0,0,1,-1 };
int grid_visited[MAX_N][MAX_M]; // N*M 짜리 격자 그래프에서 방문했는지 체크하는 배열
								// false -> 아직 방문하지 않음
								// true -> 이미 방문 했음
void dfs(int x, int y) {
	if (grid_visited[x][y] == true)return;
	grid_visited[x][y] = true;
	for (int i = 0; i < DIRECTION_SIZE; i++) {
		int a = x + dx[i];
		int b = y + dy[i];

		//경계 값 검사 격자 그래프에서 벗어나는것은 제외한다
		if (a < 0 || MAX_N <= a) continue;
		if (b < 0 || MAX_N <= b) continue;

		if (grid_visited[a][b] == false) 
			dfs(a,b);
	}
}
