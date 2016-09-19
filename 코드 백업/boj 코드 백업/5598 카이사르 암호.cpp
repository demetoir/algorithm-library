#include <stdio.h>
using namespace std;

int main() {
	char c;
	while (1) {
		scanf("%c", &c);
		if (c == '\n')break;
		printf("%c", ((c- 'A' - 3 + 'Z' - 'A' + 1) % ('Z' - 'A'+1)) + 65);
	}
	printf("\n");
	return 0;
}