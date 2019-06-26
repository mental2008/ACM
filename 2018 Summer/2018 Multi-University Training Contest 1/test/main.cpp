#include <iostream>

using namespace std;
int a[200000];
int T;
long long n,m,t,o,p,ans;
int main()
{
    freopen("a.txt", "w", stdout);
    a[1]=1;
    a[2]=1;
int     ty=2;
    for (int i=3;i<=100000;i++) a[i]=a[i-a[i-1]] + a[i-1 - a[i-2]],ty+=a[i];
    cout<<a[1001]<<" "<<a[100000]<<endl;
    scanf("%d",&T);
    while (T--)
    {
        cin>>n;

        ans=0;
        for (int i=1;i<=n;i++) ans+=a[i];
        cout<<ans<<endl;

        n=n-1;
        o=n/15;
        m=o*o*60+16*o;
        t=n%15;
        p=0;
        for (int i=2;i<=t+1;i++) p=p+a[i];
        p=p+8*o*t;
        ans=m+p+1;
        cout<<ans<<endl;
        cout<<m<<" "<<p<<endl;
    }
    return 0;
}
