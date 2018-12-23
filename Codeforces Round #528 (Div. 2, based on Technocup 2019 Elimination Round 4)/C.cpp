// ConsoleApplication8.cpp: 定义控制台应用程序的入口点。
//


#include <cstdio>
#include <bitset>
#include <iostream>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
struct node {
	long long x, y;
	bool operator<(const node& a)const 
	{
		if (x == a.x)
			return y < a.y;
		return x < a.x;
	}
	bool operator==(const node& a)
	{
		if (x == a.x&&y == a.y)
			return true;
		return false;
	}
};
vector<node> fuck;
vector<node> ans;
long long s[5];//0 first x second y  1 first y second x
vector<node> anstmp;
node tmp;
void check()
{
	anstmp.clear();
	anstmp.push_back(fuck[0]);
	for (long long i = 0; i < 2; i++)
	{
		long long deltax = fuck[i + 1].x - fuck[i].x;
		long long deltay = fuck[i + 1].y - fuck[i].y;
		if (s[i] == 0)
		{
			tmp = fuck[i];
			long long flag = deltax / abs(deltax);
			for (long long j = 1; j <= abs(deltax); j++)
			{
				tmp.x += flag;
				anstmp.push_back(tmp);
			}
			flag = deltay / abs(deltay);
			for (long long j = 1; j <= abs(deltay); j++)
			{
				tmp.y += flag;
				anstmp.push_back(tmp);
			}
		}
		else
		{
			tmp = fuck[i];
			long long flag = deltay / abs(deltay);
			for (long long j = 1; j <= abs(deltay); j++)
			{
				tmp.y += flag;
				anstmp.push_back(tmp);
			}
			flag = deltax / abs(deltax);
			for (long long j = 1; j <= abs(deltax); j++)
			{
				tmp.x+= flag;
				anstmp.push_back(tmp);
			}
		}
	}
	stable_sort(anstmp.begin(), anstmp.end());
	anstmp.erase(unique(anstmp.begin(), anstmp.end()),anstmp.end());
	if (anstmp.size() < ans.size() || ans.size() == 0)
	{
		ans.clear();
		for (auto it : anstmp)
		{
			ans.push_back(it);
		}
	}
}
void dfs(long long k)
{
	if (k == 2)
	{
		check();
		return;
	}
	s[k] = 0;
	dfs(k + 1);
	s[k] = 1;
	dfs(k + 1);
}
int main()
{
	long long i, j, k, n, m;
	ans.clear();
	for (i = 0; i < 3; i++)
	{
		scanf("%lld%lld", &tmp.x, &tmp.y);
		fuck.push_back(tmp);
	}
	sort(fuck.begin(), fuck.end());
	dfs(0);
	printf("%lld\n", ans.size());
	for (auto it : ans)
	{
		printf("%lld %lld\n", it.x, it.y);
	}
}

