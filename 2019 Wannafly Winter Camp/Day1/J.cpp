#include <cstdio>
#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include<stack>
#include<cstring>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const long long INF=0x3f3f3f3f3f3f3f3f;
const long long maxn = 1050;
vector<long long> fuck[maxn];
vector<long long> res;
int main()
{
	long long i, j, k, n, m, ans;
	while (scanf("%lld%lld", &n, &m) != EOF)
	{
		for (i = 1; i <= n; i++)
			fuck[i].clear();
		ans = INF;
		for (i = 1; i <= m; i++)
		{
			scanf("%lld%lld", &j, &k);
			fuck[k].push_back(j);
		}
		for (i = 1; i <= n; i++)
		{
			sort(fuck[i].begin(), fuck[i].end());
		}
		for (i = 1; i <= m; i++)
		{
			long long tmp = 0, cnt = 0;
			res.clear();
			for (j = 1; j <= n; j++)
				if (fuck[j].size() >= i)
				{
					long long delta = fuck[j].size() - i;
					for (k = 0; k <= delta; k++)
					{
						tmp += fuck[j][k];
						cnt++;
					}
					for (k = delta + 1; k < fuck[j].size(); k++)
						res.push_back(fuck[j][k]);
				}
				else
				{
					for (k = 0; k < fuck[j].size(); k++)
						res.push_back(fuck[j][k]);
				}
			sort(res.begin(), res.end());
			for (j = 0; j < i - cnt; j++)
				tmp = tmp + res[j];
			ans = min(ans, tmp);
		}
		printf("%lld\n", ans);
	}
}