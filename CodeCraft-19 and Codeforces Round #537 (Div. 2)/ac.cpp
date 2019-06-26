#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<iostream>
#include<set>
#include<functional>
using namespace std;
const long long maxn = 1e5+ 20;
long long a[maxn];
double ans;

int main()
{
	long long i, j, k, n, m;
	while (scanf("%lld%lld%lld", &n, &k, &m) != EOF)
	{
		for (i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		sort(a + 1, a + 1 + n);
		if (m < n - 1)
		{
			ans = 0.0;
			for (i = m + 1; i <= n; i++)
				ans = ans + a[i];
			ans = ans / (n - m);
			printf("%.8lf\n", ans);
		}
		else
		{
			long long res = min(k, m - (n - 1));
			ans = 0.0;
			ans = ans + res + a[n];
			printf("%.8lf\n", ans);
		}
		
	}
}
