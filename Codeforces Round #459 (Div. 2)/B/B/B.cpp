// B.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
map<string, string> mp;
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	mp.clear();
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		string ip, name;
		cin >> name >> ip;
		mp[ip] = name;
	}
	for (int i = 1; i <= m; ++i) {
		string name, ip;
		cin >> name >> ip;
		cout << name << " " << ip << " #";
		int len = ip.size();
		ip = ip.substr(0, len - 1);
		cout << mp[ip] << '\n';
	}
    return 0;
}

