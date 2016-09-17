#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define MP pair<int,int>
#define INF (1<<31 -1)
#define LLINF ( (((LL)1) <<62)  -1)
#define AND &&
#define OR ||

#define FOR(i,s,e) for (int i = s; i<e; i++)
//////////////////////////////////////////////////////////////////////////////////

#define MAX_N 100001
#define MAX_M 6001

int n,m;

vector<MP>l;
int main() {
	int test;
	si(test);
	for (; test > 0; test--) {
		l.clear();
		si(n);
		for (int i = 0,x,y; i < n; i++) {
			si(x);
			si(y);
			l.push_back(MP(x, y));
		}
		sort(l.begin(), l.end());

		if ( (l[0].first != 0) OR (l[0].second != 0) ) {
			int i = 1;
			for (; i < n; i++) {
				if (l[i].first == 0 AND l[i].second == 0) break;
			}

			for (int k = 0; k< (i+1) / 2; k++) {
				MP t = l[k];
				l[k] = l[i - k];
				l[i - k] = t;
			}
		}


		int i = 1;
		for (int i = 1; i < n; i++) {
			if (l[i - 1].first != l[i].first AND
				l[i - 1].second != l[i].second) {
				int j = i+1;
				for ( ; j < n; j++) {
					if (l[j - 1].first != l[j].first AND
						l[j - 1].second != l[j].second) {
						break;
					}
				}
				for (int k = 0; k<(j-i)/2; k++) {
					MP t = l[i+k];
					l[i+k]=l[j - 1 - k];
					l[j - 1 - k] = t;
				}
			}
		}
		si(m);
		for (int i = 0,val; i < m; i++) {
			si(val);
			printf("%d %d\n", l[val - 1].first, l[val - 1].second);
		}	
	}

	return 0;
}

