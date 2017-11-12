#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;

typedef struct Trie_node {
    struct Trie_node* next[2];
    vector<int> vec;
    int depth;
}TrieNode, *Trie;

TrieNode* createTrieNode(int depth) {
    // Trie node = (TrieNode *)malloc(sizeof(TrieNode));
    Trie node = new TrieNode;
    node->vec.clear();
	memset(node->next, 0, sizeof(node->next));
    node->depth = depth;
	return node;
}

void Trie_insert(Trie root, int num) {
    Trie node = root;
    int temp = 29;
    while(temp >= 0) {
        int x = (num >> temp) & 1;
        // printf("%d %d\n", temp, x);
        if(node->next[x] == NULL) {
            node->next[x] = createTrieNode(temp);
        }
        node = node->next[x];
        node->vec.push_back(num);
        temp--;
    }
}

int n;

LL solve(Trie root) {
    if(root->depth == 0) return 0;
    LL res = 0;
    if(root->next[0]) res += solve(root->next[0]);
    if(root->next[1]) res += solve(root->next[1]);
    if(root->next[0] && root->next[1]) {
        Trie lson = root->next[0], rson = root->next[1];
        if(lson->vec.size() < rson->vec.size()) {
            int temp = INF;
            for(int i = 0; i < lson->vec.size(); ++i) {
                int x = lson->vec[i];
                rson = root->next[1];
                for(int j = root->depth - 2; ~j; --j) {
                    if(rson->next[0] == NULL) rson = rson->next[1];
                    else if(rson->next[1] == NULL) rson = rson->next[0];
                    else {
                        int temp = (x >> j) & 1;
                        if(temp) rson = rson->next[1];
                        else rson = rson->next[0];
                    }
                }
                int y = rson->vec[0];
                temp = min(temp, x ^ y);
            }
            res += temp;
        }
        else {
            int temp = INF;
            for(int i = 0; i < rson->vec.size(); ++i) {
                int x = rson->vec[i];
                lson = root->next[0];
                for(int j = root->depth - 2; ~j; --j) {
                    if(lson->next[0] == NULL) lson = lson->next[1];
                    else if(lson->next[1] == NULL) lson = lson->next[0];
                    else {
                        int temp = (x >> j) & 1;
                        if(temp) lson = lson->next[1];
                        else lson = lson->next[0];
                    }
                }
                int y = lson->vec[0];
                temp = min(temp, x ^ y);
            }
            res += temp;
        }
    }
    return res;
}

int main() {
    while(~scanf("%d", &n)) {
        Trie root = createTrieNode(30);
        for(int i = 1; i <= n; ++i) {
            int val;
            scanf("%d", &val);
            Trie_insert(root, val);
        }
        LL ans = solve(root);
        printf("%lld\n", ans);
    }
    return 0;
}
