//binary_search 사용법
//
//시간복잡도 O(log(n))
//
//해더 algorithm
//
//
//binary_search(begin,end,value)
//[begin 부터 end) 까지 value있으면 true 없으면 false
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int>vi({ 1,2,3,4,6,7,8});

	bool isfind = false;
	int val = 3;
	isfind = binary_search(vi.begin(), vi.end(), val);
	//isfind = true


	val = 5;
	isfind = binary_search(vi.begin(), vi.end(), val);
	//isfind = false
	return 0;
}






