#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct Trie_node{
	int count;
	struct Trie_node* next[26];
	bool exist;
}TrieNode, *Trie;

TrieNode* createTrieNode(){
	Trie node = (TrieNode *)malloc(sizeof(TrieNode));
	node->count = 0;
	node->exist = false;
	memset(node->next, 0, sizeof(node->next));
	return node;
}

void Trie_insert(Trie root, char* word){
	Trie node = root;
	char *p = word;
	int id;
	while(*p){
		id = *p - 'a';
		if(node->next[id] == NULL){
			node->next[id] = createTrieNode();
		}
		node = node->next[id];
		++p;
		node->count += 1;
	}
	node->exist = true;
}

int Trie_search(Trie root, char* word){
	Trie node = root;
	char *p = word;
	int id;
	while(*p){
		id = *p - 'a';
		node = node->next[id];
		++p;
		if(node == NULL) return 0;
	}
	return node->count;
}

int main(){
	Trie root = createTrieNode();
	int n, m;
	char str[12];
	scanf("%d", &n);
	while(n--){
		scanf("%s", str);
		char ch = getchar();
		Trie_insert(root, str);
	}
	scanf("%d", &m);
	while(m--){
		scanf("%s", str);
		char ch = getchar();
		printf("%d\n", Trie_search(root, str));
	}
	return 0;
}
