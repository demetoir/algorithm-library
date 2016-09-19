// stl count 사용법
// 시간 복잡도 O(n)

// 헤더 <algorithm>
//
//범위내에서 원소 중 원하는 값의 갯수를 찾는다
//
//문제 
//10807
//10808

#include <algorithm>
#include <vector>

using namespace std;
int result;
int main() {
	int A[10] = { 1,1,1,2,3,5,5,5,7,8 };
	
	int val = 5;
	result = count(A, A + 10, val);
	//result == 3

	vector< int> vi({ 1,1,1,2,3,5,5,5,7,8 });

	val = 1;
	result = count(vi.begin(), vi.end(), val);
	//result == 3

	return 0;
}








