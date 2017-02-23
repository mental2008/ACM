#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD 9973
using namespace std;

void extendGcd(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return;
	}
	else{
		extendGcd(b, a % b, x, y);
		int tmp = x;
		x = y;
		y = tmp - (a / b) * y;
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, b;
		scanf("%d%d", &n, &b);
		int x, y;
		extendGcd(b, MOD, x, y);
		x *= n;
		int ans = (x % MOD + MOD) % MOD;
		printf("%d\n", ans);
	}
	return 0;
}
