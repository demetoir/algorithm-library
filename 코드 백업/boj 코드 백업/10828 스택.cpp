#include <stdio.h>
#include <stack>
#include <string.h>
#include <iostream>

using namespace std;
stack <int> s;
int n;
char code[10];
int val;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	{
		scanf("%s", &code);
		string opcode(code);
		if (opcode == "push") {
			scanf("%d", &val);
			s.push(val);
		}
		if (opcode == "pop") {
			if (s.empty())printf("-1\n");
			else {
				printf("%d\n", s.top());
				s.pop();
			}
		}
		if (opcode == "top") {
			if (s.empty())printf("-1\n");
			else printf("%d\n", s.top());
		}
		if (opcode == "size") {
			printf("%d\n", s.size());
		}
		if (opcode == "empty") {
			printf("%d\n", s.empty());
		}
	}
	return 0;
}