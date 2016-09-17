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
int main() {
	int testcase;
	si(testcase);
	for (int test = 0; test < testcase; test++) {
		si(n);
		p = vector<pii>();
		lis = vector< int>();
		for (int i = 0,a,b; i < n; i++) {
			si(a); si(b);
			p.push_back(make_pair(a, b));
		}
		sort(p.begin(), p.end());

		







		printf("%d\n", ans);
		
	}



	return 0;
}