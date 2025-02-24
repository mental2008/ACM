// A.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string s;
	while (cin >> s) {
		int len = s.size();
		int four = 0, seven = 0;
		for (int i = 0; i < len; ++i) {
			if (s[i] == '4') four++;
			else if (s[i] == '7') seven++;
		}
		if (seven) {
			if (four >= seven) cout << "4\n";
			else cout << "7\n";
		}
		else if (four) {
			cout << "4\n";
		}
		else cout << "-1\n";
	}
    return 0;
}

