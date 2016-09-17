#include <stdio.h>
using namespace std;

#define si(a) scanf("%d",&(a))

int main() {
	int testcase,a,b;
	si(testcase);
	for (int test = 0; test < testcase; test++){
		si(a); si(b);
		printf("%d\n", a + b);
	}
	return 0;
}