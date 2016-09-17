#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
#define MAX_N 1000000
#define MAX_P 36

char str[MAX_N];
char p[MAX_P];
char res[MAX_N];

stack < char > ans;
stack < int > s;

int main() {
	scanf("%s", str);
	scanf("%s", p);
	int n = strlen(str);
	int m = strlen(p);

	for (int i = 0, index = 0; i<n; i++) {
		ans.push(str[i]);
		if(str[i] == p[index]){
			index++;
			if (index == m) {
				for (int j = 0; j < m; j++) 
					ans.pop();
				
				index = 0;
				if (!s.empty()) {
					index = s.top();
					s.pop();
				}
			}
		}
		else {
			if (str[i] == p[0]) {
				s.push(index);
				index = 1;
			}
			else {
				index = 0;
				while (!s.empty())
					s.pop();
			}
		}		
	}


	if (ans.empty())
		printf("FRULA\n");
	else {
		int size = ans.size();
		for (int i = 0; !ans.empty(); i++) {
			res[i] = ans.top();
			ans.pop();
		}
		for (int i = size-1; i>=0 ; i--) {
			printf("%c", res[i]);
		}
		printf("\n");
	}
	return 0;
}