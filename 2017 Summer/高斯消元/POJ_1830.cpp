#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
const int maxn = 30;
int n;
int start[maxn];
int end[maxn];
int A[maxn][maxn];

void Gauss() {
	int i, j;
	for(i = 0, j = 0; i < n && j < n; ++j) {
		int r = i;
		while(r < n) {
			if(A[r][j]) break;
			else ++r;
		}
		if(A[r][j]) {
			for(int k = 0; k <= n; k++) swap(A[r][k], A[i][k]);
			for(int k = i + 1; k < n; k++) {
				if(A[k][j]) {
					for(int l = j; l <= n; l++) {
						A[k][l] ^= A[i][l];
					}
				}
			}
			i++;
		}
	}
	for(int j = i; j < n; j++) {
		if(A[j][n]) {
			puts("Oh,it's impossible~!!");
			return;
		}
	}
	printf("%d\n", (1 << (n - i)));
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		mem(A, 0);
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &start[i]);
		for(int i = 0; i < n; i++) scanf("%d", &end[i]);
		for(int i = 0; i < n; i++) {
			A[i][i] = 1;
			A[i][n] = start[i] ^ end[i];
		}
		while(1) {
			int x, y;
			scanf("%d%d", &x, &y);
			if(x == 0 && y == 0) break;
			A[y - 1][x - 1] = 1;
		}
		Gauss();
	}
	return 0;
}
