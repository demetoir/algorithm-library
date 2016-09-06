//aho-corasick
//
//
//시간복잡도 O(N + P)
//N : 찾으려고하는 문자열 길이
//P : 패턴의 출현 횟수
//
//
//참고 자료
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
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define MAX_N 100001

#define pii pair<int,int>

const int alphabet = 26;
int tonum(char c) { return c - 'A'; }
struct TrieNode {
	TrieNode* children[alphabet];

	//현재 위치에서 끝나는 문자열 번호
	int terminal;
	//실패연결
	TrieNode* fail;
	//이노드에 방문했을댸 등장하는 바늘들의 먼호
	vector<int>output;

	TrieNode() :terminal(false) {
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
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
				children[next] = new TrieNode();
			children[next]->insert(key + 1);
		}
	}

	TrieNode* find(const char*key) {
		if (*key == 0) return this;
		int next = tonum(*key);
		if (children[next] == NULL)return NULL;
		return children[next]->find(key + 1);
	}

};

void computeFailfunc(TrieNode* root) {
	queue<TrieNode*> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		TrieNode* here = q.front();
		q.pop();

		for (int edge = 0; edge < alphabet; edge++) {
			TrieNode* child = here->children[edge];
			if (!child)continue;

			if (here == root)
				child->fail = root;
			else {
				TrieNode* t = here->fail;
				while (t != root && t->children[edge] == NULL)
					t = t->fail;
				if (t->children[edge])
					t = t->children[edge];
				child->fail = t;
			}

			child->output = child->fail->output;
			if (child->terminal != -1)
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}

vector<pii> ahoCorasick(const string& s, TrieNode* root) {
	vector<pii> ret;
	TrieNode* state = root;
	for (int i = 0; i < s.size(); i++) {
		int chr = tonum(s[i]);
		while (state != root & state->children[chr] == NULL)
			state = state->fail;
		if (state->children[chr])
			state = state->children[chr];
		for (int j = 0; j < state->output.size(); j++)
			ret.push_back(pii(i, state->output[j]));
	}
	return ret;
}
