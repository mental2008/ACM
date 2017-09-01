#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
string header;
string blank;
string str;
int val[5];
struct Node {
    int row;
    string content;
    int sign;
    int value;
    bool operator < (const Node& e) const {
        if(sign == e.sign) return value < e.value;
        else return sign < e.sign;
    }
} node[105];

int main() {
    ios::sync_with_stdio(false);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    mem(val, 0);
    int start = 0;
    int cnt = 0;
    int MAX = -1;
    while(getline(cin, str)) {
        if(str[0] == '+') {
            if(start == 0) {
                start = 1;
            }
            else {
                start = 0;
                cnt++;
            }
        }
        else {
            node[cnt].row++;
            if(str[1] != ' ') {
                int len = (int)str.size();
                if(MAX < len) MAX = len;
                node[cnt].content = str;
                string temp = str.substr(1, 3);
                if(temp == "SYS") {
                    node[cnt].sign = 0;
                }
                else if(temp == "ATK") {
                    node[cnt].sign = 1;
                }
                else if(temp == "DFS") {
                    node[cnt].sign = 2;
                }
                else if(temp == "AUX") {
                    node[cnt].sign = 3;
                }
                else if(temp == "HAK") {
                    node[cnt].sign = 4;
                }
                node[cnt].value = val[node[cnt].sign]++;
            }
        }
    }
    sort(node, node + cnt);
    header = "+";
    for(int i = 1; i < MAX - 1; ++i) header += '-';
    header += '+';
    blank = "|";
    for(int i = 1; i < MAX - 1; ++i) blank += ' ';
    blank += '|';
    for(int i = 0; i < cnt; ++i) {
        cout << header << endl;
        for(int j = 0; j < node[i].row; ++j) {
            if(j != node[i].row / 2) cout << blank << endl;
            else {
                int len = (int)node[i].content.size();
                for(int k = 0; k < MAX - 1; ++k) {
                    if(k < len - 1) cout << node[i].content[k];
                    else cout << ' ';
                }
                cout << "|" << endl;
            }
        }
        cout << header << endl;
    }
    return 0;
}
