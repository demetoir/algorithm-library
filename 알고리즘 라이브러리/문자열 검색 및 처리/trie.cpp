//trie 트라이
//
//
//시간복잡도 O(n)
//
//
//참고 자료
//
//
//
//
//
//문제
//
//
//
//
//
//
//
#include <string>
using namespace std;
#define MAX_N 100001


const int alphabet = 26;
int tonum(char c) { return c - 'A'; }
struct NODE{
	NODE* children[alphabet];

	bool terminal;
	NODE():terminal(false){
		memset(children, 0, sizeof(children));
	}
	~NODE() {
		for (int i = 0; i < alphabet; i++) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key) {
		if (*key == 0)terminal = true;
		else {
			int next = tonum(*key);
			if (children[next] == NULL)
				children[next] = new NODE();
			children[next]->insert(key + 1);
		}
	}

	NODE* find(const char*key) {
		if (*key == 0) return this;
		int next = tonum(*key);
		if (children[next] == NULL)return NULL;
		return children[next]->find(key + 1);
	}
};





