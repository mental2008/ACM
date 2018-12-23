#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
vector<int> vec;
string s;

void solve(int l,int r) {
    if(l>r) return;
    // printf("%d %d\n",l,r);
    int len=r-l+1;
    if(l==r) {
        vec.pb(s[l]);
        return;
    }
    if(len%2==0) {
        vec.pb(s[r]);
        solve(l,r-1);
        return;
    }
    vec.pb(s[l]);
    vec.pb(s[r]);
    solve(l+1,r-1);
    return;
}

int main() {
    cin>>s;
    int len=s.size();
    solve(0,len-1);
    per(i,len-1,0) {
        printf("%c",vec[i]);
    }
    puts("");
    return 0;
}