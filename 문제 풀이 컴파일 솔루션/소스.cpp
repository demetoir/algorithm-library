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
#define MAX_N 200001
int n;
char str[MAX_N];
vector <int> sa;

struct CMP {
	vector<int> &g;
	int k;
	CMP(vector <int> &g, int k) :g(g), k(k) {};
	bool operator()(int a, int b) {
		if (g[a] != g[b]) return g[a] < g[b];
		return g[a + k] < g[b + k];
	}
};

vector <int> make_sa(const char* s) {
	int t = 1; 
	int n = strlen(s);

	vector<int> g(n+1,0);
	for (int i = 0; i < n; i++)g[i] = s[i];
	g[n] = -1;

	vector<int>perm(n,0);
	for (int i = 0; i < n; i++)perm[i] = i;

	while (t < n) {
		CMP cmp(g,t);
		sort(perm.begin(), perm.end(), cmp);

		t *= 2;
		if (t >= n) break;
		
		vector<int> newg(n+1,0);
		for (int i = 0; i < n; i++){

		}
	}



	return  perm;
}
int main() {
	si(n);
	ss(str);



	return  0;
}
