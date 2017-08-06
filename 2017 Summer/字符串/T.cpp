#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
using namespace std;
map<string, string> mp;
int main() {
	ios::sync_with_stdio(false);
	mp.clear();
	string s;
	while(getline(cin, s)) {
		if(s == "") break;
		istringstream ss(s);
		string content, key;
		ss >> content >> key;
		mp[key] = content;
	}
	string order;
	while(getline(cin, order)) {
		if(mp[order] != "") cout << mp[order] << endl;
		else cout << "eh" << endl;
	}
	return 0;
}
