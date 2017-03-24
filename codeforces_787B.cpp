#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	bool is_ok = true;
	for(int i = 1; i <= m; i++) {
		int count;
		scanf("%d", &count);
		bool one_ok = false;
		map<int, int> universe;
		for(int j = 1; j <= count; j++) {
			int num;
			scanf("%d", &num);
			if(universe[(-1) * num]) {
				one_ok = true;
			}
			universe[num]++;
		}
		if(one_ok == false) is_ok = false;
	}
	if(is_ok) printf("NO\n");
	else printf("YES\n");
	return 0;
}
