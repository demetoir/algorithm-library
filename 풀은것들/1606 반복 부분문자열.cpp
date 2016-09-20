// 1605  반복 부분 문자열
// sa,lcp 구현

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ss(a) scanf("%s",(a))
#define si(a) scanf("%d",&(a))
#define MAX_N 200001

char str[MAX_N];
int n;

struct sa_cmp {
	vector<int> &g;
	int k;
	sa_cmp(vector<int> &g, int k) : g(g), k(k) {}
	bool operator() (int a, int b) {
		if (g[a] != g[b]) return g[a] < g[b];
		return g[a + k] < g[b + k];
	}
};
vector<int> make_sa(const string &str) {
	int k = 1;
	int size = str.size();
	vector<int>g(size + 1);
	for (int i = 0; i < str.size(); i++) {
		g[i] = str[i];
	}
	g[size] = -1;
	vector<int>perm(size);
	for (int i = 0; i < size; i++)
		perm[i] = i;

	while (k < size) {
		sa_cmp cmp(g, k);
		sort(perm.begin(), perm.end(), cmp);

		k *= 2;
		if (k >= size) break;
		vector<int> newg(size + 1);
		newg[size] = -1;
		newg[perm[0]] = 0;
		for (int i = 1; i < size; i++) {
			if (cmp(perm[i - 1], perm[i])) {
				newg[perm[i]] = newg[perm[i - 1]] + 1;
			}
			else {
				newg[perm[i]] = newg[perm[i - 1]];
			}
		}
		g = newg;
	}

	return perm;
}

vector<int> make_lcp(const vector<int>&sa, const string &str) {
	int size = sa.size();
	vector<int> lcp(size);
	vector<int> rev(size);
	for (int i = 0; i < size; i++)
		rev[sa[i]] = i;
	int k = 0;
	for (int i = 1; i < size; i++) {
		if (rev[i] == 0) {
			k = 0;
			continue;
		}
		int j = sa[rev[i] - 1];
		while (i + k < size && j + k < size && str[i + k] == str[j + k]) k++;
		lcp[rev[i]] = k;
		k = max(k - 1, 0);
	}
	return lcp;
}
int main() {
	si(n);
	ss(str);
	vector<int>sa = make_sa(str);
	vector<int>lcp = make_lcp(sa, str);

	int ans = 0;
	for (int i = 1; i < n; i++)
		ans = max(ans, lcp[i]);
	printf("%d\n", ans);
	return 0;
}