#include <bits/stdc++.h>

using namespace std;

#define mem(a,i) memset(a,i,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const int maxn=70000;
int n;
int len;
char ch[maxn];
char temp[maxn];
char s[6050][15];
bool vis[6050];
struct Node {
    int id;
    int len;
    bool operator<(const Node& e) const {
        return len<e.len;
    }
} node[6050];

int main() {
    int caseCnt;
    scanf("%d",&caseCnt);
    rep(T,1,caseCnt) {
        scanf("%d",&n);
        rep(i,1,n) scanf("%s",s[i]);
        rep(i,1,n) {
            node[i].id=i;
            node[i].len=strlen(s[i]);
        }
        sort(node+1,node+1+n);
        if(node[2].len<node[3].len) {
            mem(vis,0);
            vis[node[1].id]=vis[node[2].id]=1;
            printf("Case #%d: ",T);
            rep(i,1,n) {
                if(vis[i]) continue;
                printf("%s",s[i]);
            }
            puts("");
            continue;
        }
        mem(vis,0);
        int len=0;
        int index=-1;
        rep(i,1,n) {
            if(index==-1) {
                index=i;
                len=0;
                rep(j,1,i-1) {
                    int sz=strlen(s[j]);
                    rep(k,0,sz-1) {
                        ch[len++]=s[j][k];
                    }
                }
                rep(j,i+1,n) {
                    int sz=strlen(s[j]);
                    rep(k,0,sz-1) {
                        ch[len++]=s[j][k];
                    }
                }
            }
            else {
                int p=0;
                rep(j,1,i-1) {
                    int sz=strlen(s[j]);
                    rep(k,0,sz-1) {
                        temp[p++]=s[j][k];
                    }
                }
                rep(j,i+1,n) {
                    int sz=strlen(s[j]);
                    rep(k,0,sz-1) {
                        temp[p++]=s[j][k];
                    }
                }
                if(p>len) {
                    index=i;
                    rep(j,0,p-1) {
                        ch[j]=temp[j];
                    }
                    len=p;
                }
                else if(p==len) {
                    bool ok=false;
                    rep(j,0,p-1) {
                        if(ch[j]>temp[j]) break;
                        if(ch[j]<temp[j]) {
                            ok=true;
                            // printf("%c %c\n",ch[j],temp[j]);
                            break;
                        }
                    }
                    if(ok) {
                        // puts("fuck");
                        index=i;
                        rep(j,0,p-1) {
                            ch[j]=temp[j];
                        }
                    }
                }
            }
            // rep(j,0,len-1) {
            //     printf("%c",ch[j]);
            // }
            // puts("");
        }
        // printf("%d\n",index);
        vis[index]=1;
        index=-1;
        rep(i,1,n) {
            if(vis[i]) continue;
            if(index==-1) {
                index=i;
                len=0;
                rep(j,1,i-1) {
                    if(vis[j]) continue;
                    int sz=strlen(s[j]);
                    rep(k,0,sz-1) {
                        ch[len++]=s[j][k];
                    }
                }
                rep(j,i+1,n) {
                    if(vis[j]) continue;
                    int sz=strlen(s[j]);
                    rep(k,0,sz-1) {
                        ch[len++]=s[j][k];
                    }
                }
            }
            else {
                int p=0;
                rep(j,1,i-1) {
                    if(vis[j]) continue;
                    int sz=strlen(s[j]);
                    rep(k,0,sz-1) {
                        temp[p++]=s[j][k];
                    }
                }
                rep(j,i+1,n) {
                    if(vis[j]) continue;
                    int sz=strlen(s[j]);
                    rep(k,0,sz-1) {
                        temp[p++]=s[j][k];
                    }
                }
                if(p>len) {
                    index=i;
                    rep(j,0,p-1) {
                        ch[j]=temp[j];
                    }
                    len=p;
                }
                else if(p==len) {
                    bool ok=false;
                    rep(j,0,p-1) {
                        if(ch[j]>temp[j]) break;
                        if(ch[j]<temp[j]) {
                            ok=true;
                            break;
                        }
                    }
                    if(ok) {
                        index=i;
                        rep(j,0,p-1) {
                            ch[j]=temp[j];
                        }
                    }
                }
            }
        }
        // printf("%d\n",index);
        vis[index]=1;
        printf("Case #%d: ",T);
        rep(i,1,n) {
            if(vis[i]) continue;
            printf("%s",s[i]);
        }
        puts("");
    }
    return 0;
}