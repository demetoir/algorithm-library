//결정 문제 이분탐색
//
//시간 복잡도 O(log(LIMIT) * O(deterministic function) )
//
//참고 자료
//
//문제
//1654 랜선 자르기
//1150 백업
//2110 공유기 설치
//2485 가로수
//2805 나무자르기
//3079 입국심사
//1939 중량제한
//1981 배열에서 이동

//최적해가 최대일떄 코드 틀

#define MINLIMIT 0		// 이분탐색을 할 범위
#define MAXLIMIT 2e9 // 

bool ispossible(int x) {
	//deterministic function
	//그리디 또는 dp 로 해결할수있는 문제
	//x 이하로 가능한가
	//
	//return bool
}
int bi_search() {	
	int lo = MINLIMIT, hi = MAXLIMIT;
	int ans;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (ispossible(mid)) {
			lo = mid + 1;
			ans = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	return ans;
}













