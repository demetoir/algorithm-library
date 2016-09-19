//reverse 사용법
// 시간 복잡도 O(n)
// 헤더 <algorithm>
//범위 내의 원소의 순서를 역순으로 만든다
//문제
//10811
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vi({ 1,2,3,4,5 });

	//vi = {1,2,3,4,5}
	reverse(vi.begin(), vi.end());
	//vi = {5,4,3,2,1}

	return 0;
}
