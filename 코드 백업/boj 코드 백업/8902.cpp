#include <stdio.h>
#include <string.h>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define maxlen 5234

#define forn(i,n) for(int i=0;i<n;i++)
#define for_se(i,start,end) for(int i=start;i<end;i++)

int Alen, Blen;
int colornumber[30];

struct val {
	int curcolornum[30];
	int sum;
};

char A[maxlen];
char B[maxlen];
val memo1[maxlen], memo2[maxlen];
int ret;

void set(val &cur, val &pre, char color, int index) {

	//초기화	
	forn(i, 30) {
		cur.curcolornum[i] = pre.curcolornum[i];
	}
	cur.sum = pre.sum;

	int ci = color - 'A';

	//처음
	if (cur.curcolornum[ci] == 0) {cur.sum -= index;}

	cur.curcolornum[ci] += 1;

	//마지막
	if (cur.curcolornum[ci] == colornumber[ci]) {cur.sum += index;}


}

void initval(val cur[]) {
	forn(i, maxlen) {
		cur[i].sum = 0;
		forn(j, 30) {
			cur[i].curcolornum[j] = 0;
		}
	}

}

int get(val &cur, char color, int index) {
	//현재    색깔 종류  , 총길이
	int ci = color - 'A';
	//처음


	if (cur.curcolornum[ci] == 0) {
		return cur.sum - index;
	}
	//마지막
	else if (cur.curcolornum[ci] + 1 == colornumber[ci]) {
		ret = cur.sum + index;
		return ret;
	}
	//중간일때
	else { return cur.sum; }

}

void countcolor() {

	forn(i, 30) { colornumber[i] = 0; }
	forn(i, Alen) { colornumber[A[i] - 'A'] += 1; }
	forn(i, Blen) { colornumber[B[i] - 'A'] += 1; }
	//forn(i, 30) { printf("%d ", colornumber[i]); }
	//printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);
	int a, b;

	while (1) {
		if (T == 0) break;
		T--;
		//초기화
		initval(memo1);
		initval(memo2);
		forn(i, maxlen) { A[i] = B[i] = 0; }
		scanf("%s", &A);
		scanf("%s", &B);

		Alen = strlen(A);
		Blen = strlen(B);
		//
		//색상 카운트

		countcolor();
		
		//dp
		for_se(i, 1, Alen + 1) {
			set(memo1[i], memo1[i - 1], A[i - 1], i );
			//printf("%d ", memo1[i].sum);
		}

		//printf("\n");
		for_se(i, 1, Blen + 1) {
			//홀 1->2
			if (i % 2 == 1) {
				set(memo2[0], memo1[0], B[i - 1], i);

				for_se(j, 1, Alen + 1) {
					//int a, b;
					a = get(memo1[j], B[i - 1], i + j );
					b = get(memo2[j - 1], A[j - 1], i  + j );

					if (a <= b) { set(memo2[j], memo1[j], B[i - 1], i + j); }
					else { set(memo2[j], memo2[j - 1], A[j - 1], i  + j ); }


				}

				////출력
				//forn(i, Alen + 1) {

				//	printf("%d ", memo2[i].sum);
				//}

			}
			//짝 2->1
			else {
				set(memo1[0], memo2[0], B[i - 1], i );

				for_se(j, 1, Alen + 1) {
					//int a, b;
					a = get(memo1[j - 1], A[j - 1], i  + j );
					b = get(memo2[j], B[i - 1], i + j);
					if (a < b) { set(memo1[j], memo1[j - 1], A[j - 1], i + j ); }
					else if (a>b) { set(memo1[j], memo2[j], B[i - 1], i  + j ); }
					else {
						if (memo1[j - 1].sum <= memo2[j].sum) {
							set(memo1[j], memo1[j - 1], A[j - 1], i  + j );
						}
						else {
							set(memo1[j], memo2[j], B[i - 1], i + j );
						}

					}
				}

				////출력
				//forn(i, Alen + 1) {

				//	printf("%d ", memo1[i].sum);
				//}
			}
			//printf("\n");

		}
		//printf("\n");
		//print ans
		if (Blen % 2 == 1) { printf("%d\n", memo2[Alen].sum); }
		else { printf("%d\n", memo1[Alen].sum); }




	}
}
