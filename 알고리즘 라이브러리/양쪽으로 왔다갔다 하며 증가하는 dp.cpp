//양쪽으로왔다갔다 하는 dp, 와리 가리 dp
//
//
//
//점화식
//i<=j 일때
//dp[i][j] = (dp[i+1][j] + i에대한 조각처리, dp[i][j-1]+ j에대한 조각처리)
//
//참고자료
//
//
//문제
//
//
//
//

//재귀버전
#define MAX_N 1000
int dp1[MAX_N][MAX_N];
int find1(int i, int j) {
	//i <= j 이어야한다
	if (i > j)
		return false;

	if (dp1[i][j] == -1)
		return dp1[i][j];

	//base case 처리
	if (i == j) {
		dp1[i][i];
		return dp1[i][i];
	}


	dp1[i][j] = find1(i + 1, j) /*i에 대한 조각처리*/,
		find1(i, j - 1) /*j에 대한 조각 처리*/;

	return dp1[i][j];
}
//for문 버전
#define MAX_N 1000
int dp2[MAX_N][MAX_N];

int find2() {
	for (int i = 0; i < MAX_N; i++) {
		dp2[i][i] /*base case*/;
	}
	for (int len = 0; len < MAX_N-1; len++) {
		for (int i = 0; i < MAX_N - len; i++) {
			int j = i + len;
			dp2[i][j] = dp2[i + 1][j] /*i에대한 조각처리*/,
				dp2[i][j - 1] /*j에대한 조각 처리*/;
		}
	}
	return dp2[0][MAX_N - 1];
}