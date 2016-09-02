//priority_queue 
//라이브러리 이름 queue
//
//default 로 오름차순이다
//
//시간복잡도
//push O(lg(n))
//pop O(lg(n))
//top O(lg(1))

#include <queue>
#include <functional>
using namespace std;
#define pii pair<int,int>

int main() {
	//선언
	priority_queue<int>pq;
	priority_queue<pii>pq_pair;

	//초기화
	pq = priority_queue<int>();

	//push
	pq.push(4);
	pq.push(3);
	pq.push(2);
	pq.push(1);
	//pq = {1,2,3,4}

	//pop
	int val = pq.top();
	pq.pop();
	//val -> 1
	// pq = {2,3,4}


	//내림차순으로 priority_queue 사용하기

	//greater를 사용해서 선언으로 하기
	priority_queue<int,vector<int>, greater<int> > pq;
	//priority_queue<T,vector<T>, greater<T> > pq;


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
	//pq ={(1,1),(1,3),(2,2),(2,3),(3,1),(4,1)}	
	
	//pop
	pii temp = pq_pair.top(); pq_pair.pop();
	//temp -> (1,1)

}