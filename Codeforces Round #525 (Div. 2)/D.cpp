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
typedef double db;

int ask(int x,int y) {
    cout<<"? "<<x<<" "<<y<<"\n";
    fflush(stdout);
    int val;
    scanf("%d",&val);
    return val;
}
void out(int x,int y) {
    cout<<"! "<<x<<" "<<y<<"\n";
    fflush(stdout);
}

int a,b;
int pa,pb;

int main() {
    a=b=0;
    pa=pb=0;
    int state=ask(0,0);
    per(i,29,0) {
        if(state==0) {
            int o=ask(pa,pb|(1<<i));
            if(o==1) {
                a|=(1<<i);
                b|=(1<<i);
                pa|=(1<<i);
                pb|=(1<<i);
            }
        }
        else if(state==1) {
            int x=ask(pa|(1<<i),pb|(1<<i));
            int y=ask(pa|(1<<i),pb);
            if(x==-1) {
                a|=(1<<i);
                pa|=(1<<i);
                state=y;
            }
            else if(y==-1) {
                a|=(1<<i);
                b|=(1<<i);
                pa|=(1<<i);
                pb|=(1<<i);
            }
        }
        else {
            int x=ask(pa|(1<<i),pb|(1<<i));
            int y=ask(pa,pb|(1<<i));
            if(x==1) {
                b|=(1<<i);
                pb|=(1<<i);
                state=y;
            }
            else if(y==1) {
                a|=(1<<i);
                b|=(1<<i);
                pa|=(1<<i);
                pb|=(1<<i);
            }
        }
    }
    out(a,b);
    return 0;
}