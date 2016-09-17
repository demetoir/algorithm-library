#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <string.h>
#include <math.h>

using namespace std;

vector<int> iv;
vector<int>::iterator iit;
vector<double> dv;
priority_queue <int> PQ;
queue <int>  Q;
map<int, string> istrmap;
map <long long, int>iimap;
vector < int> G[100000 + 1];
struct mp {
	int a, b;
};
#define ABS(a)(((a) < (0))?-(a):(a))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define si(a) scanf("%d",&a)
#define pi(a) printf("%d\n",a)
#define pspace printf(" ")
#define pendl printf("\n")
#define ull unsigned long long 
#define ll long long 
#define pp pair<int,int>

int n, k;
vector<int> prime;
bool seive[100000 + 1];
int memo[100000 + 1];
int main() {
	si(n);si(k);
	
	for (int i = 2; i < 100000 + 1; i++) {
		if (seive[i] == true)continue;
		prime.push_back(i);
		memo[i] = i;
		for (int j = i + i; j < 100000 + 1; j += i) {
			seive[j] = true;
			memo[j] = i;
		}
	}
	int ans = 0;
	for (int i = 1; i < n + 1; i++) {
		if (memo[i] <= k)ans++;
	}
	printf("%d\n",ans);
}