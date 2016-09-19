//find 사용법
// 시간 복잡도 O(n)
// 헤더 <algorithm>
//범위내의 원소중 value 의 갯수를 찾는다

//문제
// 10809
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int result;
int main() {
	int A[10] = { 1,1,1,2,3,5,5,5,7,8 };

	int val = 5;
	for (int i = 0; i < 10; i++) {
		auto it = find(A, A + 10, i);
		cout << i << "의 위치 : ";
		if (it == A + 10)
			cout << "찾을 수 없음";
		else {
			cout << (it - A);
		}
		cout << endl;
	}

	return 0;
}











