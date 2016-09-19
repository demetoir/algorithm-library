//rotate 사용법
// 시간 복잡도 O(n)
// 헤더 <algorithm>
//범위 내의 원소의 순서왼쪽으로 회전 시킨다
//문제 10812
#include <vector>
#include <algorithm>
using namespace std;

//rotate(begin,mid,end)
//begin 부터 end 까지  mid 기준으로 왼쪽으로 회전한다
int main() {
	vector<int> vi({ 1,2,3,4,5 });

	//vi = {1,2,3,4,5}
	rotate(vi.begin(), vi.begin()+2,vi.end());
	//vi = {3,4,5,1,2}

	return 0;
}
