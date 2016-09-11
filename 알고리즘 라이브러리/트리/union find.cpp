//union-find(Disjoint-set)
//
//시간복잡도
//
//참고자료
//https://en.wikipedia.org/wiki/Disjoint-set_data_structure
//http://blog.secmem.org/521
//
//
//문제
//1717 집합의 표현 https://www.acmicpc.net/problem/1717
//3430 용이 산다 https://www.acmicpc.net/problem/3430
//10755 공항 https://www.acmicpc.net/problem/10775
//
using namespace std;
#define MAX_N 100000

int parent[MAX_N];
int level[MAX_N];
void init(int size) {
	for (int i = 0; i < size; i++) {
		parent[i] = i;
		level[i] = 0;
	}
}
int find(int A) {
	if (parent[A] == A)return A;
	return parent[A] = find(parent[A]);
}
void unite(int A, int B) {
	int Aroot = find(A);
	int Broot = find(B);
	if (Aroot == Broot)return;

	if (level[Aroot] < level[Broot]) {
		parent[Aroot] = Broot;
	}
	else {
		parent[Broot] = Aroot;
		if (parent[Aroot] == parent[Broot]) {
			level[Aroot] ++;
		}
	}
}