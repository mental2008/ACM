#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000000
using namespace std;
int a[maxn+5];

struct SegTreeNode{
	int val;
	int addMark;
}SegTree[3*maxn];

void build(int root, int start, int end){
	SegTree[root].addMark = 0;
	if(start == end){
		SegTree[root].val = a[start];
		return;
	}
	int mid = (start + end) / 2;
	build(root * 2, start, mid);
	build(root * 2 + 1, mid + 1, end);
	SegTree[root].val = min(SegTree[root*2].val, SegTree[root*2+1].val);
}

void pushDown(int root){
	if(SegTree[root].addMark != 0){
		SegTree[root*2].addMark += SegTree[root].addMark;
		SegTree[root*2+1].addMark += SegTree[root].addMark;
		SegTree[root*2].val += SegTree[root].addMark;
		SegTree[root*2+1].val += SegTree[root].addMark;
		SegTree[root].addMark = 0;
	}
}

int query(int root, int start, int end, int l, int r){
	if(end < l || start > r){
		return 0x3f3f3f3f;
	}
	if(start >= l && end <= r){
		return SegTree[root].val;
	}
	pushDown(root);
	int mid = (start + end) / 2;
	return min(query(root*2, start, mid, l, r), query(root*2+1, mid+1, end, l, r));
}

void update(int root, int start, int end, int l, int r, int addVal){
	if(end < l || start > r){
		return;
	}
	if(start >= l && end <= r){
		SegTree[root].val += addVal;
		SegTree[root].addMark += addVal;
		return;
	}
	pushDown(root);
	int mid = (start + end) / 2;
	update(root*2, start, mid, l, r, addVal);
	update(root*2+1, mid+1, end, l, r, addVal);
}

void updateOne(int root, int start, int end, int index, int weight){
	if(start == end){
		if(start == index) SegTree[root].val = weight;
		return;
	}
	int mid = (start + end) / 2;
	if(mid >= index) updateOne(root*2, start, mid, index, weight);
	else updateOne(root*2+1, mid+1, end, index, weight);
	SegTree[root].val = min(SegTree[root*2].val, SegTree[root*2+1].val);
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
	while(q--){
		int order;
		scanf("%d", &order);
		if(order == 0){
			int l, r;
			scanf("%d%d", &l, &r);
			int ans = query(1, 1, n, l, r);
			printf("%d\n", ans);
		}
		else if(order == 1){
			int P, weight;
			scanf("%d%d", &P, &weight);
			a[P] = weight;
			updateOne(1, 1, n, P, weight);
		}
	}
	return 0;
}
