#include <stdio.h>
using namespace std;

#define MAX_N 100000
char s[MAX_N];
int ans;
int scount;
int main() {
	scanf("%s", s);
	for (int i = 0; s[i] != 0; i++) {
		if (s[i] == '(') 
			scount += 1;		
		else {
			scount -= 1;
			if (s[i - 1] == '(') 
				ans += scount;			
			else 
				ans++;			
		}
	}
	printf("%d\n", ans);
	return 0;
}