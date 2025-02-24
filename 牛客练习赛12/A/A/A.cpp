// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double pi = acos(-1.0);
const double exps = 1e-3;

int main()
{
	ios::sync_with_stdio(false);
	int caseCnt;
	cin >> caseCnt;
	while (caseCnt--) {
		double ta, tb;
		cin >> ta >> tb;
		if (ta > exps) {
			if (tb > exps) {
				if (ta - tb > exps) cout << "clockwise\n";
				else cout << "counterclockwise\n";
			}
			else {
				if(ta - tb - pi > exps) cout << "clockwise\n";
				else cout << "counterclockwise\n";
			}
		}
		else {
			if (tb > exps) {
				if(tb - ta - pi > exps) cout << "clockwise\n";
				else cout << "counterclockwise\n";
			}
			else {
				if(ta - tb > exps) cout << "clockwise\n";
				else cout << "counterclockwise\n";
			}
		}
	}
    return 0;
}

