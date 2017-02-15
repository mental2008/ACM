#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#define maxn 20000
using namespace std;
vector<string> vec[maxn+5];
map<pair<string,string>, int> mail;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int k=0;
		for(int i=0;i<=maxn;i++) vec[i].clear();
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			string login,domain;
			bool at=false;
			for(int j=0;j<s.size();j++)
			{
				if(s[j]=='@')
				{
					at=true;
					continue;
				}
				if(at==false)
					login+=tolower(s[j]);
				else
					domain+=tolower(s[j]);
			}
			if(domain=="bmail.com")
			{
				string tmp;
				for(int j=0;j<login.size();j++)
				{
					if(login[j]=='.') continue;
					if(login[j]=='+') break;
					tmp+=login[j];
				}
				login=tmp;
			}
			if(mail.find(make_pair(login,domain))==mail.end())
			{
				mail[make_pair(login,domain)]=k;
				vec[k].push_back(s);
				k++;
			}
			else
			{
				vec[mail[make_pair(login,domain)]].push_back(s);
			}
		}
		printf("%d\n",k);
		for(int i=0;i<k;i++)
		{
			printf("%d",(int)vec[i].size());
			for(int j=0;j<vec[i].size();j++)
				cout<<" "<<vec[i][j];
			printf("\n");
		}
	}
	return 0;
}
