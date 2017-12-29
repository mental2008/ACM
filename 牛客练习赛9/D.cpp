#include <iostream>
#include <string>
using namespace std;

string conv(int num) {
    int a[10];
    int temp = num;
    int i = 0;
    while(temp) {
        a[i] = temp % 10;
        temp /= 10;
        i++;
    }
    string res = "";
    for(int j = i - 1; j >= 0; --j) res += ((char)(a[j] + '0'));
    return res;
}

int main() {
    string s = "";
    int len = 0, index = 1;
    while(len < 2000) {
        string res = conv(index);
        len += (res.size());
        s += res;
        index++;
    }
    int n;
    while(~scanf("%d", &n)) {
        n--;
        printf("%c\n", s[n]);
    }
    return 0;
}
