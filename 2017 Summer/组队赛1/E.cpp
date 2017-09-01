#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double exps = 1e-8;
const double PI = acos(-1.0);
const int maxn = 1e6 + 5;

struct student {
	int chinese;
	int math;
	int english;
} node[maxn];

vector<int> vec;

bool cmp(int x, int y) {
	if(node[x].chinese == node[y].chinese) {
		if(node[x].math == node[y].math) {
			return node[x].english < node[y].english;
		}
		else return node[x].math < node[y].math;
	}
	else return node[x].chinese < node[y].chinese;
}

bool cmp1(student x, student y) {
	return x.chinese > y.chinese;
}

void del(int x, int &n) {
	node[x].chinese = node[n - 1].chinese;
	node[x].math = node[n - 1].math;
	node[x].english = node[n - 1].english;
	n--;
}

int main() {
	int caseCnt;
	scanf("%d", &caseCnt);
	while(caseCnt--) {
		int n;
		scanf("%d", &n);
		ULL vx, px, tx;
		ULL vy, py, ty;
		ULL vz, pz, tz;
		scanf("%llu%llu%llu", &vx, &px, &tx);
		scanf("%llu%llu%llu", &vy, &py, &ty);
		scanf("%llu%llu%llu", &vz, &pz, &tz);
		vec.clear();
		for(int i = 0; i < n; ++i) {
			vx = vx * px + tx;
			node[i].chinese = vx % 5000;
		}
		for(int i = 0; i < n; ++i) {
			vy = vy * py + ty;
			node[i].math = vy % 5000;
		}
		for(int i = 0; i < n; ++i) {
			vz = vz * pz + tz;
			node[i].english = vz % 5000;
		}
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				if(node[i].chinese > node[j].chinese && node[i].math > node[j].math && node[i].english > node[j].english) {
					del(j, n);
					j--;
				}
				if(node[i].chinese < node[j].chinese && node[i].math < node[j].math && node[i].english < node[j].english) {
					del(i, n);
					i--;
					break;
				}
			}
		}
		for(int i = 0; i < n; ++i) vec.push_back(i);
		sort(vec.begin(), vec.end(), cmp);
		int len = (int)vec.size();
		printf("%d\n", len);
		for(int i = 0; i < len; ++i) {
			printf("%d %d %d\n", node[vec[i]].chinese, node[vec[i]].math, node[vec[i]].english);
		}
	}
	return 0;
}
