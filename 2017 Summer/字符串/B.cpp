#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10005;
int n, m;
char str[205];
char s[maxn];
bool ok;
vector<int> vec;

typedef struct Trie_node {
	struct Trie_node* next[100];
	Trie_node* fail;
	int count;
	int sign;
	int exist;
}TrieNode, *Trie;

TrieNode* createTrieNode() {
	Trie node = (TrieNode *)malloc(sizeof(TrieNode));
	node->count = 0;
	node->sign = 0;
	node->exist = 0;
	node->fail = NULL;
	memset(node->next, 0, sizeof(node->next));
	return node;
}

void Trie_insert(Trie root, char *word, int sign) {
	Trie node = root;
	char *p = word;
	int id;
	while(*p) {
		id = (int)*p - 32;
		if(node->next[id] == NULL) {
			node->next[id] = createTrieNode();
		}
		node = node->next[id];
		++p;
	}
	node->count++;
	node->sign = sign;
}

void getFail(Trie root) {
	queue<Trie> q;
	q.push(root);
	while(!q.empty()) {
		Trie node = q.front();
		q.pop();
		for(int i = 0; i < 100; i++) {
			if(node->next[i] != NULL) {
				if(node == root) {
					node->next[i]->fail = root;
				}
				else {
					Trie temp = node->fail;
					while(temp != NULL) {
						if(temp->next[i] != NULL) {
							node->next[i]->fail = temp->next[i];
							break;
						}
						temp = temp->fail;
					}
					if(temp == NULL) node->next[i]->fail = root;
				}
				q.push(node->next[i]);
			}
		}
	}
}

int ac(Trie root, int num) {
	int len = strlen(s);
	Trie node = root;
	int ans = 0;
	for(int i = 0; i < len; i++) {
		int id = (int)s[i] - 32;
		while(node->next[id] == NULL && node != root) {
			node = node->fail;
		}
		node = node->next[id];
		if(node == NULL) node = root;
		Trie temp = node;
		while(temp != root && temp->exist != num) {
			ans += temp->count;
			if(temp->count) vec.push_back(temp->sign), ok = true;
			temp->exist = num;
			temp = temp->fail;
		}
	}
	return ans;
}

int main() {
	while(~scanf("%d", &n)) {
		Trie root = createTrieNode();
		for(int i = 1; i <= n; i++) {
			scanf("%s", str);
			Trie_insert(root, str, i);
		}
		getFail(root);
		scanf("%d", &m);
		int total = 0;
		for(int i = 1; i <= m; i++) {
			//vec.clear();
			scanf("%s", s);
			ok = false;
			int ans = ac(root, i);
			if(ok) {
				sort(vec.begin(), vec.end());
				total++;
				printf("web %d:", i);
				for(int i = 0; i < vec.size(); i++) printf(" %d", vec[i]);
				puts("");
				vec.clear();
			}
		}
		printf("total: %d\n", total);
	}
	return 0;
}
