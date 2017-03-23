#include <bits/stdc++.h>
#define maxn 300000 + 100
using namespace std;
int l[maxn], r[maxn], a[maxn], s[maxn];
int main() {
	int n;
	cin >> n;
	memset(s, 0, sizeof(s));
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		l[i] = i;
		r[i] = i;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i - 1; j >= 1;) {
			if(a[j] % a[i] == 0) {
				l[i] = l[j];
				j = l[j] - 1;
			}
			else break;
		}
	}
	for(int i = n; i >= 1; i--) {
		for(int j = i + 1; j <= n;) {
			if(a[j] % a[i] == 0) {
				r[i] = r[j];
				j = r[j] + 1;
			}
			else break;
		}
	}
	int count = 0, Max = 0;
	for(int i = 1; i <= n; i++) {
		if(r[i] - l[i] == Max) count++;
		else if(r[i] - l[i] > Max){
			count = 1;
			Max = r[i] - l[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		if(r[i] - l[i] == Max) {
			if(s[l[i]] == 1) {
				count--;
				r[i] = l[i];
			}
			else s[l[i]] = 1;
		}
	}
	cout << count << " " << Max << endl;
	for(int i = 1; i <= n; i++) {
		if(r[i] - l[i] == Max) {
			cout << l[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
