#include <stdio.h>
#include <algorithm>

#define si(a) scanf("%d",&(a))
int v, e;

int main() {
	int  testcase = 0;
	si(testcase);
	for (int test = 0; test < testcase; test++){
		si(v);si(e);
		printf("%d\n", e - v + 2);
	}
	
	return 0;
}

