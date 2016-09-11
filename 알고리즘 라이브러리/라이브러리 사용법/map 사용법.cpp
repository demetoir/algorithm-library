//map 사용법
//라이브러리 : map
//
//시간 복잡도
//추가 O(log(n))
//갱신 O(log(n))
//제거 O(log(n))
//접근 O(log(n))

#include <map>
using namespace std;

int main() {
	//선언
	map<int, int> mii;
	map<int, long long> mill;
	//map<key,value>
	

	//초기화
	mii.clear();
	mii = map<int, int>();

	//추가 및 갱신
	mii[3] = 10;
	mii[1] = 20;
	mii[2] = 30;
	mii[4] = 40;

	//제거
	//mii.erase();
	
	//접근
	mii[3];
	//mii[3] = 10
	


}