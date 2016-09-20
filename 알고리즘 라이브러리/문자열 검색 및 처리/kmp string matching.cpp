//kmp (Knuth-Morris-Pratt)
//
//문자열 매칭 알고리즘
//한 패턴이 나타나는 모든 위치를 찾는다
//
//시간복잡도 O(N + H)
//N -> 패턴길이, H-> 짚더미 문자열 길이
//
//참고 자료
//https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
//http://codedoc.tistory.com/416
//http://carstart.tistory.com/143
//
//문제
//1786 찾기 https://www.acmicpc.net/problem/1786
//1701 Cubeditor https://www.acmicpc.net/problem/1701
//1305 광고 https://www.acmicpc.net/problem/1305
//4354 문자열 제곱 https://www.acmicpc.net/problem/4354
//
//검증됨
//
#include <vector>
using namespace std;
#define MAX_N 100001
#define MAX_H 100001
int pie[MAX_N];//실패 함수
int str[MAX_H];//찾을 짚더미
int patern[MAX_N];// 찾을 패턴
int h;//찾을 짚더비 길이
int n;//찾을 패턴 길이 

#define MAX_N 1000001
#define MAX_H 1000001
int pie[MAX_N];//실패 함수
char str[MAX_H];//찾을 짚더미
char patern[MAX_N];// 찾을 패턴
int h;//찾을 짚더비 길이
int n;//찾을 패턴 길이 
vector<int>ans;
void make_Pie() {
	//start =1 로 시작함  
	int start = 1, matched = 0;
	while (start + matched < n) {
		if (patern[start + matched] == patern[matched]) {
			matched += 1;
			pie[start + matched - 1] = matched;
		}
		else {
			if (matched == 0)start += 1;
			else {
				start += matched - pie[matched - 1];
				matched = pie[matched - 1];
			}
		}
	}
}

void kmp() {
	make_Pie();
	int matched_count = 0;
	int start = 0, matched = 0;
	while (start <= h - n) {
		//매칭 되었다
		if (str[start + matched] == patern[matched]
			&& matched < n) {
			matched += 1;
			if (matched == n)
				ans.push_back(start);
		}
		//안 됨...
		else {
			if (matched == 0) start++;
			else {
				start += matched - pie[matched - 1];
				matched = pie[matched - 1];
			}
		}
	}

	return;
}
