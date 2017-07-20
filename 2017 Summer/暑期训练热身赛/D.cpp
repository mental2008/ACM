#include <bits/stdc++.h>
using namespace std;
string s1, s2;
struct word {
	int letter[30];
	void init() {
		memset(letter, 0, sizeof(letter));
	}
	inline bool operator <(const word &a) const {
		for(int i = 0; i < 30; i++) {
			if(letter[i] < a.letter[i]) return true;
			else if(letter[i] > a.letter[i]) return false;
		}
		return false;
	}
};
set<word> vec;

int main() {
	cin >> s1 >> s2;
	vec.clear();
	for(int i = 0; i < s1.size(); i++) {
		word word0;
		word0.init();
		word0.letter[s1[i] - 'a']++;
		vec.insert(word0);
		for(int j = i + 1; j < s1.size(); j++) {
			word0.letter[s1[j] - 'a']++;
			vec.insert(word0);
		}
	}
	int ans = 0;
	for(int i = 0; i < s2.size(); i++) {
		word word0;
		word0.init();
		word0.letter[s2[i] - 'a']++;
		if(vec.find(word0) != vec.end()) {
			ans = max(ans, 1);
		}
		for(int j = i + 1; j < s2.size(); j++) {
			word0.letter[s2[j] - 'a']++;
			if(vec.find(word0) != vec.end()) {
				ans = max(ans, j - i + 1);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
