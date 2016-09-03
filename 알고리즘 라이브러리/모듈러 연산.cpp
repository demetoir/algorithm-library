//모듈러 연산
//
//참고 자료
//http://egloos.zum.com/eyestorys/v/3544600
//
//
//
//
//
int main() {
	int a = 7;
	int b = 94;
	int mod = 17;

	(a + b) % mod == (a%mod + b%mod) % mod;
	//true

	(a - b) % mod == (a%mod - b%mod + mod) % mod;
	//true

	(a * b) % mod == (a%mod * b%mod) % mod;
	//true

	(a / b) % mod == (a%mod / b%mod) % mod;
	//false

	(a / b) % mod == (a%mod*(1 / b) % mod) % mod;;
	//true
	//moduler inverse
}