#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define maxn 100000
using namespace std;
int a[maxn+5];

struct SegTreeNode{
	int val;
	int addMark;
}segTree[3*maxn];

void build(int root, int start, int end){
	segTree[root].addMark = 0;
	if(start == end){
		segTree[root].val = a[start];
	}
	else{
		int mid = (start + end) / 2;
		build(root*2, start, mid);
		build(root*2+1, mid+1, end);
		segTree[root].val = max(segTree[root*2].val, segTree[root*2+1].val);
	}
}

void pushDown(int root){
	if(segTree[root].addMark != 0){
		segTree[root*2].addMark += segTree[root].addMark;
		segTree[root*2+1].addMark += segTree[root].addMark;
		segTree[root*2].val += segTree[root].addMark;
		segTree[root*2+1].val += segTree[root].addMark;
		segTree[root].addMark = 0;
	}
}

int query(int root, int nstart, int nend, int qstart, int qend){
	if(qstart > nend || qend < nstart){
		return -0x3f3f3f3f;
	}
	if(qstart <= nstart && qend >= nend){
		return segTree[root].val;
	}
	pushDown(root);
	int mid = (nstart + nend) / 2;
	return max(query(root*2, nstart, mid, qstart, qend), query(root*2+1, mid+1, nend, qstart, qend));
}

void update(int root, int nstart, int nend, int ustart, int uend, int addVal){
	if(ustart > nend || uend < nstart)
		return;
	if(ustart <= nstart && uend >= nend){
		segTree[root].addMark += addVal;
		segTree[root].val += addVal;
		return;
	}
	pushDown(root);
	int mid = (nstart + nend) / 2;
	update(root*2, nstart, mid, ustart, uend, addVal);
	update(root*2+1, mid+1, nend, ustart, uend, addVal);
	segTree[root].val = max(segTree[root*2].val, segTree[root*2+1].val);
}

int main(){
	int n, q;
	while(~scanf("%d%d", &n, &q)){
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		build(1, 1, n);
		for(int i = 0; i < q; i++){
			string order;
			int l, r;
			cin >> order;
			scanf("%d%d", &l, &r);
			if(order == "Add"){
				int value;
				scanf("%d", &value);
				update(1, 1, n, l, r, value);
			}
			else if(order == "Qry"){
				int ans = query(1, 1, n, l, r);
				printf("The answer is %d.\n", ans);
			}
		}
	}
	return 0;
}
