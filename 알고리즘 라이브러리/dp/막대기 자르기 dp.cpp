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
//순서를 정리한다..
//백준 그룹 문제집에 있음
//1099 dp 막대기 나누기
//1365 dp lis 막대기 나누기
//1541 dp 그리디 막대기 나누기
//1594 dp 막대기 나누기
//1720 dp 막대기 나누기
//1890 dp 막대기 나누기
//1904 dp 막대기 나누기
//1912 dp 막대기 나누기
//1947 dp 막대기 나누기 피보나치
//1965 dp lis 막대기 나누기
//2011 dp 막대기 나누기
//2133 dp 막대기 나누기 응용
//2193 dp 막대기 나누기
//2302 dp 막대기 나누기 상
//2352 dp 막대기 나누기 lis
//2491 dp lis 막대기 나누기
//2565 dp lis 막대기 나누기
//2568 dp lis 막대기 나누기
//2616 dp 막대기 나누기 2차 ?
//2643 dp lis 막대기 나누기 2원소 ?
//2670 dp 막대기 나누기 연속합
//2718 dp 막대기 나누기
//3745 dp lis 막대기 나누기
//5060 dp 막대기 나누기 상
//8902 dp 막대기 나누기 상
//10211 dp 막대기 나누기 최대 부분합 ?
//11053 dp lis 막대기 나누기
//11054 dp lis 막대기 나누기
//11055 dp lis 막대기 나누기
//11060 dp 막대기 나누기
//11722 dp lis 막대기 나누기
//11726 dp 막대기 나누기
//11727 dp 막대기 나누기


#include <algorithm>
using namespace std;

//점화식 f(n) = for(i,0~n) {f(i) + (i+1~n)조각 }
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