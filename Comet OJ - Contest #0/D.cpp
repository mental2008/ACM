#include <bits/stdc++.h>

using namespace std;

namespace FastIO {
	#define BUF_SIZE 100000
	bool IOError = 0;
	inline char NextChar() {
		static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p1 == pend) {
			p1 = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if(pend == p1) {
				IOError = 1;
				return -1;
			}
		}
		return *p1++;
	}
	inline bool Blank(char c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t';
	}

	template<class T> inline void Read(T &x) {
		char c;
		while(Blank(c = NextChar()));
		if(!IOError) {
			for(x = 0; '0' <= c && c <= '9'; c = NextChar())
				x = (x << 3) + (x << 1) + c - '0';
		}
	}
}

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

const ll mod=1e9+7;
inline void Add(ll &x,ll y) { x+=y; if(x>=mod) x-=mod; }
int main() {
    int caseCnt;
    // scanf("%d",&caseCnt);
    FastIO::Read(caseCnt);
    while(caseCnt--) {
        ll n;
        // scanf("%lld",&n);
        FastIO::Read(n);
        int p=sqrt(n);
        if(p*p==n) puts("infty");
        else if(n%4==0) {
            n/=4;
            ll ans=0;
            ll cnt=0;
            for(ll i=1;i*i<=n;++i) {
                if(n%i==0) {
                    cnt++;
                    ll x=i+n/i;
                    Add(ans,n*x%mod);
                }
            }
            printf("%lld %lld\n",cnt,ans);
        }
        else puts("0 0");
    }
    return 0;
}