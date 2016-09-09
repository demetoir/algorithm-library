//카탈란 수(Catalan number)
//
//시간 복잡도
//
//참고자료
//http://wiki.mathnt.net/index.php?title=%EC%B9%B4%ED%83%88%EB%9E%80_%EC%88%98_(Catalan_numbers)
//https://en.wikipedia.org/wiki/Catalan_number
//http://suhak.tistory.com/77
//
//
//
//문제
//
//수열 : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012
//
using namespace std;

//계단 격자 최단경로 수 dp
#include <string.h>
#define MAX_N 1000
int catalan1[MAX_N][MAX_N];
void make_Catalan1() {
	memset(catalan1, 0, sizeof(catalan1));
	for (int i = 1; i < MAX_N; i++)
		catalan1[1][i] = 1;

	for (int i = 2; i < MAX_N; i++) {
		for (int j = i; j < MAX_N; j++) {
			catalan1[i][j] = catalan1[i - 1][j] + catalan1[i][j - 1];
		}
	}

	return;
}


//점화식 dp
#define MAX_N 100000
int catalan2[MAX_N];
void make_Catalan2() {
	catalan2[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		int val = 0;
		for (int j = 0; j <= i; j++) {
			val += catalan2[j] * catalan2[i - j];
		}
	}
	return;
}

//홀로노믹 수열 dp
#define MAX_N 100000
int catalan3[MAX_N];
void make_Catalan3() {
	catalan3[1] = 1;
	for (int i = 2; i < MAX_N; i++) {
		catalan3[i] = (catalan3[i - 1] * (4 * i - 2)) / (i + 1);
	}
	return;
}