//검증 필요

//소수 판별법
//
//한 개의 수의 소수 판별법
//시간 복잡도 O(root(n))
//
//에라토스테네스의 체
//시간 복잡도 
//전처리 O(n)
//판별 O(1)
//
//체를 이용한 소인수 분해
//
//참고자료
//
//
//
//문제 
//
#include <vector>
using namespace std;

//한 개의 수의 소수 판별법
bool is_prime(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0)return false;
	}
	return true;
}

//에라토스테네스의 체
#define MAX_N 100000
vector<bool> seive;// 체
vector<int> prime;// 소수가 들어있는 벡터
void make_seive(int size) {
	seive = vector<bool>(size, true);
	seive[0] = seive[1] = false;
	for (int i = 2; i < size; i++) {
		if (seive[i] == false)continue;
		prime.push_back(i);
		for (int j = i + i; j < size; j += i)
			seive[j] = false;
	}
}

//체를 이용한 소인수 분해
#define MAX_N 100000
vector<int> seive;// 체
vector<int> prime;// 소수가 들어있는 벡터
void make_seive(int size) {
	seive = vector<bool>(size, 1);
	seive[0] = 0;
	seive[1] = 1;
	for (int i = 2; i < size; i++) {
		if (seive[i] > 1)continue;
		prime.push_back(i);
		for (int j = i + i; j < size; j += i)
			seive[j] = i;
	}
}

int integer_factorization(int n, vector<int> &factor) {
	while (n > 1) {
		factor.push_back(seive[n]);
		n = n / seive[n];
	}
}

