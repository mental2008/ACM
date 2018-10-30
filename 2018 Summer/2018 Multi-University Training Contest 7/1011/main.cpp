#include <bits/stdc++.h>
using namespace std;
namespace IO {
    const int MT = 100000000;
    char IO_BUF[MT];
    int IO_PTR, IO_SZ;

    void begin() {
        IO_PTR = 0;
        IO_SZ = fread (IO_BUF, 1, MT, stdin);
    }
    template<typename T>
    inline bool scan_d (T & t) {
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != '-' && (IO_BUF[IO_PTR] < '0' || IO_BUF[IO_PTR] > '9'))
            IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        bool sgn = false;
        if (IO_BUF[IO_PTR] == '-') sgn = true, IO_PTR ++;
        for (t = 0; IO_PTR < IO_SZ && '0' <= IO_BUF[IO_PTR] && IO_BUF[IO_PTR] <= '9'; IO_PTR ++)
            t = t * 10 + IO_BUF[IO_PTR] - '0';
        if (sgn) t = -t;
        return true;
    }
    inline bool scan_s (char s[]) {
        while (IO_PTR < IO_SZ && (IO_BUF[IO_PTR] == ' ' || IO_BUF[IO_PTR] == '\n') ) IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        int len = 0;
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != ' ' && IO_BUF[IO_PTR] != '\n')
            s[len ++] = IO_BUF[IO_PTR], IO_PTR ++;
        s[len] = '\0';
        return true;
    }
    template<typename T>
    void print(T x) {
        static char s[33], *s1; s1 = s;
        if (!x) *s1++ = '0';
        if (x < 0) putchar('-'), x = -x;
        while(x) *s1++ = (x % 10 + '0'), x /= 10;
        while(s1-- != s) putchar(*s1);
    }
    template<typename T>
    void println(T x) {
        print(x); putchar('\n');
    }
};
#define mem(a, i) memset(a, i, sizeof(a))
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i);
const int maxn = 100005;
const int maxk = 10;
int n, k;
int v[maxk];
struct Node {
	int index;
	int val;
	bool operator < (const Node& e) const {
		return val > e.val;
	}
};
priority_queue<Node> q[maxk];
int a[maxn][maxk];
int b[maxn][maxk];

int main() {
	// freopen("a.txt", "r", stdin);
	IO::begin();
	int caseCnt;
	IO::scan_d(caseCnt);
	while(caseCnt--) {
		IO::scan_d(n);
		IO::scan_d(k);
		rep(i, 1, k) while(!q[i].empty()) q[i].pop();
		rep(i, 1, k) IO::scan_d(v[i]);
		rep(i, 1, n) {
			rep(j, 1, k) {
				IO::scan_d(a[i][j]);
			}
			rep(j, 1, k) {
				IO::scan_d(b[i][j]);
			}
		}
		rep(i, 1, n) {
			q[1].push({i, a[i][1]});
		}
		int ans = 0;
		while(1) {
			bool ok = false;
			rep(i, 1, k) {
				while(1) {
					if(q[i].empty()) break;
					bool state = false;
					Node node = q[i].top();
					if(node.val <= v[i]) {
						state = true;
						ok = true;
						q[i].pop();
						if(i == k) {
							ans++;
							rep(j, 1, k) v[j] += b[node.index][j];
						}
						else {
							q[i + 1].push({node.index, a[node.index][i + 1]});
						}
					}
					if(state == false) break;
				}
			}
			if(ok == false) break;
		}
		IO::println(ans);
		rep(i, 1, k) printf("%d%c", v[i], (i == k ? '\n' : ' '));
	}
}
