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

////////////////////////////////////////////////////////////////////////////////
#define MAX_N 20

int memo1[MAX_N + 1][MAX_N + 1];
int memo2[MAX_N + 1][MAX_N + 1];

int n,k;
int a, b;
int ans = INF;

int  main() {
	si(n);
	si(a); si(b);
	si(k); 
	

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			memo1[i][j] = INF;
			memo2[i][j] = INF;
		}
	}
	memo1[a][b] = 0;

	for (int i = 0,val,cur = INF; i < k; i++) {
		si(val);

		for (int i = 1; i <= 20; i++) {
			for (int j = 1; j <= 20; j++) {
				memo2[i][j] = INF;
			}
		}

		for (int i = 1; i <= 20; i++) {
			for (int j = i+1; j <= 20; j++) {
				if(i)
				if (memo1[i][j] == INF) continue;

				for (int x = 1; x <= 20; x++) {
					for (int y = x+1;y <= 20; y++) {
						if (x != val && y != val) continue;

						int plus = abs(i - x) + abs(j - y);
						memo2[x][y] = min(memo1[i][j]+ plus, memo2[x][y]);
						cur = min(memo2[x][y], cur);
					}
				}
			}
		}
		//memo2 = memo1
		for (int i = 1; i <= 20; i++) {
			for (int j = 1; j <= 20; j++) {
				memo1[i][j] = memo2[i][j];
			}
		}


	}

	
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			ans = min(memo1[i][j], ans);
		
		}
	}

	printf("%d\n", ans);

	return 0;


}











