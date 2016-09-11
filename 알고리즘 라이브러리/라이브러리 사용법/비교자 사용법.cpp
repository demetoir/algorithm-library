//비교자 사용법
//
//주의사항
//콜백 함수의 반환형은 bool 이어야함
//콜백 함수의 인자는 2개이며 인자의 서로 같은 타입이어야한다

#include <vector>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;
#define pii pair<int,int>

struct triple{
	int a, b, c;
	triple(int _a, int _b, int _c) 
		:a(_a), b(_b), c(_c) {};
};

bool int_cmp(int a, int b) {
	return a < b;
}

bool pii_cmp(pii A, pii B) {
	if (A.first != B.first) return A.first < B.first;
	return A.second < B.second;
}

bool triple_cmp(triple A, triple B) {
	if (A.a != B.a) return A.a < B.a;
	if (A.b != B.b) return A.b < B.b;
	return A.c < B.c;
}

bool int_cmp_reverse(int a, int b) {
	return a > b;
}

bool pii_cmp_reverse(pii A, pii B) {
	if (A.first != B.first) return A.first > B.first;
	return A.second > B.second;
}

bool triple_cmp_reverse(triple A, triple B) {
	if (A.a != B.a) return A.a > B.a;
	if (A.b != B.b) return A.b > B.b;
	return A.c > B.c;
}

int main() {
	vector<int> v_int;
	vector<pii> v_pii;
	vector<triple> v_triple;

	v_int.push_back(5);
	v_int.push_back(3);
	v_int.push_back(1);
	v_int.push_back(2);
	v_int.push_back(4);
	//v_int = {5,3,1,2,4}

	v_pii.push_back(pii(4,1));
	v_pii.push_back(pii(3,2));
	v_pii.push_back(pii(3,1));
	v_pii.push_back(pii(1,4));
	v_pii.push_back(pii(2,2));
	//v_pii = {(4,1),(3,2),(3,1),(1,4),(2,2)}

	v_triple.push_back(triple(3,2,4));
	v_triple.push_back(triple(1,3,3));
	v_triple.push_back(triple(2,2,1));
	v_triple.push_back(triple(1,3,5));
	v_triple.push_back(triple(2,1,6));
	//v_triple = {(3,2,4),(1,3,3),(2,2,1),(1,3,5),(2,1,6)}

	//오름차순 sort

	sort(v_int.begin(), v_int.end(), int_cmp);
	//결과 v_int ={1,2,3,4,5}
	sort(v_pii.begin(), v_pii.end(), pii_cmp);
	//결과 v_pii = {(1,4),(2,2),(3,1),(3,2),(4,1)}
	sort(v_triple.begin(), v_triple.end(), triple_cmp);
	//결과 v_triple = {(1,3,3),(1,3,5),(2,1,6),(2,2,1),(3,2,4)}


	//내림차순 sort
	sort(v_int.begin(), v_int.end(), int_cmp_reverse);
	//결과 v_int = {5,4,3,2,1}
	sort(v_pii.begin(), v_pii.end(), pii_cmp_reverse);
	//결과 v_pii = {(4,1),(3,2),(3,1),(2,2),(1,4)}
	sort(v_triple.begin(), v_triple.end(), triple_cmp_reverse);
	//결과 v_triple = {(3,2,4),(2,2,1),(2,1,6),(1,3,5),(1,3,3)}

}