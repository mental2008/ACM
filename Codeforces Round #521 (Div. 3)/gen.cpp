#include<cstdio>
#include<algorithm>
#include<ctime>

using namespace std;

typedef long long ll;
const ll mod=1e9+7;

int main() {
    freopen("in.txt","w",stdout);
    /*puts("62 5 26");
    srand((unsigned int)time(NULL));
    for(int i=1;i<=62;++i) {
        ll val=(mod*rand())%(1000000000ll)+1;
        printf("%lld ",val);
    }
    puts("");*/
    puts("5000 4248 3453");
    srand((unsigned int)time(NULL));
    for(int i=1;i<=5000;++i) {
        ll val=1000000000ll;
        printf("%lld ",val);
    }
    puts("");
}