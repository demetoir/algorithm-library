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
#define MAX_N 5000001
LL maxans = 0;
LL minans = LLINF;
int block[MAX_N];
LL ans;
int n,p;
char str[MAX_N];


int main() {
	si(n);
	scanf("%s", str);
	
	int val = 0;
	for (int i = 0; i < n; i++) {
		int cur = str[i];
		if ('0' <= cur AND cur <= '9')
			val  = val*10 + cur - '0';
		else {
			if (val <= 999999) {
				ans += val;
			}
			val = 0;
		}
	}

	if (val <= 999999) {
		ans += val;
	}


	printf("%lld\n", ans);

	return 0;
}