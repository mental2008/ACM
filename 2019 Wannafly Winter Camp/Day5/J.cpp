#include <iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))
inline int sign(__int128 a) { return a<0 ? -1 : a>0; }
inline int cmp(__int128 a, __int128 b) { return sign(a - b); }
struct P {
	__int128 x, y;
	P(){}
	P(__int128 _x,__int128 _y):x(_x),y(_y){}
	P operator+(P p) { return { x + p.x,y + p.y }; }
	P operator-(P p) { return { x - p.x,y - p.y }; }
	P operator*(__int128 d) { return { x*d,y*d }; }
	bool operator<(P p)const {
		int c = cmp(x, p.x);
		if (c)return c == -1;
		return cmp(y, p.y) == -1;
	}
	bool operator==(P p)const {
		return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
	}
    __int128 dot(P p) { return x*p.x+y*p.y; }
};

bool intersect(__int128 l1, __int128 r1, __int128 l2, __int128 r2)
{
	if (l1 > r1)
		swap(l1, r1);
	if (l2 > r2)
		swap(l2, r2);
	return !(cmp(r1, l2) == -1 || cmp(r2, l1) == -1);
}
bool isSS(P p1, P p2, P q1, P q2)
{
	return intersect(p1.x, p2.x, q1.x, q2.x) && intersect(p1.y, p2.y, q1.y, q2.y)
		&& crossOp(p1, p2, q1)*crossOp(p1, p2, q2) <= 0 && crossOp(q1, q2, p1)*crossOp(q1, q2, p2) <= 0;
}

// bool isMiddle(__int128 a, __int128 m, __int128 b) {
//     return sign(a-m)==0||sign(b-m)==0||(a<m!=b<m);
// }
// bool isMiddle(P a, P m, P b) {
//     return isMiddle(a.x, m.x, b.x) && isMiddle(a.y, m.y, b.y);
// }
bool onSeg_strict(P p1, P p2, P q) {
    return crossOp(p1,p2,q)==0&&sign((q-p1).dot(p1-p2))*sign((q-p2).dot(p1-p2))<0;
}

// bool isSS_strict(P p1, P p2, P q1, P q2)
// {
// 	return crossOp(p1, p2, q1)*crossOp(p1, p2, q2) < 0 && crossOp(q1, q2, p1)*crossOp(q1, q2, p2) < 0;
// }
const int maxn = 2050;
struct node {
	int id1, id2;
};
node fuck[maxn];
P a[maxn];
int main()
{
	long long i, j, k, n, m,ans;
	while (scanf("%lld%lld", &n, &m) != EOF)
	{
		ans = 0;
		for (i = 1; i <= m; i++)
			scanf("%d%d", &fuck[i].id1, &fuck[i].id2);
		for (i = 1; i <= n; i++) {
            ll x,y;
            scanf("%lld%lld", &x, &y);
            a[i].x=x;
            a[i].y=y;
        }
		for (i = 1; i <= m; i++)
			for (j = i + 1; j <= m; j++)
				if (isSS(a[fuck[i].id1], a[fuck[i].id2], a[fuck[j].id1], a[fuck[j].id2])) {
                    if(fuck[i].id1==fuck[j].id1||fuck[i].id1==fuck[j].id2||fuck[i].id2==fuck[j].id1||fuck[i].id2==fuck[j].id2) {
                        if(onSeg_strict(a[fuck[i].id1],a[fuck[i].id2],a[fuck[j].id1])||onSeg_strict(a[fuck[i].id1],a[fuck[i].id2],a[fuck[j].id2])||onSeg_strict(a[fuck[j].id1],a[fuck[j].id2],a[fuck[i].id1])||onSeg_strict(a[fuck[j].id1],a[fuck[j].id2],a[fuck[i].id2])) {
                            ans++;
                        }
                    }
                    else {
                        ans++;
                    }
                    
                }
					
		printf("%lld\n", ans);
	}
}

