#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e+6;

struct segment {
    int pos;
    int mark;
    segment(int _pos, int _mark) {
        pos = _pos, mark = _mark;
    }
};

vector<segment> vec;
vector<pair<int, int> > ans;

bool cmp(segment x, segment y) {
    if(x.pos == y.pos) return x.mark > y.mark;
    return x.pos < y.pos;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        segment segment1(l, 1);
        vec.push_back(segment1);
        segment segment2(r, -1);
        vec.push_back(segment2);
    }
    sort(vec.begin(), vec.end(), cmp);

//    for(int i = 0; i < vec.size(); i++) {
//        cout << vec[i].pos << endl;
//    }

    int count = 0;
    int l, r;
    bool is_l = false;
    for(int i = 0; i < vec.size(); i++) {
        count += vec[i].mark;
        if(count >= k && is_l == false) {
            l = vec[i].pos;
            is_l = true;
        }
        if(count < k && is_l == true) {
            r = vec[i].pos;
            is_l = false;
            ans.push_back(make_pair(l, r));
        }
    }
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}