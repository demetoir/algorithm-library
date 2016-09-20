//미완성
//막대기 자르기 dp
//
//
//한쪽으로 증가하는 또는 한쪽에서 감소하면서 진행한다
//큰막대기  =  잘린 막대기 + 조각으로 나온다 
//그림으로 설명할게 필요하다
//기본적인 dp이다
//f(n) = f(n-1) + 조각처리값
//
//
//참고 자료
//
//
//문제
//
//
//
//
//
//
//

#include <algorithm>
using namespace std;

//점화식 f(n) = f(n-1) 
//재귀버전 
#define MAX_N 100000
int dp1[MAX_N];
int A[MAX_N];
int n;
int find1(int x) {
	if (dp1[x] != 0) 
		return dp1[x];

	//base case 처리
	if (x < 0)
		return 0;

	//큰 막대기 dp[x]를 구한다 
	for (int i = 0; i < x; i++) {
		//작은 막대기dp[i]와 조각처리를 구현한다
		
	}
	return dp1[x];
}

//for문 버전 
#define MAX_N 100000
int dp2[MAX_N];
int A[MAX_N];
int n;
int find2(int x) {
	//base case 처리
	dp2[0] = 0;

	for (int i = 1; i < x; i++) {
		//dp[i] 초기화
		//큰막대기 dp[i]를 구한다 
		for (int j = 0; j < x; j++) {
			//작은 막대기 dp[j] 와 조각 처리를 구현한다			
		}
	}

	return dp2[x];
}