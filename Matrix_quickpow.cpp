#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define MOD 10000
using namespace std;

struct Matrix{
	int a[2][2];
	Matrix(){}
	Matrix(int x11, int x12, int x21, int x22){
		a[0][0] = x11;
		a[0][1] = x12;
		a[1][0] = x21;
		a[1][1] = x22;
	}
};

Matrix operator*(Matrix x, Matrix y){
	Matrix res;
	res.a[0][0] = (x.a[0][0] * y.a[0][0] + x.a[0][1] * y.a[1][0]) % MOD;
	res.a[0][1] = (x.a[0][0] * y.a[0][1] + x.a[0][1] * y.a[1][1]) % MOD;
	res.a[1][0] = (x.a[1][0] * y.a[0][0] + x.a[1][1] * y.a[1][0]) % MOD;
	res.a[1][1] = (x.a[1][0] * y.a[0][1] + x.a[1][1] * y.a[1][1]) % MOD;
	return res;
}

Matrix quick_pow(LL n){
	Matrix origin(1, 0, 0, 1);
	Matrix p(1, 1, 1, 0);
	while(n){
		if(n & 1)
			origin = origin * p;
		p = p * p;
		n >>= 1;
	}
	return origin;
}

int main(){
	LL n;
	while(~scanf("%lld", &n)){
		if(n == -1) break;
		Matrix ans = quick_pow(n);
		printf("%d\n", ans.a[0][1]);
	}
	return 0;
}
