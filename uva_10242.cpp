#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
	double x, y;
};

bool operator == (node first, node second){
	if(first.x == second.x && first.y == second.y) return true;
	else return false;
}

int main(){
	node a[4];
	while(cin >> a[0].x >> a[0].y){
		for(int i = 1; i < 4; i++){
			cin >> a[i].x >> a[i].y;
		}
		if(a[1] == a[3]) swap(a[2], a[3]);
		else if(a[0] == a[2]) swap(a[0], a[1]);
		else if(a[3] == a[0]){
			swap(a[0], a[1]);
			swap(a[2], a[3]);
		}
		printf("%.3lf %.3lf\n", a[0].x - a[1].x + a[3].x, a[0].y - a[1].y + a[3].y);
	}
	return 0;
}
