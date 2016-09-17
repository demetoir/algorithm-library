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
#define MAX_N 30001

LL maxans = 0;
LL minans = LLINF;

int food[MAX_N];
int ans;
int n, d, k, c;
int check[3001];
int main() {
	int test;
	si(n);
	si(d);
	si(k);
	si(c);
	for (int i = 0; i < n; i++) {
		si(food[i]);
	}
	ans = 0;
	
	for (int start = 0; start < n; start++) {
		memset(check, 0, sizeof(check));
		for (int i = 0; i < k; i++) {
			check[ food[(start + i) % n] ] +=1;
		}
		int val = 0; 
		
		check[c] += 1;
		for (int i = 1; i <= 3000; i++) {
			if (check[i] > 0) val += 1;
		}
		ans = max(ans, val);
		

	}
	printf("%d\n", ans);

	return 0;
}