#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

#define DEBUG 0
#define I_AM_AN_IDOIT 0 // fixed by Twan
#define ONLY_A_FEW_ANGLES 0 

#define V0    25
#define VMINE 10
#define FRICTION 5
#define G     9.81
#define EPS   1e-6
#define MAXN  1000
#define MINE  0
#define SPIKE 1

struct position {
  double x,y,vx,vy;
  position land() const {
    position ret = *this;
    double t = (vy + sqrt(vy*vy + 2*G*y)) / G; // solve quadratic eqn
    ret.vy = ret.y = 0; // splat
    ret.x  = x + t * vx;
    return ret;
  }
};
struct obstacle {
  double pos;
  int type;
  bool operator<(const obstacle& other) const {
    return pos < other.pos;
  }
};
obstacle items[MAXN];

int n;


int simulate(const position& p) {
	position l = p.land();
	for(int i=0;i<n;++i) {
		if (l.x < items[i].pos+EPS && l.x + l.vx/FRICTION + EPS > items[i].pos) { // hits object
			if (items[i].type == SPIKE) {
				if (DEBUG) {
					printf("SPIKED: %f+%f hits %f ! \n",l.x,l.vx/FRICTION,items[i].pos);
				}
				return -100;
			}
			l.vx -= FRICTION * (items[i].pos - l.x);
			#if !I_AM_AN_IDOIT
				l.x = items[i].pos; // Don't forget this!
			#endif
			l.vy += VMINE;
			return simulate(l);
		}
	}
	#if 0 //!I_AM_AN_IDOIT
		l.x += l.vx/FRICTION;
	#endif
	return static_cast<int>( 100 * l.x + 0.5 );
}

int main() {
	int r; scanf("%d",&r);
	while(r--) {
		scanf("%d",&n); 
		char tmp[100];
		for(int i=0;i<n;++i) {
			scanf("%lf %s",&(items[i].pos),tmp);
			items[i].type = !!strcmp(tmp,"mine");
			if(DEBUG==1)  printf("%d %f\n",items[i].type,items[i].pos);
		}
		sort(items,items+n);
		int best=-90; int best_score = 0;
#if ONLY_A_FEW_ANGLES
		for(int i=68;i<71;++i) {
#else
		for(int i=-89;i<90;++i) {
#endif
			double angle = 3.1415926535897932384626 * i / 180;
			int score = simulate( (position){0,1,V0*cos(angle),V0*sin(angle)  } );
			if (DEBUG) {
				printf("a = %d -> score=%d\n",i,score);
			}
			if(score > best_score) { best=i; best_score=score; }
		}
		printf("%d %d\n",best_score, best);
		if(DEBUG > 0)   printf("\tdistance = %fm\n",best_score);
	}
}
