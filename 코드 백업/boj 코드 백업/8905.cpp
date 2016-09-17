// 8905.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string alpha[128];
string A, B;
int T;
int K;
int Ai, Bi;
int ans;


int find(int i, int j) {
	int ret = false;
	if (i == A.size() && j == B.size()) {
		//for (int c = 'a'; c <= 'z'; c++) {
		//	if (alpha[c] == "")continue;
		//	cout << (char)c <<" "<< alpha[c] << endl;
		//}
		ans = 1;
		return 1;
	}
	if (i >= A.size() || j >= B.size()) {
		return false;
	}	
	string cur = "";
	for (int k = 0; k < K; k++) {
		if (j + k >= B.size()) continue;
		cur += B[j+k];
		if (alpha[A[i]] == "") {
			alpha[A[i]] = cur;
			ret = find(i + 1, j + k+1);
			alpha[A[i]] = "";
			if (ans == true) return true;
		}		
		else if (alpha[A[i]] == cur) {
			ret = find(i + 1, j + k + 1);
			if (ans == true) return true;
		}
	}
	return false;
}

int main(){
	scanf("%d", &T);
	while (T--) {
		cin >> K >> A >> B;

		for (int i = 0; i < 128; i++) {
			alpha[i] = "";
		}
		ans = 0;

		find(0, 0);
		printf("%d\n", ans);
	}

    return 0;
}

