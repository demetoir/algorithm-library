//fill 사용법
// 시간 복잡도 O(n)
// 헤더 <algorithm>
//범위내의 모든 원소를 value 로 바꾼다
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int result;
int main() {
	int A[10] = { 1,1,1,2,3,5,5,5,7,8 };

	int start = 3;
	int end = 7;

	fill(A + 3, A + 7, 0);

	//A = { 1,1,1,0,0,0,0,5,5,7,8 };

	return 0;
}











