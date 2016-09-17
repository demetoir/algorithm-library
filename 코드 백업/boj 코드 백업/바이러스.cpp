#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <string.h>

using namespace std;

vector<int> iv;
vector<int>::iterator iit;
vector<double> dv;
priority_queue <int> PQ;
queue <int>  Q;
map<int, string> istrmap;
map <long long, int>iimap;
struct mp {
	int a, b;
};
#define ABS(a)(((a) < (0))?-(a):(a))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


int n, m, K, L;
int G[101][101];

int dist[1000001];
///////////////1000000000
#define MAXDIS 1234567890;
vector <int > start;
long long ans = 0;
int dir[1000001];
int vlevel[101];
int vdelete[101];
int number;
int vl[101];
int G2[101][101];
void init() {

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			G[i][j] = 0;
		}
		vlevel[i] = 0;
		vdelete[i] = 0;
	}
	ans = 0;
}
//차수가 작은거 부터 제거함
void f1() {
	while (1) {
		int flag = false;
		for (int i = 1; i < n + 1; i++) {
			if (vlevel[i] < K&& vlevel[i] >0) {
				flag = true;
				vlevel[i] = 0;
				for (int j = 1; j < n + 1; j++) {
					if (G[i][j] == 1) {
						vlevel[j] -= 1;
					}
					G[i][j] = 0;
					G[j][i] = 0;
				}
			}
		}
		if (flag == false) { break; }
	}
	for (int i = 1; i < n + 1; i++) {
		if (vlevel[i] == 0) {
			//printf("## %d\n", i);
			ans += i;
			vdelete[i] = 1; 
			vlevel[i] = -1;
		}
	}
}

int maxlevel() {
	int ret = 0;
	for (int i = 1; i < n + 1; i++) {
		ret = MAX(ret, vlevel[i]);
	}
	return ret;
}

void f2() {

	
	while (number != 0) {
		//최소 지움값을 찾음
		if (maxlevel() <= number - 1 - L) {
			break;
		}
		int index =0;
		int val = -1;
	
		//가장 크고 빠른놈을 선택
		for (int i = 1; i < n + 1; i++) {
			if (val < vlevel[i]) {
				index = i;
				val = vlevel[i];
			}
		}
		//그놈을 제거한다
		vlevel[index] = -1;
		for (int i = 1; i < n + 1; i++) {
			if (G[index][i] == 1) {
				G[i][index] = 0;
				vlevel[i] -= 1;
				G[index][i] = 0;
			}
		}
		ans += index;
		number -= 1;
		//printf("## %d\n", index);

	}
}
int main(int argc, char** argv) {
	//setbuf(stdout, NULL);

	int TC;
	scanf("%d", &TC);	// cin 사용 가능
	for (int test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		scanf("%d %d ", &K, &L);
		scanf("%d %d", &n, &m);

		init();
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			G[a][b] = 1;
			G[b][a] = 1;
			vlevel[a] += 1;
			vlevel[b] += 1;

		}

		while (1) {
			f1();
			//printf("\n");
			number = 0;
			for (int i = 1; i < n + 1; i++) {
				if (vlevel[i] >= 0)
					number += 1;
			}
			int oldval = number;

			f2();
			//printf("\n");
			if (oldval == number)
				break;
		}

		
		// 이 부분에서 정답을 출력하십시오.


		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%lld\n", ans);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}