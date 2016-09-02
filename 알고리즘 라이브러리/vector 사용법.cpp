//vector 사용법
//라이브러리 이름 vector
// 시간 복잡도
//push_back O(lg(1))
//size O(lg(1))v
//
//
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

	//개수 확인
	vi.size();
	//vi.size() -> 3

	//복사
	vector<int> vi2;
	vi2 = vi;
}
