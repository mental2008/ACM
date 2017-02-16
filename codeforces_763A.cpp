#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
struct edge{
	int l,r;
}a[maxn+5];
int clo[maxn+5];
int vis[maxn+5];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(clo,0,sizeof(clo));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<n;i++)
			scanf("%d%d",&a[i].l,&a[i].r);
		for(int i=1;i<=n;i++)
			scanf("%d",&clo[i]);
		int num=0;
		for(int i=1;i<n;i++)
		{
			if(clo[a[i].l]!=clo[a[i].r])
			{
				vis[a[i].l]++;
				vis[a[i].r]++;
				num++;	
			}
		}
		int flag=false;
		if(num==0) printf("YES\n1\n");
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==num)
				{
					printf("YES\n%d\n",i);
					flag=true;
					break;
				}
			}
			if(flag==false) printf("NO\n");
		} 

	}
	return 0;
}
