#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>

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

//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 500001
#define MAX_P 300001

LL maxans = 0;
LL minans = LLINF;
int block[MAX_N];
int ans;
int n,p;

stack<int> line[7];


int main() {
	si(n);si(p);

	for (int i = 0,a,b; i < n; i++) {
		si(a);si(b);
		while (!line[a].empty() && line[a].top() > b) {
			line[a].pop();
			ans+=1;
		}

		if (line[a].empty() || line[a].top() !=b) {
			ans += 1;
			line[a].push(b);
		}
	
	}


	printf("%d\n", ans);

	return 0;
}