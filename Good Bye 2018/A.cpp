#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int main() {
    int y,b,r;
    scanf("%d%d%d",&y,&b,&r);
    if(b<r-1) {
        r=b+1;
    }
    else {
        b=r-1;
    }
    if(y<b-1) {
        b=y+1;
    }
    else {
        y=b-1;
    }
    if(b<r-1) {
        r=b+1;
    }
    else {
        b=r-1;
    }
    printf("%d\n",y+b+r);
    return 0;
}