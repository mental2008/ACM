#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <utility>
#include <bitset>
#include <complex>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define sqr(x) ((x)*(x))
#define mp make_pair
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
const ll INF=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;

const int maxn=1e5+5;
int n,q;
char s[maxn];
int a[maxn][3];
int cc[maxn][3];
int b[3];
int seg[maxn][26];

void build(int root,int l,int r) {
    if(l==r) {
        seg[root][s[l]-'a']=1;
        return;
    }
    int mid=(l+r)>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    rep(i,0,25) {
        seg[root][i]=seg[root<<1][i]+seg[root<<1|1][i];
    }
}
int qry(int root,int l,int r,int ql,int qr,int c) {
    if(l>qr||r<ql) return -1;
    if(seg[root][c]==0) return -1;
    if(l==r) return l;
    int mid=(l+r)>>1;
    int p=qry(root<<1,l,mid,ql,qr,c);
    if(p!=-1) return p;
    return qry(root<<1|1,mid+1,r,ql,qr,c);
}
void upd(int root,int l,int r,int index,int c,int val) {
    if(l>index||r<index) return;
    if(l==r) {
        seg[root][c]+=val;
        return;
    }
    int mid=(l+r)>>1;
    upd(root<<1,l,mid,index,c,val);
    upd(root<<1|1,mid+1,r,index,c,val);
    seg[root][c]=seg[root<<1][c]+seg[root<<1|1][c];
}

int main() {
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    build(1,1,n);
    mem(b,0);
    rep(i,0,2) cc[0][i]=0;
    while(q--) {
        char o[5];
        scanf("%s",o);
        if(o[0]=='+') {
            int id;
            char c[5];
            scanf("%d%s",&id,c);
            id--;
            b[id]++;
            a[b[id]][id]=c[0]-'a';
            // printf("%d %d %d\n",id,b[id],a[b[id]][id]);
        }
        else {
            int id;
            scanf("%d",&id);
            id--;
            b[id]--;
        }
        // rep(i,0,2) {
        //     printf("i = %d\n",i+1);
        //     rep(j,1,b[i]) {
        //         printf("%c",a[j][i]+'a');
        //     }
        //     puts("");
        // }
        bool judge=false;
        int per[3]={0,1,2};
        sort(per,per+3);
        do {
            vector<pii> v;
            bool ok=true;
            int d[3];
            mem(d,0);
            // printf("%d %d %d\n",per[0],per[1],per[2]);
            while(1) {
                bool chk=true;
                rep(i,0,2) if(d[i]!=b[i]) chk=false;
                if(chk) break;
                pii temp(inf,-1);
                rep(j,0,2) {
                    int i=per[j];
                    if(d[i]==b[i]) continue;
                    int id=qry(1,1,n,cc[d[i]][i]+1,n,a[d[i]+1][i]);
                    if(id==-1) {
                        ok=false;
                        break;
                    }
                    // printf("%d %d %c\n",id,i,a[d[i]+1][i]+'a');
                    if(id<temp.fi) temp=mp(id,i);
                }
                // printf("%d %d\n",temp.fi,temp.se);
                if(!ok) break;
                d[temp.se]++;
                upd(1,1,n,temp.fi,a[d[temp.se]][temp.se],-1);
                cc[d[temp.se]][temp.se]=temp.fi;
                v.pb(mp(temp.fi,a[d[temp.se]][temp.se]));
            }
            for(auto p:v) {
                upd(1,1,n,p.fi,p.se,1);
            }
            if(ok) { judge=true; break; }
            // puts("");
        } while(next_permutation(per,per+3));
        if(judge) puts("YES");
        else puts("NO");
    }
    return 0;
}