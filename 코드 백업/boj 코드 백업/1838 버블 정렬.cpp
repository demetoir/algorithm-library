#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define si(a) scanf("%d",&(a))
#define MAX_N 1001
#define mp pair <int ,int >

vector < mp > buble;

int n;
int memo[MAX_N];
int fish[MAX_N];
int ans;

int main() {
	si(n);
	for (int i = 0, val; i < n; i++) {
		si(val);
		buble.push_back(make_pair(val, i));
	}
	sort(buble.begin(),buble.end());

	for (int i = 0,val,index; i < n; i++) {
		val = buble[i].first;
		index = buble[i].second;
		if (index < i) {
			ans = max(ans, i - index);
		}
	}

	printf("%d\n", ans);
	return 0;
}

