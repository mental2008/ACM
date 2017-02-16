#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 15
#define LL long long
using namespace std;
int a[maxn+5];
set<LL> vis; 
int n;
void dfs(int x,int y,int z,int num)
{
	if(num==n)
	{
		if(x>=y && y>=z && x<y+z && x!=0 && y!=0 && z!=0)
		{
			LL sum=z*10000000000+y*100000+x;
			vis.insert(sum);
		}
		return;
	}
	dfs(x+a[num+1],y,z,num+1);
	dfs(x,y+a[num+1],z,num+1);
	dfs(x,y,z+a[num+1],num+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vis.clear();
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		dfs(0,0,0,0);
		printf("%d\n",(int)vis.size());
	}
	return 0;
}
