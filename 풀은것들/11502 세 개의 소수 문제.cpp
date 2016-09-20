//11502
//완전 탐색 문제이다
//a+b+c = d 라면
//a+b= d-c 로 변형해서 푼다

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <limits>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <functional>

using namespace std;
typedef long long LL;

#define INF 2e9
#define LLINF ((LL)1e18)
#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sll(a) scanf("%lld",&(a))
#define sc(a) scanf("%c",&(a))
#define ss(a) scanf("%s",a)
#define pii pair<int,int>
//////////////////////////////////////////////////////////////////////////////////////////
#define MAX_N 100001


int seive[1234];
int n;
int prime[1234];
int primesize = 0;
int ans[3];
int isfind;
int main() {

	for (int i = 2; i < 1234; i++) {
		if (seive[i] == 1) continue;
		prime[primesize] = i;
		primesize += 1;
		for (int j = i + i; j < 1234; j += i)
			seive[j] = 1;
	}

	int test;
	si(test);
	for (; test > 0; test--) {
		si(n);
		isfind = 0;
		for (int i = 0; i < primesize; i++) {
			for (int j = i; j < primesize; j++) {
				int val = n - prime[i] - prime[j];
				if (val >= 2 && seive[val] == 0) {
					ans[0] = prime[i];
					ans[1] = prime[j];
					ans[2] = val;
					isfind = 1;
				}
			}
		}
		sort(ans, ans + 3);
		if (isfind) {
			printf("%d %d %d\n", ans[0], ans[1], ans[2]);
		}
		else
			printf("0\n");
	}
	return 0;
}