// tuple 사용법
// 헤더 tuple
//
#include <tuple>
#include <iostream>
using namespace std;
int main() {
	//선언
	tuple<int, int, int> tupleiii = make_tuple(3,2,1);

	//접근
	cout << get<0>(tupleiii) << endl;
	cout << get<0>(tupleiii) << endl;
	cout << get<0>(tupleiii) << endl;

	//get으로 수정은 못함
	//이거 쓸바에야 구조체 만드는게 나을듯
	return  0;
}