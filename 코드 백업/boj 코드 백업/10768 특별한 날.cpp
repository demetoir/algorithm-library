#include <stdio.h>
#include <algorithm>

#define si(a) scanf("%d",&(a))
int a,b;

int main() {
	si(a);
	si(b);
	
	
	if (a < 2 || (a <= 2 && b < 18))
		printf("Before\n");
	else if (a == 2 && b == 18)
		printf("Special\n");
	else
		printf("After");

	return 0;
}

