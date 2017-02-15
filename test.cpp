#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#define maxn 20000
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
					if(a[j]=='+'||a[j]=='@') break;
					copy+=tolower(a[j]);
				}
				if(!lalala[copy])
				{
					vec[++k].push_back(a);
					lalala[copy]=k;
				}
				else
				{
					vec[lalala[copy]].push_back(a);	
				}
			}
			else
			{
				string copy;
				for(int j=0;j<a.size();j++)
					copy+=tolower(a[j]);	
				if(!lalala[copy])
				{
					vec[++k].push_back(a);
					lalala[copy]=k;
				}
				else
				{
					vec[lalala[copy]].push_back(a);
				}
			}
		}
		printf("%d\n",k);
		for(int i=1;i<=k;i++)
		{
			printf("%d",(int)vec[i].size());
			for(int j=0;j<vec[i].size();j++)
			{
				printf(" ");
				cout<<vec[i][j];
			}
			printf("\n");
		}
	}
	return 0;
}
