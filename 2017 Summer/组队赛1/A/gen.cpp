#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MIN_n = 3, MIN_m = 10;
const int MID_n = 8, MID_m = 100;
const int MAX_n = 20, MAX_m = 1000;
const int MIN_c = 10;
const int MID_c = 1000*1000;
const int MAX_c = 1000*1000;
int rand(int lb,int ub){
	return rand()%(ub-lb)+lb;
}
int l[MAX_n],g[MAX_n];
void test_case(int limit_n,int limit_m,int limit_c){
	int n = rand(2,limit_n+1), m = rand(1,limit_m+1);
	printf("%d %d\n",n,m);
	int half_n = n/2;
	for (int i = 0; i < m; ++i){
		int B = rand(0,half_n*(i+1)/m+1);
		int W = half_n - B;
		int c = rand(1,limit_c+1);
		printf("%d %d %d",B,W,c);
		int mask = 0;
		for (int j = 0; j < B; ++j){
			int li;
			do{
				li = rand(0,n);
			}while(mask>>li&1);
			mask |= 1<<li;
			printf(" %d",li);
		}
		for (int j = 0; j < W; ++j){
			int gi;
			do{
				gi = rand(0,n);
			}while(mask>>gi&1);
			mask |= 1<<gi;
			printf(" %d",gi);
		}
		printf("\n");
	}
}
int main(){
	srand(time(0));
	for (int i = 0; i < 20; ++i)
		test_case(MIN_n,MIN_m,10);
	for (int i = 0; i < 10; ++i)
		test_case(MID_n,MID_m,MID_c);
	for (int i = 0; i < 10; ++i)
		test_case(MAX_n,MID_m,MAX_c);
	for (int i = 0; i < 10; ++i)
		test_case(MAX_n,MAX_m,MAX_c);
}
