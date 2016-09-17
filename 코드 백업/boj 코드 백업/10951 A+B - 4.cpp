#include <stdio.h>
using namespace std;

#define si(a) scanf("%d",&(a))

int main() {
	int testcase, a, b;
	while (1){
		if (scanf("%d %d",&a,&b) != 2) break;

		printf("%d\n", a + b);
	}
	return 0;
}