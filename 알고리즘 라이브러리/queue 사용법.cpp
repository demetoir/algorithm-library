//queue 사용법
//라이브러리 이름 queue
//시간복잡도
//push O(lg(1))
//pop O(lg(1))
//front O(lg(1))

#include <queue>
using namespace std;

int main() {
	//선언
	queue<int> q;

	//초기화 
	q = queue<int>();

	//push 
	q.push(1);
	q.push(2);
	q.push(3);

	//pop()
	int val =q.front(); q.pop();

	// 비어있는지 검사
	q.empty();
	//비어있으면 true 반환


	// 루프 사용할때
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
	}

}
