#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 20000
using namespace std;
int fa[maxn+5];

void init(int n){
	for(int i = 0; i <= n; i++){
		fa[i] = i;
	}
}

int _find(int x){
	return (fa[x] == x) ? x : (fa[x] = _find(fa[x]));
}

bool connect(int a, int b){
	int x = _find(a);
	int y = _find(b);
	if(x == y) return 1;
	else{
		fa[x] = y;
		return 0;
	}
}

struct relation{
	int girl, boy;
	int d;
}soider[50005];

bool cmp(relation a, relation b){
	return a.d < b.d;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		init(maxn + 2);
		int n, m, R;
		scanf("%d%d%d", &n, &m, &R);
		for(int i = 0; i < R; i++){
			int xi, yi, di;
			scanf("%d%d%d", &xi, &yi, &di);
			soider[i].girl = xi;
			soider[i].boy = yi + 10001;
			soider[i].d = (-1) * di;
		}
		int ans = (n + m) * 10000;
		sort(soider, soider + R, cmp);
		for(int i = 0; i < R; i++){
			if(!connect(soider[i].girl, soider[i].boy)){
				ans += soider[i].d;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
