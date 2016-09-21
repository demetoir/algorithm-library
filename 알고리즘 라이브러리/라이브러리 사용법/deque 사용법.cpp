//deque 사용법
//
//헤더 deque
//
//양쪽으로 push pop 이 가능한 queue
//
//시간복잡도 
//push  O(1);
//pop O(1);
//
#include <deque>

using namespace std;

int main() {
	deque<int> dequei;
	dequei.push_back(1);
	dequei.push_back(2);
	dequei.push_back(3);
	dequei.push_back(4);
	dequei.push_back(5);
	// deque = {1,2,3,4,5}
	
	dequei.pop_back();
	//deque = {1,2,3,4}

	dequei.pop_front();
	//deque = {2,3,4}

	dequei.push_front(7);
	//deque = {7,2,3,4}

	return 0;
}





