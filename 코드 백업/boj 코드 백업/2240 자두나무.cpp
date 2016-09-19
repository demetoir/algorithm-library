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

////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1000

int memo1[2][31];
int memo2[2][31];


int T,w;
int jadu[MAX_N + 1];
int ans;

int  main() {
	si(T);
	si(w);

	for (int i = 0; i < 31; i++) {
		memo1[0][i] = -1;
		memo1[0][i] = -1;
	}

	memo1[0][0] = 0;

	for (int t = 0,jadu; t < T; t++) {
		for (int i = 0; i < 31; i++) {
			memo2[0][i] = -1;
			memo2[0][i] = -1;
		}
		si(jadu);

		for (int i = 0,val; i <= w; i++) {
			
			val= jadu ==1 ? 1:0;			
			memo2[0][i] = max(memo1[0][i]+val,memo2[0][i]);
			if (i>0)
				memo2[0][i] = max(memo1[1][i-1]+val, memo2[0][i]);
				
			val = jadu == 2 ? 1 : 0;
			memo2[1][i] = max(memo1[1][i] +val , memo2[1][i]);
			if (i > 0)
				memo2[1][i] = max(memo1[0][i-1]+val,memo2[1][i]);
		}

		for (int i = 0; i < 31; i++) {
			memo1[0][i] = memo2[0][i];
			memo1[1][i] = memo2[1][i];
		}
	}

	for (int i = 0; i < 31; i++) {
		ans = max(ans, memo1[0][i]);
		ans = max(ans, memo1[1][i]);

	}
	printf("%d\n", ans);
	return 0;
}











