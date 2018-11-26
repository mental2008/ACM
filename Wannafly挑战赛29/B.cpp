#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const int maxn=1e5+5;
int n;
ll k;
ll x[maxn];
struct Node {
    ll a,b,c,d;
    bool zero;
    void init() {
        a=b=c=d=0;
        zero=0;
    }
    Node() {}
    Node(ll _a,ll _b,ll _c,ll _d) {
        a=_a;b=_b;c=_c;d=_d;
        zero=0;
    }
    bool operator<(const Node& e) const {
        if(a==e.a) {
            if(b==e.b) {
                if(c==e.c) {
                    return d<e.d;
                }
                return c<e.c;
            }
            return b<e.b;
        }
        return a<e.a;
    }
    bool operator==(const Node& e) const {
        return a==e.a&&b==e.b&&c==e.c&&d==e.d;
    }
} node[maxn];
map<Node,ll> st;

int main() {
    scanf("%d%lld",&n,&k);
    ll big=1ll*n*(n-1)/2;
    rep(i,1,n) {
        scanf("%lld",&x[i]);
        node[i].init();
        ll temp=x[i];
        while(temp) {
            if(temp%10==0) node[i].zero=1;
            else if(temp%10==2) {
                node[i].a++;
            }
            else if(temp%10==3) {
                node[i].b++;
            }
            else if(temp%10==4) {
                node[i].a+=2;
            }
            else if(temp%10==5) {
                node[i].c++;
            }
            else if(temp%10==6) {
                node[i].a++;
                node[i].b++;
            }
            else if(temp%10==7) {
                node[i].d++;
            }
            else if(temp%10==8) {
                node[i].a+=3;
            }
            else if(temp%10==9) {
                node[i].b+=2;
            }
            temp/=10;
        }
    }
    if(k==0) {
        ll ans=0;
        ll m=0;
        ll num_zero=0;
        rep(i,1,n) {
            if(node[i].zero) num_zero++;
            if(node[i].zero==0&&node[i].a==0&&node[i].b==0&&node[i].c==0&&node[i].d==0) {
                m++;
            }
        }
        ans=m*(m-1)/2;
        return 0*printf("%lld\n",big-ans);
    }
    else if(k==1) {
        ll ans=1ll*n*(n-1)/2;
        return 0*printf("%lld\n",big-ans);
    }
    ll sum=0;
    ll num_zero=0;
    rep(i,1,n) {
        node[i].a%=k;
        node[i].b%=k;
        node[i].c%=k;
        node[i].d%=k;
        if(node[i].zero) {
            num_zero++;
            continue;
        }
        if(node[i].a==0&&node[i].b==0&&node[i].c==0&&node[i].d==0) {
            // cout<<"fuck "<<i<<"\n";
            sum++;
        }
        else {
            st[node[i]]++;
        }
    }
    // cout<<sum<<" "<<num_zero<<"\n";
    ll ans=sum*(sum-1)/2+num_zero*(num_zero-1)/2+num_zero*(n-num_zero);
    // Node temp(0,1,0,0);
    // cout<<st[temp]<<"\n";
    ll res=0;
    rep(i,1,n) {
        if(node[i].zero) continue;
        if(node[i].a==0&&node[i].b==0&&node[i].c==0&&node[i].d==0) {
            continue;
        }
        Node temp;
        temp.init();
        temp.a=(k-node[i].a)%k;
        temp.b=(k-node[i].b)%k;
        temp.c=(k-node[i].c)%k;
        temp.d=(k-node[i].d)%k;
        // cout<<x[i]<<"\n";
        // cout<<temp.a<<" "<<temp.b<<" "<<temp.c<<" "<<temp.d<<"\n";
        // cout<<st[temp]<<"\n";
        res+=st[temp];
        if(node[i]==temp) res--;
    }
    res/=2;
    ans+=res;
    printf("%lld\n",big-ans);
    return 0;
}