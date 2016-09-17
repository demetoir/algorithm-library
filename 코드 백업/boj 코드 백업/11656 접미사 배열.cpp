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
#define MP pair < int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define sS(a) scanf("%s",a)
#define INF 1234567890
#define INFLL 12345678912345678
#define MAX_N 1000

char s[MAX_N + 1];
int group[MAX_N + 1];
struct Comparator{
	const vector<int>& group;
	int t;
	Comparator(const vector<int>& _g, int _t) :group(_g), t(_t) {};
	bool operator()(int a, int b) {
		if (group[a] != group[b]) return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};

int  main() {
	sS(s);
	int t = 1;
	string str(s);
	int n = str.size();

	vector<int> group(n + 1);

	for (int i = 0; i < n; i++)
		group[i] = s[i];
	group[n] = -1;

	vector <int> perm(n);
	for (int i = 0; i < n; i++) {
		perm[i] = i;
	}

	while (t < n) {

		Comparator cmp(group, t);
		sort(perm.begin(), perm.end(), cmp);

		t*=2;
		
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
	
	for (int i = 0; i < n; i++) {
		for (int j = perm[i]; j < n; j++) {
			printf("%c", s[j]);
		}
		printf("\n");
	}



	return 0;
}











