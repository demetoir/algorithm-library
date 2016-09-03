//유클리드 호제법
//
//최대공약수와 최소공배수를 빠르게 구하는 방법
//
//시간 복잡도 : O( log2(min(a, b)) )
//
//참고자료
//https://en.wikipedia.org/wiki/Euclidean_algorithm
//https://opentutorials.org/course/1685/9533
//
//문제
//
//
//

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, b%a);
}

int main() {
	int a = 16;
	int b = 28;

	//최대 공약수
	int gcd_val = gcd(a, b);

	//최소 공배수
	//오버플로우의 위험이있다
	int lcm_val = (a*b) / gcd_val;
}