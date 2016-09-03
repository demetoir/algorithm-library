//priority_queue 
//라이브러리 이름 queue
//
//default로 내림차순이다
//
//시간복잡도
//push O(lg(n))
//pop O(lg(n))
//top O(1)
//
//참고 자료
//http://koosaga.myungwoo.kr/entry/STL-priority-queue-%ED%99%9C%EC%9A%A9%EB%B2%95
//
#include <queue>
#include <functional>
using namespace std;
#define pii pair<int,int>

struct triple {
	int a, b, c;
};

//구조체 사용시에는 연산자 오버로딩을 이용한다
//연산자 오버로딩시 < 이것만 된다 > 이것은 priority_queue 에서 인식 못한다
bool operator <(triple a, triple b) {
	//some compare logic
}

int main() {
	//선언
	priority_queue<int>pq;
	priority_queue<pii>pq_pair;
	priority_queue<triple>pq_triple;

	//초기화
	pq = priority_queue<int>();

	//push
	pq.push(4);
	pq.push(3);
	pq.push(2);
	pq.push(1);
	//pq = {4,3,2,1}

	//pop
	int val = pq.top();
	pq.pop();
	//val -> 4
	//pq = {3,2,1}


	//오름차순으로 priority_queue 사용하기

	//greater를 사용해서 선언으로 하기
	priority_queue<int,vector<int>, greater<int> > pq;
	//priority_queue<T,vector<T>, less<T> > pq;


	//선언은 그대로 하고 원소값의 부호를 바꾸어 사용함
	priority_queue<int>pq;

	//push
	int val = 5;
	pq.push(-val);

	//pop
	int temp = -pq.top(); 
	pq.pop();
	
	//pair 를 이용한 priority_queue 사용하는 방법
	priority_queue<pii> pq_pair;

	//push
	pq_pair.push(pii(4, 1));
	pq_pair.push(pii(3, 1));
	pq_pair.push(pii(1, 3));
	pq_pair.push(pii(1, 1));
	pq_pair.push(pii(2, 2));
	pq_pair.push(pii(2, 3));
	//pq ={(4,1),(3,1),(2,3),(2,2),(1,3),(1,1)}	
	
	//pop
	pii temp = pq_pair.top(); pq_pair.pop();
	//temp -> (4,1)

}