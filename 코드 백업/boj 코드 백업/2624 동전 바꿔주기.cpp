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

//////////////////////////////////////////////////////////////////////////////////

#define MAX_N 100
int n,k;
int memo[10000 + 1];
vector <MP> coin;
int ans;
int  main() {
	si(n); si(k);
	for (int i = 0,a,b; i < k; i++) {
		si(a); si(b);
		coin.push_back(MP(a, b));
	}
	sort(coin.begin(), coin.end());

	memo[0] = 1;
	int maxval = 0;
	int sum = 0;
	for (int iter = 0; iter < k; iter++) {
		int val = coin[iter].first;
		int num = coin[iter].second;
		for (int i = n; i >=0; i--) {
			if (memo[i] == 0) continue;
			for (int j = 1; j <= num; j++) {
				int next = i + val*j;
				if (next > n)continue;
				memo[next] += memo[i];
			}
		}
	}

	ans = memo[n];



	printf("%d\n", ans);
	return 0;
}






 




