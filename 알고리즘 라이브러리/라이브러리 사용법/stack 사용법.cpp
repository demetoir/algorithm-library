//stack 사용법
//라이브러리 이름 stack
//시간복잡도
//push O(1)
//pop O(1)
//top O(1)
//문제
//10828

#include <stack>
using namespace std;

int main() {
	//선언
	stack<int> st;

	//초기화 
	st = stack<int>();

	//push 
	st.push(1);
	st.push(2);
	st.push(3);
	//st = {1,2,3}

	//pop()
	int val = st.top(); st.pop();
	//val = 3

	// 비어있는지 검사
	st.empty();
	//비어있으면 true 반환


	// 루프 사용할때
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
	}

}
