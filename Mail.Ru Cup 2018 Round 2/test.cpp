#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
#include<cmath>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) (x*x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=205;
vector<string> vec[maxn];
vector<int> sign[maxn];
int n;
int cnt[maxn];

bool judge(string s) {
    if(s=="") return false;
    int len=s.size();
    if(s[0]=='0') {
        if(len==1) return true;
        return false;
    }
    if(s[0]>='a'&&s[0]<='z') return false;
    if(s[len-1]>='a'&&s[len-1]<='z') return false;
    return true;
}
vector<string> ans;

bool chk(string a,string b) {
    if(a==""||b=="") return false;
    int len=a.size();
    if(a[len-1]>='0'&&a[len-1]<='9'&&b[0]>='0'&&b[0]<='9') return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    n=0;
    while(getline(cin,s)) {
        int len=s.size();
        bool judge=false;
        string temp="";
        rep(i,0,len-1) {
            if(s[i]==' ') {
                vec[n].pb(temp);
                sign[n].pb(n);
                temp="";
            }
            else temp+=s[i];
        }
        vec[n].pb(temp);
        sign[n].pb(n);
        if(s[len-1]==' ') {
            vec[n].pb("");
            sign[n].pb(n);
        }
        n++;
    }
    mem(cnt,0);
    for(int i=0;i<n;++i) {
        int len=vec[i].size();
        string temp;
        for(int j=0;j<len;++j) {
            if(j==len-1&&i+1<n&&chk(vec[i][j],vec[i+1][0])) {
                //cout<<vec[i][j]<<" "<<vec[i+1][0]<<"\n";
                //cout<<sign[i][j]<<" "<<sign[i+1][0]<<"\n";
                vec[i+1][0]=vec[i][j]+vec[i+1][0];
                sign[i+1][0]=sign[i][j];
            }
            else {
                temp=vec[i][j];
                if(judge(temp)) {
                    ans.pb(temp);
                    //cout<<temp<<"\n";
                    //cout<<sign[i][j]<<"\n";
                    //cout<<"fuck\n";
                    cnt[sign[i][j]]++;
                }
            }
            
        }
    }
    int len=ans.size();
    rep(i,0,len-1) {
        cout<<ans[i];
        if(i==len-1) cout<<"\n";
        else cout<<" ";
    }
    rep(i,0,n-1) {
        cout<<cnt[i]<<"\n";
    }
    return 0;
}
/*
 * 2018 Beijing regional
 * B
 * AC code
 */