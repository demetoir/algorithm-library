//aho-corasick
//
//kmp를 공부할것
//
//시간복잡도 O(N+M + P)
//N : 찾으려고하는 문자열 길이
//m : 찾으려고하는 짚더미 문자열 길이
//P : 패턴의 출현 횟수
//
//아호 코라식은 실패함수
//
//참고 자료
//http://www.slideshare.net/ssuser81b91b/ahocorasick-algorithm
//http://channelofchaos.tistory.com/24
//http://hwamir.tistory.com/5
//http://blog.ivank.net/aho-corasick-algorithm-in-as3.html
//알고리즘 문제해결 2권
//
//문제
//백준 그룹 문제집 참조
//

#include <string>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define MAX_N 100001

#define pii pair<int,int>

const int alphabet = 26;
int tonum(char c) { return c - 'a'; }
struct Node {
	Node* children[alphabet];

	//현재 위치에서 끝나는 문자열 번호
	int terminal;
	//실패연결
	Node* fail;
	//이노드에 방문했을댸 등장하는 바늘들의 번호
	vector<int>output;

	Node() :terminal(-1) {
		memset(children, 0, sizeof(children));
	}
	~Node() {
		for (int i = 0; i < alphabet; i++) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key, int id) {
		if (*key == 0)terminal = id;
		else {
			int next = tonum(*key);
			if (children[next] == NULL)
				children[next] = new Node();
			children[next]->insert(key + 1, id);
		}
	}

	//TrieNode* find(const char* key) {
	//	if (*key == 0) return this;
	//	int next = tonum(*key);
	//	if (children[next] == NULL)return NULL;
	//	return children[next]->find(key + 1);
	//}
};

void computeFailfunc(Node* root) {
	queue<Node*> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();

		for (int edge = 0; edge < alphabet; edge++) {
			Node* child = cur->children[edge];
			if (!child)continue;

			if (cur == root)
				child->fail = root;
			else {
				Node* failnode = cur->fail;
				while (failnode != root && failnode->children[edge] == NULL)
					failnode = failnode->fail;
				if (failnode->children[edge])
					failnode = failnode->children[edge];
				child->fail = failnode;
			}

			child->output = child->fail->output;
			if (child->terminal >= 1)
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}

int ahoCorasick(const string& s, Node* root) {
	/*vector<pii> ret;*/
	int count = 0;
	Node* cur = root;
	for (int i = 0; i < s.size(); i++) {
		int chr = tonum(s[i]);
		while (cur != root && cur->children[chr] == NULL) {
			cur = cur->fail;

		}
		if (cur->children[chr])
			cur = cur->children[chr];

		if (cur->output.size())
			return 1;

	}
	return 0;
}

