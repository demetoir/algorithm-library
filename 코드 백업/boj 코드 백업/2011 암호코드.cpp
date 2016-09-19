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
#define MP pair <int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define sS(a) scanf("%s",a)
#define INF 1234567890
#define INFLL 12345678912345678

////////////////////////////////////////////////////////////////////////////////
#define MAX_N 5000

#define MOD 1000000
int memo[MAX_N + 1];
char s[MAX_N + 1];
int num[MAX_N + 1];




int  main() {
	scanf("%s", s);
	int size = strlen(s);

	for (int i = 0; i < size; i++)
		num[i+1] = s[i] - '0';

	memo[0] = 1;

	for (int i = 1; i <= size; i++) {

		
		if (num[i] != 0)
			memo[i] = (memo[i] + memo[i-1]) % MOD;
		

		int val = num[i] + num[i - 1]*10;
		if (num[i-1] !=0 &&val <= 26 && 1 <= val && i-2 >=0) {
			memo[i] = (memo[i] + memo[i - 2]) % MOD;
		}
		
	}
	int ans = memo[size];
	printf("%d\n", ans);
	return 0;
}










