#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=1e5+5;
int n;
int a[maxn];
set<string> st[maxn];
int id[maxn];
bool mark[maxn];
pii p[maxn];
pii pp[maxn];
int m;
int mm;
int ans;

void work() {
    random_shuffle(id+1,id+1+n);
    set<string> temp;
    bool first=true;
    ans=0;
    m=0;
    rep(i,1,n) {
        if(first) {
            if(!mark[id[i]]) {
                first=false;
                temp.clear();
                for(auto x:st[id[i]]) {
                    temp.insert(x);
                }
                p[++m]=mp(id[i],id[i]);
            }
            else if(mark[id[i]]&&mark[id[i+1]]) {
                first=false;
                temp.clear();
                p[++m]=mp(id[i],id[i+1]);
                for(auto x:st[id[i]]) {
                    temp.insert(x);
                }
                i++;
                for(auto x:st[id[i]]) {
                    temp.insert(x);
                }
            }
        }
        else {
            if(!mark[id[i]]) {
                int b=0;
                for(auto x:st[id[i]]) {
                    if(temp.find(x)!=temp.end()) {
                        b++;
                    }
                }
                int a=temp.size()-b;
                int c=st[id[i]].size()-b;
                ans+=min(min(a,b),c);
                temp.clear();
                for(auto x:st[id[i]]) {
                    temp.insert(x);
                }
                p[++m]=mp(id[i],id[i]);
            }
            else if(mark[id[i]]&&mark[id[i+1]]) {
                set<string> temp2;
                p[++m]=mp(id[i],id[i+1]);
                for(auto x:st[id[i]]) {
                    temp2.insert(x);
                }
                i++;
                for(auto x:st[id[i]]) {
                    temp2.insert(x);
                }
                int b=0;
                for(auto x:temp2) {
                    if(temp.find(x)!=temp.end()) {
                        b++;
                    }
                }
                int a=temp.size()-b;
                int c=temp2.size()-b;
                ans+=min(min(a,b),c);
                temp.clear();
                for(auto x:temp2) {
                    temp.insert(x);
                }
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) {
        string o;
        cin>>o;
        if(o[0]=='H') mark[i]=0;
        else mark[i]=1;
        cin>>a[i];
        rep(j,0,a[i]-1) {
            string s;
            cin>>s;
            st[i].insert(s);
        }
        id[i]=i;
    }
    int cnt=10;
    int res=0;
    while(cnt--) {
        work();
        if(res<ans) {
            res=ans;
            mm=m;
            rep(i,1,m) pp[i]=p[i];
        }
    }
    cout<<mm<<"\n";
    rep(i,1,mm) {
        if(pp[i].fi==pp[i].se) cout<<pp[i].fi-1<<"\n";
        else cout<<pp[i].fi-1<<" "<<pp[i].se-1<<"\n";
    }
    cout<<"ans = "<<res<<"\n";
    return 0;
}

/*
2
33
138
147691
113024
*/