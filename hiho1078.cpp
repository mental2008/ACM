#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100000
using namespace std;
int a[maxn + 5];

struct SegTreeNode{
	int val;
	int addMark;
	int left, right;
}SegTree[3 * maxn];

void build(int root, int start, int end){
	SegTree[root].addMark = 0;
	SegTree[root].left = start;
	SegTree[root].right = end;
	if(start == end){
		SegTree[root].val = a[start];
		return;
	}
	int mid = (start + end) / 2;
	build(root * 2, start, mid);
	build(root * 2 + 1, mid + 1, end);
	SegTree[root].val = SegTree[root * 2].val + SegTree[root * 2 + 1].val;
}

void pushDown(int root){
	if(SegTree[root].addMark != 0){
		SegTree[root * 2].addMark = SegTree[root].addMark;
		SegTree[root * 2 + 1].addMark = SegTree[root].addMark;
		SegTree[root * 2].val = (SegTree[root * 2].right - SegTree[root * 2].left + 1) * SegTree[root].addMark;
		SegTree[root * 2 + 1].val = (SegTree[root * 2 + 1].right - SegTree[root * 2 + 1].left + 1) * SegTree[root].addMark;
		SegTree[root].addMark = 0;
	}
}

int update(int root, int start, int end, int l, int r, int addVal){
	if(start > r || end < l){
		return SegTree[root].val;
	}
	if(start >= l && end <= r){
		SegTree[root].val = (end - start + 1) * addVal;
		SegTree[root].addMark = addVal;
		return SegTree[root].val;
	}
	pushDown(root);
	int mid = (start + end) / 2;
	return SegTree[root].val = (update(root * 2, start, mid, l, r, addVal) + update(root * 2 + 1, mid + 1, end, l, r, addVal));
}

int query(int root, int start, int end, int l, int r){
	if(start > r || end < l){
		return 0;
	}
	if(start >= l && end <= r){
		return SegTree[root].val;
	}
	pushDown(root);
	int mid = (start + end) / 2;
	return (query(root * 2, start, mid, l, r) + query(root * 2 + 1, mid + 1, end, l, r));
}

int main(){
	memset(a, 0, sizeof(a));
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int order;
		int l, r;
		scanf("%d%d%d", &order, &l, &r);
		if(order == 1){
			int value;
			scanf("%d", &value);
			update(1, 1, n, l, r, value);
		}
		else if(order == 0){
			int ans = query(1, 1, n, l, r);
			printf("%d\n", ans);
		}
	}
	return 0;
}
