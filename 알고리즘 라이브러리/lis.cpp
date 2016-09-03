//lis (longest increasing sequence, 최장 증가수열)
//
//시간 복잡도 
//쉬운 dp : O(n^2)
//lower_bound 이용 : O(nlog(n))
//
//참고자료
//https://en.wikipedia.org/wiki/Longest_increasing_subsequence
//http://hoon222y.tistory.com/45
//https://www.youtube.com/watch?v=RzPElBr3L5A
//1 : 24 : 07 부분 부터 보면 최대 구간 중첩이라는 문제있는데 확실히 알려면 여기 한번 보는거 추천
//
//문제
//1956 상자넣기 https://www.acmicpc.net/problem/1965
//2565 전깃줄 https://www.acmicpc.net/problem/2565
//2352 반도체 설계 https://www.acmicpc.net/problem/2352
//1365 꼬인 전깃줄 https://www.acmicpc.net/problem/1365
//2568 전기줄 - 2 https://www.acmicpc.net/problem/2568
//11055 가장 큰 증가 부분 수열 https://www.acmicpc.net/problem/11055
//2532 먹이사슬 https://www.acmicpc.net/problem/2532
//1937 욕심쟁이 판다 https://www.acmicpc.net/problem/1937
//

#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1000

int seq1[1000];
//쉬운 dp
#define MAX_N 1001
int n;
int seq[MAX_N];
int dp[MAX_N];
int main() {
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (seq[j] < seq[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	return 0;
}

//lower_bound 이용시
int seq2[100000];
int dp2[100000];
int n = 100000;
int main() {

	dp[0] = seq[0];
	int size = 1;
	for (int i = 1; i < n; i++) {
		if (dp[size - 1] < seq[i]) {
			dp[size] = seq[i];
			size++;
		}
		else {
			dp[lower_bound(dp, dp + size, seq[i]) - dp] = seq[i];
		}
	}
	int ans = size;
	printf("%d\n", ans);
	return 0;
}