//이분탐색
//
//시간 복잡도 O(log(n))
//
//선행 조건
//찾으려는 자료는 단조 증가 이어야한다
//
//참고 자료
//
//문제
//

using namespace std;
#define MAX_N 10000000
int A[MAX_N];
int bi_search(int x) {
	int low = 0;
	int high = MAX_N - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (A[mid] == x)
			return mid;
		else if (A[mid] < x) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}
	return -1;
}
