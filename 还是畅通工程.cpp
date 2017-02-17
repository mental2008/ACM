#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
using namespace std;
int fa[maxn+5];
void init(int n){
	for(int i = 0; i <= n; i++){
		fa[i] = i;
	}
}
int _find(int x){
	return (fa[x]==x?x:(fa[x]=_find(fa[x])));
}
bool connect(int x, int y){
	int p = _find(x);
	int q = _find(y);
	if(p == q) return 1;
	else{
		fa[p] = q;
		return 0;
	}
}
struct town{
	int a, b;
	int dis;
}node[maxn+5];
bool cmp(town x, town y){
	return x.dis<y.dis;
}
int main(){
	int n;
	while(scanf("%d", &n)){
		if(n == 0) break;
		init(n);
		for(int i = 0; i < n*(n-1)/2; i++){
			int x, y, dist;
			scanf("%d%d%d", &x, &y, &dist);
			node[i].a = x;
			node[i].b = y;
			node[i].dis = dist;
		}
		sort(node, node+n*(n-1)/2, cmp);
		int ans = 0;
		for(int i = 0; i < n*(n-1)/2; i++){
			if(!connect(node[i].a, node[i].b)){
				ans += node[i].dis;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
