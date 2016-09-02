//lowerbound 사용법
//시간 복잡도 O(log(n))
//
//선행조건
//찾고자 하는 배열은 미리 오름차순으로 정렬 되어야한다
//
//문제
//
//


#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

int main() {
	//일반 배열 사용시
	int A[10] = { 2,6,4,3,2, 1,5,3,2,5 };

	sort(A, A + 10);
	//A={1,2,2,2,3,3,4,5,5,6}

	//찾고자하는 값
	int val = 3;

	//찾고자하는값이 나타나는 첫번쨰 index 반환
	int index = lower_bound(A, A + 10, val) - A;
	// index -> 4

	//찾고자하는값을 바로 쓰기
	int *temp = lower_bound(A, A + 10, val);
	//*temp -> 3


	//vecter 사용시
	vector<int> vi;
	vi.push_back(2);
	vi.push_back(6);
	vi.push_back(4);
	vi.push_back(3);
	vi.push_back(2);
	vi.push_back(1);
	vi.push_back(5);
	vi.push_back(3);
	vi.push_back(2); 
	vi.push_back(5);
	//vi = { 2,6,4,3,2,1,5,3,2,5 };


	//찾고자하는 값
	int val = 3;

	//찾고자하는값이 나타나는 첫번쨰 index 반환
	int index = lower_bound(vi.begin(), vi.end(), val) - vi.begin();
	// index -> 4

	//찾고자하는값을 바로 쓰기
	vector<int>::iterator iter = lower_bound(vi.begin(), vi.end(), val) ;
	iter;
	//*temp -> 3




}