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
#define MAX_N 1000
int n, m;
int l[MAX_N+1];
vector<int>memo;
vector<int>psum;
int ans,val;
int  main() {
	int testcase;
	si(testcase);
	for (int test = 0; test < testcase; test++) {
		si(n); 
		int val;
		int psum=0;
		ans = -INF;
		for (int i = 0; i < n; i++) {
			si(val);
			ans = max(ans,val);
			psum += val;
			if (psum < 0)
				psum = 0;
			else
				ans = max(ans, psum);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}











