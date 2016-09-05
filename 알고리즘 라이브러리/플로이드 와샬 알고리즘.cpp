//플로이드 와셜 알고리즘
//
//시간 복잡도 O(V^3)
//
//참고자료
//https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
//http://m.blog.naver.com/cky5122/80195173113
//
//문제
//11403 경로 찾기 https://www.acmicpc.net/problem/11403
//11404 플로이드 https://www.acmicpc.net/problem/11404
//1389 케빈 베이컨의 6단계 법칙 https://www.acmicpc.net/problem/1389
//1238 파티 https://www.acmicpc.net/problem/1238
//2606 바이러스 https://www.acmicpc.net/problem/2606

using namespace std;

//인접 행렬 일떄
#define MAX_V 100

int G[MAX_V][MAX_V];
int n;
void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (G[j][k] > G[j][i] + G[i][k]) {
					G[j][k] = G[j][i] + G[i][k];
				}
			}
		}
	}
}