

ll dp[22][22];
int num[22];

ll dfs(int pos,int cnt,bool flag) {
    if(pos==-1) {
        if(cnt<=3) return 1;
        return 0;
    }
    if(!flag&&dp[pos][cnt]!=-1) return dp[pos][cnt];
    int p;
    if(flag) p=num[pos];
    else p=9;
    ll res=0;
    rep(i,0,p) {
        if(i==0) res+=dfs(pos-1,cnt,flag&&i==p);
        else res+=dfs(pos-1,cnt+1,flag&&i==p);
    }
    if(!flag) dp[pos][cnt]=res;
    return res;
}

ll calc(ll x) {
    int i=0;
    while(x) {
        num[i++]=x%10;
        x/=10;
    }
    return dfs(i-1,0,1);
}

int main() {
    mem(dp,-1);
    int caseCnt;
    scanf("%d",&caseCnt);
    while(caseCnt--) {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",calc(r)-calc(l-1));
    }
    return 0;
}
