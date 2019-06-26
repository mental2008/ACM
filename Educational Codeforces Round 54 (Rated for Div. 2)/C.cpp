#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<iomanip>
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
const db exps=1e-8;
const db pi=acos(-1.0);
const int maxn=1e5+5;

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        db d;
        scanf("%lf",&d);
        db delta=d*d-d*4;
        if(delta>exps||fabs(delta)<exps) {
            delta=sqrt(delta);
            db a=(d+delta)/2;
            db b=(d-delta)/2;
            if(b>exps||fabs(b)<exps) {
                printf("Y %.10lf %.10lf\n",a,b);
            }
            else puts("N");
        }
        else {
            puts("N");
        }
    }
    return 0;
}