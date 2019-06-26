#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<sstream>
#include<time.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define random(a,b) ((a)+rand()%((b)-(a)+1))
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

stringstream ss;

int main(int argc,char *argv[]) {
    int seed=time(NULL);
    if(argc) {
        ss.clear();
        ss<<argv[1];
        ss>>seed;
    }
    srand(seed);
    printf("1\n");
    int n=10;
    printf("%d\n",n);
    rep(i,1,n) {
        printf("%d ",random(0,10));
    }
    printf("\n");
    return 0;
}