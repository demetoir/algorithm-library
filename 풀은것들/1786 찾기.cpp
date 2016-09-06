#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>

using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sc(a) scanf("%c",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define pii pair<int,int>
#define INF 2e9
#define LLINF ( (((LL)1) <<63)  -1)
#define AND &&
#define OR ||
#define FOR(i,s,e) for (int i = s; i<e; i++)
#define all(a) (a).begin(),(a).end()
//////////////////////////////////////////////////////////////////////////////////
//1786 찾기
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

int main() {
	gets_s(str);
	gets_s(patern);
	n = strlen(patern);
	h = strlen(str);

	kmp();
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i] + 1);
	}


	return 0;
}