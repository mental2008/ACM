#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
#define LL long long
using namespace std;
LL a[maxn + 5];

struct SegTreeNode{
	LL val;
	LL addMark;
	LL left, right;
}SegTree[3 * maxn];

void build(LL root, LL start, LL end){
	SegTree[root].addMark = 0;
	SegTree[root].left = start;
	SegTree[root].right = end;
	if(start == end){
		SegTree[root].val = a[start];
		return;
	}
	LL mid = (start + end) / 2;
	build(root * 2, start, mid);
	build(root * 2 + 1, mid + 1, end);
	SegTree[root].val = SegTree[root * 2].val + SegTree[root * 2 + 1].val;
}

void pushDown(LL root){
	if(SegTree[root].addMark != 0){
		SegTree[root * 2].addMark += SegTree[root].addMark;
		SegTree[root * 2 + 1].addMark += SegTree[root].addMark;
		SegTree[root * 2].val += ((SegTree[root * 2].right - SegTree[root * 2].left + 1) * SegTree[root].addMark);
		SegTree[root * 2 + 1].val += ((SegTree[root * 2 + 1].right - SegTree[root * 2 + 1].left + 1) * SegTree[root].addMark);
		SegTree[root].addMark = 0;
		return;
	}
}

void update(LL root, LL start, LL end, LL l, LL r, LL addVal){
	if(start > r || end < l){
		return;
	}
	if(start >= l && end <= r){
		SegTree[root].val += ((end - start + 1) * addVal);
		SegTree[root].addMark += addVal;
		return;
	}
	pushDown(root);
	LL mid = (start + end) / 2;
	update(root * 2, start, mid, l, r, addVal);
	update(root * 2 + 1, mid + 1, end, l, r, addVal);
	SegTree[root].val = SegTree[root * 2].val + SegTree[root * 2 + 1].val;
}

LL query(LL root, LL start, LL end, LL l, LL r){
	if(start > r || end < l){
		return 0;
	}
	if(start >= l && end <= r){
		return SegTree[root].val;
	}
	pushDown(root);
	LL mid = (start + end) / 2;
	return (query(root * 2, start, mid, l, r) + query(root * 2 + 1, mid + 1, end, l, r));
}

int main(){
	LL n, q;
	while(~scanf("%lld%lld", &n, &q)){
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		build(1, 1, n);
		for(int i = 0; i < q; i++){
			char order;
			LL l, r;
			cin >> order;
			scanf("%lld%lld", &l, &r);
			if(order == 'Q'){
				LL ans = query(1, 1, n, l, r);
				printf("%lld\n", ans);
			}
			else if(order == 'C'){
				LL value;
				scanf("%lld", &value);
				update(1, 1, n, l, r, value);
			}
		}
	}
	return 0;
}
