#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const int maxn = 505;
int n;

struct Node {
    string name;
    double one, other;
    int index;
} node1[maxn], node2[maxn];

vector<Node> vec;

bool cmp1(Node x, Node y) {
    return x.one < y.one;
}

bool cmp2(Node x, Node y) {
    return x.other < y.other;
}

int main() {
    //freopen("B.in", "r", stdin);
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            cin >> node1[i].name >> node1[i].one >> node1[i].other;
            node1[i].index = i;
            node2[i] = node1[i];
        }
        sort(node2 + 1, node2 + 1 + n, cmp2);
        vec.clear();
        double ans = 10000000000000;
        for(int i = 1; i <= n; ++i) {
            int num = 0;
            double res = node1[i].one;
            for(int j = 1; j <= n; ++j) {
                if(node2[j].index == node1[i].index) continue;
                num++;
                res += node2[j].other;
                if(num == 3) {
                    break;
                }
            }
            if(res < ans) {
                vec.clear();
                vec.push_back(node1[i]);
                int num = 0;
                for(int j = 1; j <= n; ++j) {
                    if(node2[j].index == node1[i].index) continue;
                    num++;
                    vec.push_back(node2[j]);
                    if(num == 3) {
                        break;
                    }
                }
                ans = res;
            }
        }
        cout << fixed << setprecision(8) << ans << '\n';
        for(int i = 0; i < 4; ++i) {
            cout << vec[i].name << '\n';
        }
    }
    return 0;
}
