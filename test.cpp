#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#define maxn 30000
using namespace std;
vector<string> vec[maxn+5];
map<string,int> lalala;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<=maxn;i++) vec[i].clear();
		lalala.clear();
		int k=0;
		for(int i=0;i<n;i++)
		{
			string a;
			cin>>a;
			bool is_ok=false;
			string tmp;
			for(int j=0;j<a.size();j++)
			{
				if(is_ok==true)
				{
					tmp+=tolower(a[j]);
				}
				if(a[j]=='@') is_ok=true;
			}
			if(tmp=="bmail.com")
			{
				string copy;
				for(int j=0;j<a.size();j++)
				{
					if(a[j]=='.') continue;
					if(a[j]=='+')
					{
						for(int m=j+1;m<a.size();m++)
						{
							if(a[m]=='@') 
							{
								j=m;
								break;
							}
						}
					}
					copy+=tolower(a[j]);
				}
				if(!lalala[copy])
				{
					vec[++k].push_back(copy);
					vec[k].push_back(a);
					lalala[copy]++;
				}
				else
				{
					for(int j=1;j<=k;j++)
					{
						if(copy==vec[j][0])
						{
							vec[j].push_back(a);	
							break;
						}
					}	
				}
			}
			else
			{
				string copy;
				//bool is_ok=false;
				for(int j=0;j<a.size();j++)
				{
					//if(a[j]=='.' && is_ok==false) continue;
					copy+=tolower(a[j]);
					//if(a[j]=='@') is_ok=true;
				}	
				if(!lalala[copy])
				{
					vec[++k].push_back(copy);
					vec[k].push_back(a);
					lalala[copy]++;
				}
				else
				{
					for(int j=1;j<=k;j++)
					{
						if(copy==vec[j][0])
						{
							vec[j].push_back(a);
							break;
						}
					}	
				}
			}
		}
		printf("%d\n",k);
		for(int i=1;i<=k;i++)
		{
			printf("%d",(int)vec[i].size()-1);
			for(int j=1;j<vec[i].size();j++)
			{
				printf(" ");
				cout<<vec[i][j];
			}
			printf("\n");
		}
	}
	return 0;
}
