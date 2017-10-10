#include <iostream>
#include <string>
#include <queue>
using namespace std;
// should be 100, higher for GA input
#define MAXLOC 400 
#define WALL   -1

const int conn[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
int h,w;

int  nloc, nbox, boxloc[2], player, edges[MAXLOC][4];
bool is_goal[MAXLOC+1], done[MAXLOC][MAXLOC+1][MAXLOC];

struct position {
  int box1, box2, player;
};

#define IN_BOUNDS(x,y) (x>=0 && y>=0 && x<w && y < h)

int solve() {
  cin >> h >> w;
  string maze[h];
  int nodelbl[h][w];
  for(int i=0;i<h;++i) cin >> maze[i];

  nloc = nbox = 0;
  for(int i=0;i<h;++i) for(int j=0;j<w;++j) {
    if(maze[i][j]!='#') {
      is_goal[nloc] = (maze[i][j]=='G');
      if(maze[i][j]=='X') boxloc[nbox++] = nloc;
      if(maze[i][j]=='S') player         = nloc;
      nodelbl[i][j] = nloc++;
    }
    else nodelbl[i][j] = WALL;
  }
//  cout << "non-wall count: " << nloc << " boxes: " << nbox << endl;
  if(nbox == 0) return 0;
  if(nbox == 1) boxloc[1] = MAXLOC;

  for(int i=0;i<h;++i) for(int j=0;j<w;++j) {
    if(nodelbl[i][j] == WALL) continue;
    for(int e=0;e<4;++e) {
      int tx = j+conn[e][1], ty = i+conn[e][0];
      edges[nodelbl[i][j]][e] = IN_BOUNDS(tx,ty) ? nodelbl[ty][tx] : WALL;
    }
  }

  for(int i=0;i<MAXLOC;++i)
    for(int j=0;j<=MAXLOC;++j) 
      for(int k=0;k<MAXLOC;++k) done[i][j][k] = false;
  done[boxloc[0]][boxloc[1]][player] = true;
 
  queue<position> q, qto;
  qto.push((position){boxloc[0],boxloc[1],player});

  int moves; // keep track of search depth
  for(moves=0;!qto.empty();moves++) { 
    swap(q,qto);
    while(!q.empty()) { // breadth-first search
      position p = q.front(); q.pop();

      if( is_goal[p.box1] && is_goal[p.box2] ) goto solved;
      for(int e=0;e<4;++e) {
        position next = p;
        if((next.player = edges[p.player][e]) == WALL) continue;
        if(next.player==next.box1) next.box1 = edges[next.box1][e]; // push in same direction
        if(next.player==next.box2) next.box2 = edges[next.box2][e]; 
 
        if(next.box1==WALL || next.box2==WALL || next.box1==next.box2) continue;

        if(done[next.box1][next.box2][next.player]) continue;
        done[next.box1][next.box2][next.player] = true;

        qto.push(next);
      }
    }
  }
  return -1;
 solved:
  return moves;
}



int main() {
  is_goal[MAXLOC] = true;
  int r; cin >> r; 
  while(r--) {
    int sol = solve();
    if (sol >= 0) cout << sol << endl;
    else          cout << "impossible" << endl;
  }
  return 0;
}
