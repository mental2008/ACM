#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m;
int a[maxn];
map<int, int> mp;
vector<int> vec;
bool cmp(int x, int y) {
    return x > y;
}

bool judge(int need) {
    if(need == 0) return true;
    int len = vec.size();
    int sum = 0;
    for(int i = 0; i < len; ++i) {
        sum += (vec[i] / need);
    }
    return sum >= n;
}

int main()
{
    scanf("%d%d", &n, &m);
    mp.clear();
    for(int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }
    vec.clear();
    for(auto &temp : mp) {
        vec.push_back(temp.second);
    }
    sort(vec.begin(), vec.end(), cmp);
    int l = 0, r = 100;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(judge(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
