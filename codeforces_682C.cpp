#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 100000
#define LL long long
using namespace std;
int n;
int a[maxn+5];
struct edge{
	int node,weight;
	edge(){}
	edge(int _node,int _weight){
		node=_node,weight=_weight;
	}
};
vector<edge> vec[maxn+5];
int ans;
void dfs(int x,LL d,int fa)
{
	if(d>a[x]) return;
	ans++;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i].node==fa) continue;
		else dfs(vec[x][i].node,max(d+vec[x][i].weight,0LL),x);
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<=maxn;i++)
			vec[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=0;
		for(int i=2;i<=n;i++)
		{
			int p,c;
			scanf("%d%d",&p,&c);
			edge edge1(i,c);
			vec[p].push_back(edge1);
			edge edge2(p,c);
			vec[i].push_back(edge2);
		}
		dfs(1,0,-1);
		printf("%d\n",n-ans);
	}
	return 0;
}
