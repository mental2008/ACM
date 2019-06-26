#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

int cnt[14];

int main() {
    int n=18;
    rep(i,1,n) {
        int val;
        scanf("%d",&val);
        cnt[val]++;
    }
    int ans=cnt[0];
    rep(i,1,13) {
        ans+=cnt[i]%2;
    }
    printf("%d\n",ans);
    return 0;
}