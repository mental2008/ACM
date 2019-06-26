#include<bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define lowbit(x) (x&-x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int maxn=105;
char s[maxn];
char fuck[maxn];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        scanf("%s",s);
        int len=strlen(s);
        int a,b,c;
        a=b=c=0;
        rep(i,0,len-1) {
            if(s[i]>='0'&&s[i]<='9') a++;
            else if(s[i]>='A'&&s[i]<='Z') b++;
            else if(s[i]>='a'&&s[i]<='z') c++;
        }
        rep(i,0,len-1) fuck[i]=s[i];
        fuck[len]='\0';
        int num=0;
        if(a) num++;
        if(b) num++;
        if(c) num++;
        if(num==1) {
            if(a) {
                fuck[0]='A';
                fuck[1]='a';
            }
            else if(b) {
                fuck[0]='0';
                fuck[1]='a';
            }
            else {
                fuck[0]='0';
                fuck[1]='A';
            }
        }
        else if(num==2) {
            rep(i,0,len-1) {
                if(fuck[i]>='0'&&fuck[i]<='9') a--;
                else if(fuck[i]>='A'&&fuck[i]<='Z') b--;
                else if(fuck[i]>='a'&&fuck[i]<='z') c--;
                char ch=fuck[i];
                fuck[i]='0';
                a++;
                if(a&&b&&c) break;
                a--;
                fuck[i]='A';
                b++;
                if(a&&b&&c) break;
                b--;
                fuck[i]='a';
                c++;
                if(a&&b&&c) break;
                c--;
                fuck[i]=ch;
                if(fuck[i]>='0'&&fuck[i]<='9') a++;
                else if(fuck[i]>='A'&&fuck[i]<='Z') b++;
                else if(fuck[i]>='a'&&fuck[i]<='z') c++;
            }
        }
        printf("%s\n",fuck);
    }
    return 0;
}
