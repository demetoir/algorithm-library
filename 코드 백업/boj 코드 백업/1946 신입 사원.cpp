#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define si(a) scanf("%d" , &(a))
#define pii pair< int, int > 

int n;

vector< pii >p;
vector< int > lis;
int ans = 0;
bool cmp (const pii A, const pii B) {
	if (A.first < B.first && A.second < B.second) {
		return true;
	}
	return false;
}

int main() {
	int testcase;
	si(testcase);
	for (int test = 0; test < testcase; test++) {
		si(n);
		p = vector<pii>();
		lis = vector< int>();
		for (int i = 0, a, b; i < n; i++) {
			si(a); si(b);
			p.push_back(make_pair(a, b));
		}
		sort(p.begin(), p.end());
		ans = 1;
		int val = p[0].second;
		for (int i = 1; i < n; i++) {
			if (val > p[i].second) {
				ans += 1;
				val = p[i].second;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}