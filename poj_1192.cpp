#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define maxn 1000
using namespace std;
int dp[maxn+5][3];
int n;
struct node{
	int x, y, c;
}a[maxn+5];
vector<int> vec[maxn+5];
void dfs(int i, int fa){
	for(int j = 0; j < vec[i].size(); j++){
		if(vec[i][j] == fa) continue;
		dfs(vec[i][j], i);
		dp[i][0] = max(dp[i][0], max(dp[vec[i][j]][0], dp[vec[i][j]][1]));
		if(dp[vec[i][j]][1] > 0)
			dp[i][1] += dp[vec[i][j]][1];
	}
}
int main(){
	while(~scanf("%d", &n)){
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= maxn; i++) vec[i].clear();
		for(int i = 0; i < n; i++){
			int xi, yi, ci;
			scanf("%d%d%d", &xi, &yi, &ci);
			a[i].x = xi;
			a[i].y = yi;
			a[i].c = ci;
			dp[i][1] = a[i].c;
		}
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
			      if(abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) == 1){
					vec[i].push_back(j);
					vec[j].push_back(i);
				}
			}
		}
		dfs(0, -1);
		int ans = max(dp[0][0], dp[0][1]);
		printf("%d\n", ans);
	}
	return 0;
}
