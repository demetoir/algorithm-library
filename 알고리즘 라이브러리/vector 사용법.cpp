//vector 사용법
//라이브러리 이름 vector
//
//시간 복잡도
//push_back O(1)
//size O(1)
//접근 O(1)
//

#include <vector>
using namespace std;

int main() {
	//선언
	vector<int> vi;
	vector<long long> vll;
	
	//초기화 방법
	vi.clear();
	//결과 vi = {}

	//특정한 값과 길이를 가지게 초기화 
	int n = 5;
	int val = -1;
	vi.assign(n,val);
	//결과 vi = {-1,-1,-1,-1,-1}

	//삽입 
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	// 결과값
	// vi= {1,2,3}

	//접근 
	vi[1];
	//vi[1] -> 2

	//개수 확인
	vi.size();
	//vi.size() -> 3

	//vector 안의 모든 원소 접근
	for (int i = 0; i < vi.size(); i++) {
		vi[i];
	}

	//복사
	vector<int> vi2;
	vi2 = vi;
}
