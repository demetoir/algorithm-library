//sort 사용법
//라이브러리 : algorithm
//defualt로 오름차순 정렬
//시간복잡도 O(nlog(n))
//문제 
//
//2750
//1181
//11650
//11651
//10825
//10814

#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main() {
	// 일반 배열 sort
	int A[5] = {3,4,2,1,3};
	sort(A, A + 5);

	//sort(A, A + A의 길이) 
	//결과 A = {1,2,3,3,4}

	// vector sort
	vector<int> vi;
	vi.push_back(3);
	vi.push_back(4);
	vi.push_back(2);
	vi.push_back(1);
	vi.push_back(3);

	sort(vi.begin(), vi.end());
	//결과 vi = {1,2,3,3,4}

	//내림차순으로 정렬
	sort(A, A+5, greater<int>());
	//결과 vi = {4,3,3,2,1}

	sort(vi.begin(), vi.end(), greater<int>());
	//결과 vi = {4,3,3,2,1}

}


