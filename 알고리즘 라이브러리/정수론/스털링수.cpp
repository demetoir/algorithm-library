//스털링 수
//
//시간 복잡도
//
//참고자료
//
//문제
//https://ko.wikipedia.org/wiki/%EC%8A%A4%ED%84%B8%EB%A7%81_%EC%88%98#.EC.84.B1.EC.A7.88
//
using namespace std;
// 1종 스털링 수
//점화식
//f(n+1,m) = n*f(n,m)-f(n,m-1)
//
//base case
//m>n =>f(n,m) = 0
//m =1 => f(n,m) = (n-1)!
//m =n => f(n,m) = 1
using namespace std;
#define MAX_N 12
int Stirling[MAX_N][MAX_N];
void make_Stirling() {
	Stirling[0][0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		Stirling[i][1] = Stirling[i - 1][1] * (i - 1);
		Stirling[i][i] = 1;
		for (int j = 2; j < i; j++) {
			Stirling[i][j] = (i - 1)*Stirling[i - 1][j] + Stirling[i - 1][j - 1];
		}
	}
}

