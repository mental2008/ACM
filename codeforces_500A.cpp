#include<bits/stdc++.h>
#define maxn 30000
using namespace std;
int a[maxn+5], vis[maxn+5];
int n, t;
bool is_ok;
void dfs(int i){
	if(i == t){
		is_ok = true;
		return;
	}
	if(!vis[i+a[i]]){
		vis[i+a[i]] = 1;
		dfs(i+a[i]);
	}
	return;
}
int main(){
	while(~scanf("%d%d", &n, &t)){
		memset(a , 0 , sizeof(a));
		memset(vis , 0 , sizeof(vis));
		is_ok = false;
		for(int i = 1; i <= n-1 ; i++)
			scanf("%d",&a[i]);
		vis[1] = 1;
		dfs(1);
		if(is_ok == true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
