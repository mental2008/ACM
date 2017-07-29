#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 300005;
int n, x, y;
char derek[maxn];
char alfia[maxn];
int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		scanf("%d%d%d", &n, &x, &y);
		scanf("%s", derek);
		scanf("%s", alfia);
		int difference = 0;
		for(int i = 0; i < n; i++) {
			if(derek[i] != alfia[i]) difference++;
		}
		if(abs(x - y) > difference || x + y > 2 * n - difference) puts("Lying");
		else puts("Not lying"); 
	}
	return 0;
}
