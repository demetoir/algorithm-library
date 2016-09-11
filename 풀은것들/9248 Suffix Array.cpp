// sa ,lcp 구현
//https://www.acmicpc.net/problem/9248
//n이커서 빠른 sa 생성 알고리즘이 필요하다

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

#define LL long long
#define pii pair < int,int>
#define si(a) scanf("%d",&(a))
#define ss(a) scanf("%s",(a))
#define sLL(a) scanf("%lld",&(a))
#define INF 1234567890
#define LLINF 12345678912345678
#define all(a) (a).begin(),(a).end()
//////////////////////////////////////////////////////////////////////////////////////////

#define MAX_N 500001
char str[MAX_N];
struct SA_CMP {
	const vector<int>& g;
	int t;
	SA_CMP(const vector<int>& g_, int t_) :g(g_), t(t_) {}
	bool operator() (int a, int b) {
		if (g[a] != g[b]) return  g[a] < g[b];
		return g[a + t] < g[b + t];
	}
};

vector<int> make_SA(const char *str) {
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
		SA_CMP cmp(group, t);
		sort(perm.begin(), perm.end(), cmp);

		t *= 2;
		if (t >= n)break;

		vector<int> newgroup(n + 1);
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
	return perm;
}

vector<int> make_lcp(const vector<int> &sa, const string &s) {
	int size = sa.size();
	vector<int> lcp(size, 0);
	vector<int> rev(size, 0);
	int k = 0, j;
	for (int i = 0; i < size; i++) rev[sa[i]] = i;
	for (int i = 0; i < size; i++) {
		if (rev[i] == 0) { k = 0; continue; }
		j = sa[rev[i] - 1];
		while (i + k < size && j + k < size && s[i + k] == s[j + k])k++;
		lcp[rev[i]] = k;
		k = max(k - 1, 0);
	}
	return lcp;
}

int main() {
	ss(str);
	int n = strlen(str);
	vector <int> sa = make_SA(str);

	vector<int > lcp = make_lcp(sa, str);
	for (int i = 0; i < n; i++)
		printf("%d ", sa[i] + 1);
	printf("\n");

	printf("x ");
	for (int i = 1; i < n; i++)
		printf("%d ", lcp[i]);
	printf("\n");

	return  0;
}
