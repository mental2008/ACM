#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int l=-INF,r=INF;
		int tmp=0;
		for(int i=0;i<n;i++)
		{
			int score,sign;
			scanf("%d%d",&score,&sign);
			if(sign==1) l=max(l,1900-tmp);
			if(sign==2) r=min(r,1899-tmp);
			tmp+=score;
		}
		if(l>r) printf("Impossible\n");
		else if(r==INF) printf("Infinity\n");
		else printf("%d\n",r+tmp);
	}
	return 0;
}
