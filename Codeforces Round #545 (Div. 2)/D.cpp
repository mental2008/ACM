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

const int maxn=501000;
char s[maxn];
char t[maxn];
int n,m;
int nx[maxn];
char ans[maxn];

void getNext() {
    int len=m;
    nx[0]=0;
    int i=0,j=0;
    for(j=1;j<len;j++) { 
        while(t[i]!=t[j]&&i>0) i=nx[i-1];
        if(t[i]==t[j]) {
            i++;
            nx[j]=i;
        }
        else nx[j]=0;
    }
}

int main() {
    scanf("%s",s);
    scanf("%s",t);
    int num0,num1;
    num0=num1=0;
    n=strlen(s);
    m=strlen(t);
    rep(i,0,n-1) {
        if(s[i]=='1') num1++;
        else num0++;
    }
    getNext();
    int p=nx[m-1];
    if(n<m) printf("%s\n",s);
    else {
        int sum1,sum0;
        sum1=sum0=0;
        int k=0;
        rep(i,1,m) {
            if(t[i-1]=='1') sum1++;
            else sum0++;
            ans[++k]=t[i-1];
        }
        if(sum1>num1||sum0>num0) printf("%s\n",s);
        else {
            while(1) {
                bool ok;
                rep(i,p+1,m) {
                    ok=false;
                    if(t[i-1]=='1') {
                        if(sum1<num1) {
                            sum1++;
                            ans[++k]='1';
                            ok=true;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        if(sum0<num0) {
                            sum0++;
                            ans[++k]='0';
                            ok=true;
                        }
                        else {
                            break;
                        }
                    }
                    if(!ok) break;
                    if(k==n) break;
                }
                if(!ok) break;
                if(k==n) break;
            }
            while(sum1<num1) { ans[++k]='1'; sum1++; }
            while(sum0<num0) { ans[++k]='0'; sum0++; }
            rep(i,1,n) printf("%c",ans[i]);
            puts("");
        }
    }
    return 0;
}