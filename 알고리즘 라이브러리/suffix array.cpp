//suffix array 접미사 배열
//
//시간 복잡도 O(nlog(n))
//
//참고 자료
//https://en.wikipedia.org/wiki/Suffix_array
//
//
//문제 
//11656 접미사 배열 https://www.acmicpc.net/problem/11656
//5582 공통 부분 문자열 https://www.acmicpc.net/problem/5582
//


#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_N 1000

char str[MAX_N + 1];
int group[MAX_N + 1];
struct Comparator {
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _g, int _t) :group(_g), t(_t) {};
	bool operator()(int a, int b) {
		if (group[a] != group[b]) return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

int  main() {
	int t = 1;
	int n = strlen(str);

	vector<int> group(n + 1);
	for (int i = 0; i < n; i++)
		group[i] = str[i];
	group[n] = -1;

	vector <int> perm(n);
	for (int i = 0; i < n; i++) {
		perm[i] = i;
	}

	while (t < n) {
		Comparator cmp(group, t);
		sort(perm.begin(), perm.end(), cmp);

		t *= 2;
		if (t >= n)break;

		vector< int> newgroup(n + 1);
		newgroup[n] = -1;
		newgroup[perm[0]] = 0;

		for (int i = 1; i < n; i++) {
			if (cmp(perm[i - 1], perm[i]))
				newgroup[perm[i]] = newgroup[perm[i - 1]] + 1;
			else
				newgroup[perm[i]] = newgroup[perm[i - 1]];
		}
		group = newgroup;
	}
	return 0;
}
