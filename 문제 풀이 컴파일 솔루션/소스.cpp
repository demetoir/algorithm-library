//dp 슬라이딩윈도우, 정렬 ,아이디어, 막대기 나누기
//
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
#define LLINF 12345678912345678
//////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
#define MAX_N 12
int Stirling[MAX_N][MAX_N];
void make_Stirling() {
	Stirling[0][0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		Stirling[i][1] = Stirling[i - 1][1] * (i-1);
		Stirling[i][i] = 1;
		for (int j = 2; j < i; j++) {
			Stirling[i][j] = (i-1)*Stirling[i-1][j] + Stirling[i-1][j - 1];
		}
	}
}
int main() {
	make_Stirling();

	return 0;
}


