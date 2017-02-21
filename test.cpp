nclude <iostream>

#include <stdio.h>

#include <algorithm>



using namespace std;



long long a[1010], b[1010];

double c[1010];

int n, k;



bool ok(double mid){

	for (int i = 1; i <= n; i++){

		c[i] = a[i] - b[i] * mid;

	}

	sort(c + 1, c + 1 + n);

	double sum = 0.0;

	for (int i = k+1; i <= n; i++){

		sum += c[i];

	}

	if (sum >= 0.0) return true;

	return false;

}



int f(double ans){

	int ans2 = ans;

	if (ans - ans2 > ans2 + 1 - ans){

		return ans2 + 1;

	}

	return ans2;

}



int main(){

	while (scanf("%d%d", &n, &k) == 2){

		if (n == 0 && k == 0) break;

		

		for (int i = 1; i <= n; i++){

			scanf("%I64d", &a[i]);

			a[i] = 100 * a[i];

		}

		for (int i = 1; i <= n; i++)

			scanf("%I64d", &b[i]);



		double l = 0.0, r = 100.0, mid, eps = 0.0001;



		while (r - l > eps){

			mid = (r + l) / 2;

			if (ok(mid)) l = mid;

			else r = mid;

		}

		printf("%d\n", f(mid));

	}

	return 0;

}//test







 



 
