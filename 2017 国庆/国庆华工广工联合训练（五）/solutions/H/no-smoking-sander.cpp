#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct state { int node, flow, parent;};
struct edge  { int to, maxcap; mutable int cap;};
bool operator<(state a,state b) { return a.flow < b.flow; }// voor priority_queue
bool operator<(edge a,edge b)   { return a.to < b.to; }    // voor set

typedef vector<state> VS;
typedef set<edge>     SE;

const int inf = 2000000000, maxN = 4*999*999;
const int USE_HATCHES = true;

SE edges[maxN]; // adjacency 'lists': array van sets van edges

int network_flow(int n,int source, int sink) {
  int totalflow = 0;
  if (source < 0 || source >= n) fprintf(stderr,"source fail %d >= %d\n",source,n);
  if (sink < 0 || sink >= n) fprintf(stderr,"sink fail %d >= %d\n",sink,n);
  while(1) {
    // vind pad
    priority_queue<state> pq;
    pq.push( (state){source,inf,-1} );
    VS best(n, (state){-1,0,-1} );
    while(!pq.empty()) {
      state s = pq.top(); pq.pop();
      if(best[s.node].node!=-1) continue; // al geweest.
      best[s.node] = s;
      if(s.node==sink) break;
  
      for(SE::iterator i=edges[s.node].begin() ; i!=edges[s.node].end() ;++i) {
        if(best[i->to].flow==0) {
          if (s.node < 0 || s.node >= maxN) fprintf(stderr,"bork2 %d\n",s.node);
          pq.push( (state){ i->to , min(i->cap,s.flow), s.node } ); 
        }
      }//for edges
    }// while finding path
    if(best[sink].flow==0) break; // geen pad meer naar sink
    // pad toevoegen
    int to = sink, fr, flow = best[sink].flow;
    for(to = sink; to != source; to = fr) {
      fr = best[to].parent;
      if (fr < 0 || fr >= maxN) {
        fprintf(stderr,"bork %d\n",fr);
      }
      edges[fr].find((edge){to})->cap -= flow;
      edges[to].find((edge){fr})->cap += flow;
    }
    totalflow += flow;
  }
  return totalflow;
}

int r,w,d,srcx,srcy,sinkx,sinky,n,sinki,sourcei,l,u; 
#define IJtoN(i,j) ((d*(i))+j)

int main() {
  cin >> r;
  while(r--) {
    cin >> w >> d >> srcx >> srcy >> sinkx >> sinky;
   // cout << "w:" << w << " d:" << d << " src:" << srcx << "," << srcy << endl;
    n=w*d;
    fill(edges,edges+n,SE());
    for(int i=0;i<w;++i) for(int j=1;j<d;++j) {
      cin >> l; 
      if(l > 0) {
        int from = IJtoN(i,j), to = IJtoN(i,j-1), cap = 1000 * (l+USE_HATCHES);
        edges[from].insert((edge){to,cap,cap});
        edges[to].insert((edge){from,cap,cap});
      }
    }
    for(int i=1;i<w;++i) for(int j=0;j<d;++j) {
      cin >> u; 
      if(u > 0) {
        int from = IJtoN(i,j), to = IJtoN(i-1,j), cap = 1000 * (u+USE_HATCHES);
        edges[from].insert((edge){to,cap,cap});
        edges[to].insert((edge){from,cap,cap});
      }
    }
    //cout << network_flow(n,IJtoN(srcx-1,srcy-1), IJtoN(sinkx-1,sinky-1)) << endl;
    cout << network_flow(n,IJtoN(srcx,srcy), IJtoN(sinkx,sinky)) << endl;
  }
}


