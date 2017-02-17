#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000
using namespace std;
int n, m;
int fa[maxn+5];
void init(int n){
	for(int i = 0; i <= n; i++){
		fa[i] = i;
	}
}
int _find(int x){
	return (fa[x]==x?x:(fa[x]=_find(fa[x])));
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
int main(){
	while(~scanf("%d", &n)){
		if(n == 0) break;
		scanf("%d", &m);
		init(n);
		for(int i = 0; i < m ; i++){
			int x, y;
			scanf("%d%d", &x, &y);
			connect(x, y);
		}
		int ans = 0;
		for(int i = 2; i <= n; i++){
			if(!connect(1, i)){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
