//lowerbound 사용법
//시간 복잡도 O(log(n))
//
//선행조건
//찾고자 하는 배열은 미리 오름차순으로 정렬 되어야한다
//
//주의 사항
//찾는 값이 존재 하지 않을떄와 여러개 존재할떄의 예외를 생각한다
//
//원소를 삽입했을때 정렬상태가 꺠지지 않은 위치중 가장 작은 위치를 반환한다
//
//
//문제
//10815
//
//
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

int main() {
	//일반 배열 사용시
	int A[10] = { 1,2,2,2,5,7,7,7,10,20 };

	sort(A, A + 10);
	//A={1,2,2,2,5,7,7,7,10,20}

	//찾고자하는 값
	int val = 5;

	//찾고자하는값이 나타나는 첫번쨰 index 반환
	int index = lower_bound(A, A + 10, val) - A;
	// index -> 4

	//찾고자하는값을 바로 쓰기
	int *temp = lower_bound(A, A + 10, val);
	//*temp -> 3

	//찾는 값이 없을때
	val = -1;
	index = lower_bound(A, A + 10, val) - A;
	//index = 0

	val = 4;
	index = lower_bound(A, A + 10, val) - A;
	//index = 4

	val = 45;
	index = lower_bound(A, A + 10, val) - A;
	//index = 10
	//이떄 배열의 범위를 벋어나기 때문에 주의한다 

	//찾는 값이 여러개일떄
	val = 2;
	index = lower_bound(A, A + 10, val) - A;
	//index = 1
	//찾는 값이 여러개일떄 배열상에서 그 값의 가장 왼쪽 위치를 반환한다
	//오른쪽위치를 사용하고 싶을때는 upper_bound 를 사용한다

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
	val = 3;

	//찾고자하는값이 나타나는 첫번쨰 index 반환
	index = lower_bound(vi.begin(), vi.end(), val) - vi.begin();
	// index -> 4

	//찾고자하는값을 바로 쓰기
	vector<int>::iterator iter = lower_bound(vi.begin(), vi.end(), val);
	printf("%d\n", *iter);
	//*iter -> 3



	return 0;
}