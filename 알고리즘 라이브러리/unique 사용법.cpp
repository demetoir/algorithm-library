//unique 사용법
// 시간 복잡도 O(?)
// 헤더 <algorithm>

#include <vector>
#include <algorithm>
using namespace std;

//unique(begin,end)
//begin 부터 end 까지 연속되는 중복된값을 제거한다
//따라서 정렬된상태여야 모든원소에 대해 중복되지 않게 된다
int main() {
	vector<int> vi1({ 1,2,3,4,4,4,4,1,2,3,1,2 });
	vector<int> vi2({ 1,2,3,4,4,4,4,1,2,3,1,2 });

	vi1.erase(unique(vi1.begin(), vi1.end()), vi1.end());
	//vi1 = {1,2,3,4,1,2,3,1,2}

	sort(vi2.begin(), vi2.end());
	vi2.erase(unique(vi2.begin(), vi2.end()), vi2.end());
	//vi1 = {1,2,3,4}


	return 0;
}
