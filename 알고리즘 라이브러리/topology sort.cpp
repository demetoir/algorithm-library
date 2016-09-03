//topology sort(위상정렬)
//
//시간복잡도 O(V + E)
//
//참고 자료
//https://en.wikipedia.org/wiki/Topological_sorting
//http://blog.naver.com/PostView.nhn?blogId=cky5122&logNo=80189496939&parentCategoryNo=162&categoryNo=206&viewDate=&isShowPopularPosts=false&from=postView
//
//문제
//2252 줄세우기 https://www.acmicpc.net/problem/2252

#include <vector>
#include <queue>
using namespace std;
#define MAX_V 100000

vector<int> G[MAX_V]; // 그래프
int inlevel[MAX_V]; //각정점으로 들어가는 차수
void topology_sort(vector<int> &sorted_v) {
	queue <int>q;
	for (int i = 0; i < MAX_V; i++) {
		if (inlevel[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		sorted_v.push_back(cur);

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i];
			inlevel[next]-=1;
			if (inlevel[next] == 0)
				q.push(next);
		}
	}
}