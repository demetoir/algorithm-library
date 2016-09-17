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

#define FOR(i,s,e) for (int i = s; i<e; i++)


//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1001
#define MOD 1000000000
int x[3];
int y[3];
int ans;
int n;
int l[5];
int ansval = 0;
//마지막 수 ,  1024갯수
int memo1[10][1024+1];
int memo2[10][1024+1];

int main() {
	si(n);
	for (int i = 1; i < 10; i++) {
		memo1[i][1 << i] = 1;
	}


	for (int iter = 1; iter < n; iter++) {
		memset(memo2, 0, sizeof(memo2));

		for (int i = 0; i < 10; i++) {
			for (int bit = 0,nextbit; bit < 1024; bit++) {
				if (( bit & (1 << i) ) == false) continue;

				nextbit = (bit | (1<<(i-1)) );
				if (i - 1 >= 0) {
					memo2[i-1][nextbit] = (memo2[i-1][nextbit] + memo1[i][bit]) % MOD;
				}
				nextbit = (bit | (1 << (i +1)));

				if (i + 1 <= 9) {
					memo2[i+1][nextbit] = (memo2[i+1][nextbit] + memo1[i][bit]) % MOD;
				}
			}
		}

		for (int i = 0; i < 10; i++) {
			for (int bit = 0; bit < 1024; bit++) {
				memo1[i][bit] = memo2[i][bit];
			}
		}
	}

	ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + memo1[i][1023]) % MOD;
	}
	printf("%d\n", ans);

	return 0; 
}

