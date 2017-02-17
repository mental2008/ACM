#include<bits/stdc++.h>
#define maxn 100000
using namespace std;
vector<int> vec[maxn+5];
int n,m;
int a[maxn+5];
int ans;
int vis[maxn+5];
void dfs(int x , int num , int fa){
	if(a[x]) num++;
	else num = 0;
	if(num > m) return;
	if(vis[x] == 0 && x != 1 && vec[x].size() == 1){
		ans++;
		vis[x] = 1;
		return;
	}
	for(int i = 0;i < vec[x].size(); i++){
		if(vec[x][i] == fa) continue;
		dfs(vec[x][i] , num , x);
	}
}
int main(){
	while(~scanf("%d%d", &n, &m)){
		memset( a , 0 , sizeof(a) );
		memset( vis , 0, sizeof(vis) );
		ans = 0;
		for(int i = 0;i <= maxn; i++) vec[i].clear();
		for(int i = 1;i <= n; i++){
			scanf("%d",&a[i]);
		}
		for(int i = 0;i < n-1; i++){
			int x,y;
			scanf("%d%d", &x, &y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		dfs(1,0,-1);
		printf("%d\n",ans);
	}
	return 0;
}
