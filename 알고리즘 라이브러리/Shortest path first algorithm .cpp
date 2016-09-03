//Shortest path first algorithm (spfa,spf)
//
//시간복잡도 O(E)
//
//참고자료
//https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
//
//문제
//
//

#include <queue>
#include <vector>
#include <utility>
using namespace std;


//일반 그래프에서의 spf
#define MAX_V 100000
#define INF 2e9
#define pii pair <int,int>
vector<pii>G[MAX_V];
vector<int>dist;
void spf(int start) {
	queue<int>q;
	q.push(start);
	dist = vector<int>(MAX_V, INF);
	dist[start] = 0;
	vector<bool> isinqueue(MAX_V);
	isinqueue[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		isinqueue[cur] = false;

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				isinqueue[next] = true;
			}
		}
	}
}