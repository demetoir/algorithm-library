//dp k번째 답
//dp를 구하는거 는 쉽다
//k번째를 구하는것에서 인덱스 처리를 조심해야한다

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
#define INF 1234567890
#define INFLL 12345678912345678
#define MAX_N 50000

LL dp[100][100];
LL n, l, k;
void find(LL curlen, LL count, LL val) {
	if (curlen == 0)return;
	LL sum = 0;
	//앞에 0이 들어가는 갯수
	for (int i = 0; i <= count; i++) {
		sum += dp[curlen - 1][i];
	}

	if (val <= sum) {
		printf("0");
		find(curlen - 1, count, val);
	}
	else {
		printf("1");
		find(curlen - 1, count - 1, val - sum);
	}
	return;
}
int main() {
	sLL(n);
	sLL(l);
	sLL(k);

	dp[0][0] = 1;
	for (int i = 1; i < 100; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}


	find(n, l, k);
	printf("\n");
	return 0;
}


