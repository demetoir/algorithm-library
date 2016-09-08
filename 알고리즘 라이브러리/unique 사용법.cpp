//unique 사용법
// 시간 복잡도 O(?)
// 헤더 <algorithm>
//begin 부터 end 까지 같은 값을 제거한다
#include <vector>
#include <algorithm>
using namespace std;

//rotate(begin,mid,end)
//begin 부터 end 까지  mid 기준으로 왼쪽으로 회전한다
int main() {
	int x = 5, y = 87;
	//x == 5, y==87
	swap(x, y);
	//x == 87, y==5

	vector<int>a({ 1,2,3 });
	vector<int>b({ 5,6,7,8 });

	//a = {1,2,3}, b = {5,6,7,8}
	swap(a, b);
	//a = {5,6,7,8}, b = {1,2,3} 

	return 0;
}
