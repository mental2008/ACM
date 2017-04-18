#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 20071027
#define maxn 300000
#define LL long long
using namespace std;
char s[maxn + 5];
LL dp[maxn + 5];

typedef struct Trie_node {
    int count;
    struct Trie_node* next[26];
    bool exist;
}TrieNode, *Trie;

TrieNode* createTrieNode() {
    Trie node = (TrieNode *)malloc(sizeof(TrieNode));
    node->count = 0;
    node->exist = false;
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
        node->count += 1;
    }
    node->exist = true;
}

void Trie_search(Trie root, char *word, int length, int i) {
    Trie node = root;
    char *p = word;
    int id;
    int originLength = length;
    while(length--) {
        id = *p - 'a';
        node = node->next[id];
        ++p;
        if(node == NULL) return;
        if(node->exist) dp[i] = (dp[i] + dp[i + originLength - length]) % MOD;
    }
}

int main() {
    int CaseCnt = 1;
    while(~scanf("%s", s)) {
        Trie root = createTrieNode();
        int len = (int)strlen(s);
        memset(dp, 0, sizeof(dp));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            char pattern[4000 + 5];
            scanf("%s", pattern);
            Trie_insert(root, pattern);
        }
//        char test[5] = "ab";
//        cout << Trie_search(root, test, 2) << endl;
        dp[len] = 1;
        for(int i = len - 1; i >= 0; i--) {
            char *tmp = &s[i];
            int tmplen = (int)strlen(tmp);
            Trie_search(root, tmp, min(tmplen, 100), i);
        }
//        for(int i = 0; i < 5; i++) {
//            cout << dp[i] << endl;
//        }
        printf("Case %d: %lld\n", CaseCnt++, dp[0]);
    }
    return 0;
}