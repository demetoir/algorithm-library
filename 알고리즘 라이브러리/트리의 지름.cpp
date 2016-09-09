//트리의 지름
//트리 안의 가장 거리가 먼 정점의 거리 
////트리내 최장 거리및 경로
//

//참고 자료

//
//http://koosaga.myungwoo.kr/entry/%ED%8A%B8%EB%A6%AC%EC%9D%98-%EC%A7%80%EB%A6%84-Diameter-of-tree
//http://blog.sisobus.com/2013/10/backjoon-online-judge-no1967.html#.V9KccpiLRb4
//http://codingishard.tistory.com/entry/%ED%8A%B8%EB%A6%AC%EC%9D%98-%EC%A7%80%EB%A6%84-%EB%B0%98%EC%A7%80%EB%A6%84-%EC%9D%B4%EC%8B%AC%EB%A5%A0
//
//
//문제
//
//https://www.acmicpc.net/problem/1967
//https://www.acmicpc.net/problem/1167
//

//cost 가 있을떄
#include <vector>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
#define MAX_N 100000
vector <pii> G[MAX_N + 1];
int ans; 
int dfs(int cur) {	
	int a = 0, b = 0;
	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i].first;
		int cost = G[cur][i].second;
		int val = dfs(next) + cost;

		if (a < val) {
			swap(a, val);
		}
		if (b < val) {
			b = val;
		}
	}
	ans = max(a + b, ans);
	return a;
}




