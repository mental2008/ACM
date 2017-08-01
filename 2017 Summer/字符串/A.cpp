#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 55;
const int maxD = 1000005;
int n;
char str[maxn];
char s[maxD];

typedef struct Trie_node {
	struct Trie_node* next[26];
	Trie_node* fail;
	int count;
}TrieNode, *Trie;

TrieNode* createTrieNode() {
	Trie node = (TrieNode *)malloc(sizeof(TrieNode));
	node->count = 0;
	node->fail = NULL;
	memset(node->next, 0, sizeof(node->next));
	return node;
}

void Trie_insert(Trie root, char *word) {
	Trie node = root;
	char *p = word;
	int id;
	while(*p) {
		id = *p - 'a';
		if(node->next[id] == NULL) {
			node->next[id] = createTrieNode();
		}
		node = node->next[id];
		++p;
	}
	node->count++;
}

void getFail(Trie root) {
	queue<Trie> q;
	q.push(root);
	while(!q.empty()) {
		Trie node = q.front();
		q.pop();
		for(int i = 0; i < 26; i++) {
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

int ac(Trie root) {
	int len = strlen(s);
	Trie node = root;
	int ans = 0;
	for(int i = 0; i < len; i++) {
		int id = s[i] - 'a';
		while(node->next[id] == NULL && node != root) {
			node = node->fail;
		}
		node = node->next[id];
		if(node == NULL) node = root;
		Trie temp = node;
		while(temp != root && temp->count != -1) {
			ans += temp->count;
			temp->count = -1;
			temp = temp->fail;
		}
	}
	return ans;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d", &n);
		getchar();
		Trie root = createTrieNode();
		for(int i = 1; i <= n; i++) {
			scanf("%s", str);
			Trie_insert(root, str);
		}
		getFail(root);
		scanf("%s", s);
		int ans = ac(root);
		printf("%d\n", ans);
	}
	return 0;
}
