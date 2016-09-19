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


#define MAX_N 501
#define MAX_M 6001

int n;
map<LL, int> mymap;


int main() {
	si(n);
	for (int i = 0; i < n; i++) {
		LL val;
		sLL(val);
		mymap[val] += 1;
	}
	LL ansval=0;
	LL ans = 0;
	for (map<LL, int>::iterator iter = mymap.begin(); iter != mymap.end(); iter++) {
		LL key = iter->first;
		LL val = iter->second;
		if (ansval == val) {
			ans = min(key, ans);
		}
		if (ansval < val) {
			ansval = val;
			ans = key;
		}
	}
	printf("%lld\n", ans);


	return 0; 
}

