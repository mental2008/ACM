#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
typedef long long ll;
const ll mod=998244353ll;

struct matrix
{
   ll a[3][3];
   void clear() { mem(a,0); }
};
matrix mul(matrix x,matrix y)
{
    matrix temp;
    temp.clear();
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                temp.a[i][j]=(temp.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
            }
        }
    }
    return temp;
}

matrix qpow(matrix a, ll n) {
    matrix res=a;
    matrix p.clear();
    p.a[0][0]=p.a[0][1]=p.a[1][0]=p.a[2][0]=p.a[2][1]=p.a[2][2]=1;
    while(n) {
        if(n&1) res=mul(res,p);
        p=mul(p,p);
        n>>=1;
    }
    return res;
}

void calc(ll n) {
    matrix res;
    res.clear();
    res.a[0][0]=res.a[1][0]=1;
    res.a[0][2]=2;
    return qpow(res,n-2).a[2][0];
}

int main() {

    return 0;
}