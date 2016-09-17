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
#define sll(a) scanf("%lld",&a)
#define pi(a) printf("%d\n",a)
#define pspace printf(" ")
#define pendl printf("\n")
#define ull unsigned long long 
#define ll long long 
#define pp pair<int,int>

int n = 0;
ll w[100], v[100];
vector < long long > fib;

int main() {
	long long a, b, c;
	a = 0, b = 1;
	for (int i = 0; i < 100; i++) {
		c = a + b;
		a = b;
		b = c;
		if (c > 1e16)break;
		printf("%d %lld\n", i, c);
	}
	/*si(n); 
	for (int i = 0; i < n; i++) {
		sll(w[i]); sll(v[i]);
	}
*/
}