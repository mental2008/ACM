#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxD = 2000005;
int n;
char str[1005][55];
char s[maxD];
int res[1005];

typedef struct Trie_node {
	struct Trie_node* next[26];
	Trie_node* fail;
	int count;
	int sign;
}TrieNode, *Trie;

TrieNode* createTrieNode() {
	Trie node = (TrieNode *)malloc(sizeof(TrieNode));
	node->count = 0;
	node->sign = 0;
	node->fail = NULL;
	memset(node->next, 0, sizeof(node->next));
	return node;
}

void Trie_insert(Trie root, char *word, int sign) {
	Trie node = root;
	char *p = word;
	int id;
	while(*p) {
		id = *p - 'A';
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
		if(s[i] < 'A' || s[i] > 'Z') {
			node = root;
			continue;
		}
		int id = s[i] - 'A';
		while(node->next[id] == NULL && node != root) {
			node = node->fail;
		}
		node = node->next[id];
		if(node == NULL) node = root;
		Trie temp = node;
		while(temp != root) {
			//ans += temp->count;
			if(temp->count) {
				res[temp->sign]++;
				ans = max(res[temp->sign], ans);
			}
			temp = temp->fail;
		}
	}
	return ans;
}

int main() {
	while(~scanf("%d", &n)) {
		getchar();
		Trie root = createTrieNode();
		for(int i = 1; i <= n; i++) {
			scanf("%s", str[i]);
			Trie_insert(root, str[i], i);
		}
		getFail(root);
		scanf("%s", s);
		memset(res, 0, sizeof(res));
		int ans = ac(root);
		//printf("%d\n", ans);
		for(int i = 1; i <= n; i++) {
			if(res[i] != 0) {
				printf("%s: %d\n", str[i], res[i]);
			}
		}
	}
	return 0;
}
