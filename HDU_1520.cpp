#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 6000
using namespace std;
int a[maxn+5];
int dp[maxn+5][3];
vector<int> vec[maxn+5];
int n;
void dfs(int i, int fa){
	for(int j = 0; j < vec[i].size(); j++){
		if(vec[i][j] == fa) continue;
		dfs(vec[i][j], i);
		dp[i][0] += max(dp[vec[i][j]][0], dp[vec[i][j]][1]);
		dp[i][1] += dp[vec[i][j]][0];
	}
}
int main(){
	while(~scanf("%d", &n)){
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= maxn; i++) vec[i].clear();
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			dp[i][1] = a[i];
		}
		int x, y;
		while(scanf("%d%d", &x, &y)){
			if(x == 0 && y == 0) break;
			vec[x].push_back(y);
			vec[y].push_back(x);
		}
		dfs(1, -1);
		int ans = max(dp[1][0], dp[1][1]);
		printf("%d\n", ans);
	}
	return 0;
}
