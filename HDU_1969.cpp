#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
#define maxn 10000
using namespace std;
int N, F;
double a[maxn+5];
bool judge(double x){
	int sum = 0;
	for(int i = 1; i <= N; i++){
		sum += (int)(a[i] / x);
	}
	return sum >= F;
}
int main(){
	const double pai = acos(-1);
	int t;
	scanf("%d", &t);
	while(t--){
		memset(a, 0, sizeof(a));
		scanf("%d%d", &N, &F);
		F++;
		double Maxright = -1;
		for(int i = 1; i <= N; i++){
			int R;
			scanf("%d", &R);
			a[i] = pai * R * R;
			Maxright = max(a[i], Maxright);
		}
		double l = 0, r = Maxright;
		while(r - l > 1e-7){
			double mid = (l + r) / 2;
			if(judge(mid) == true) l = mid;
			else r = mid;
		}
		printf("%.4lf\n", l);
	}
	return 0;
}
