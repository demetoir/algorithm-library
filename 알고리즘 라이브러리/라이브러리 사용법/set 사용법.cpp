//set 사용법
//
//헤더 set

//문제 
//중복 뺴고 정렬하기 10867
//10815
//10816


#include <set>
using namespace std;

int main() {
	//선언
	set<int> seti;

	//삽입
	seti.insert(1);
	seti.insert(2);
	seti.insert(3);
	seti.insert(4);
	//set  = {1,2,3,4}

	//삽입하면서 이미 있는 원소인지 확인하기
	auto result = seti.insert(7);
	//result = pair(7,true)
	auto result = seti.insert(3);
	//result = pair(3,false)

	//삭제하기
	seti.erase(3);
	//seti = {1,2,4,7}
	seti.erase(seti.begin());
	//seti = {2,4,7}

	//크기 
	seti.size();
	// seti.size() == 4

	//위치 찾기









	return  0;
}
