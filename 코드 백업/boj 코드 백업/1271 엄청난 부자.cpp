#include <stdio.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d\n", &n, &m);

	printf("%d\n%d", n / m, n%m);

	return 0;
}