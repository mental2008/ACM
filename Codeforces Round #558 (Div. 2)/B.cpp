#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
const db exps=1e-8;
const db pi=acos(-1.0);

struct Node {
    int val,cnt;
    Node() {}
    Node(int val,int cnt):val(val),cnt(cnt) {}
    bool operator<(const Node& e) const {
        if(cnt==e.cnt) return val<e.val;
        return cnt<e.cnt;
    }
};
set<Node> st;
map<int,int> mp;
const int maxn=1e5+5;
int n;

bool judge() {
    int a,b,c;
    auto head=st.begin();
    a=(*head).cnt;
    auto tail=st.end();
    tail--;
    b=(*tail).cnt;
    tail--;
    c=(*tail).cnt;
    if(b==c+1&&c==a) return true;
    return false;
}
bool judge2() {
    int a,b,c,d;
    auto head=st.begin();
    a=(*head).cnt;
    head++;
    b=(*head).cnt;
    auto tail=st.end();
    tail--;
    c=(*tail).cnt;
    if(c==b&&a==1) return true;
    return false;
}

int main() {
    scanf("%d",&n);
    int ans=1;
    rep(i,1,n) {
        int val;
        scanf("%d",&val);
        auto pos=st.find(Node(val,mp[val]));
        if(pos==st.end()) {
            mp[val]++;
            st.insert(Node(val,mp[val]));
        }
        else {
            st.erase(pos);
            mp[val]++;
            st.insert(Node(val,mp[val]));
        }
        if(st.size()>=2) {
            if(judge()||judge2()) ans=i;
        }
        else ans=i;
    }
    printf("%d\n",ans);
    return 0;
}