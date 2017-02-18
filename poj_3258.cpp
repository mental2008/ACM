#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50000
using namespace std;
int a[maxn+5];
int L, n, m;
bool check(int x){
	int num = 0;
	int space = 0;
	for(int i = 1; i <= n+1; i++){
		if(a[i] - a[space] < x){
			num++;
		}
		else{
			space = i;
		}
	}
	return num <= m;
}
int main(){
	while(~scanf("%d%d%d", &L, &n,&m)){
		a[0] = 0;
		a[n+1] = L;
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n+1);
		int l = 1, r = 2*L;
		while(r - l > 1){
			int mid = (l + r) / 2;
			if(check(mid)) l = mid;
			else r = mid;
		}
		printf("%d\n", l);
	}
	return 0;
}
