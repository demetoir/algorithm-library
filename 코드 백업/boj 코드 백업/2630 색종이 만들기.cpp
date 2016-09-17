#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

#define LL long long
#define MP pair < int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define sS(a) scanf("%s",a)
#define INF 1234567890
#define INFLL 12345678912345678

//////////////////////////////////////////////////////////////////////////////////


#define MAX_N 100
int n;
int board[128][128];
int ans1, ans2;
void find(int x1,int x2,int y1,int y2) {
	int flag=0;

	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++)
			if (board[x1][y1] != board[i][j]) {
				flag = 1;
				break;
			}
	}

	if (flag == 0) {
		if (board[x1][y1] == 0)
			ans1 += 1;
		else
			ans2 += 1;
		return;
	}
	int xmid = (x2 - x1) / 2 +x1;
	int ymid = (y2 - y1) / 2 +y1;

	find(x1, xmid, y1, ymid);
	find(xmid+1, x2, y1, ymid);
	find(x1, xmid, ymid+1, y2);
	find(xmid+1, x2, ymid+1, y2);

}
int  main() {
	si(n);
	for(int i =0; i<n; i++)
		for (int j = 0; j < n; j++) {
			si(board[i][j]);
		}

	find(0, n - 1, 0, n - 1);


	printf("%d\n", ans1);
	printf("%d\n", ans2);

	return 0;
}











