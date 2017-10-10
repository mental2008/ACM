#include <queue>
#include <stdio.h>
#include <utility>
#include <climits>

const int MAXROWS = 1000;
const int MAXCOLS = 1000;
const bool DEBUG = false;
const bool USE_HATCHES = true;

int cap[MAXROWS+1][MAXCOLS+1][2]; // Size adjusted to make boundary conditions easier (simply have zero-capacity links to the left and up on the right and bottom borders)
int flow[MAXROWS+1][MAXCOLS+1][2];
int previous[MAXROWS][MAXCOLS]; // Points to previous node in augmenting path (-2 for root, -1 for none yet, 0 for left, 1 for up, 2 for down and 3 for right)
int seen[MAXROWS][MAXCOLS];

void neighbour(int r, int c, int n, int* nr, int *nc) {
    *nr = r;
    *nc = c;
    switch(n) {
    case 0: // left
        (*nc)--;
        break;
    case 1: // up
        (*nr)--;
        break;
    case 2: // down
        (*nr)++;
        break;
    case 3: // right
        (*nc)++;
        break;
    default:
        fprintf(stderr, "Invalid neighbour!\n");
    }
}

int residualCapacity(int r, int c, int n) {
    switch(n) {
    case 0: // left
        return cap[r][c][0] - flow[r][c][0];
    case 1: // up
        return cap[r][c][1] - flow[r][c][1];
    case 2: // down
        return cap[r+1][c][1] + flow[r+1][c][1];
    case 3: // right
        return cap[r][c+1][0] + flow[r][c+1][0];
    }
    return 0;
}

int augmentFlow(int r, int c, int n, int f) {
    switch(n) {
    case 0: // left
        flow[r][c][0] += f;
        break;
    case 1: // up
        flow[r][c][1] += f;
        break;
    case 2: // down
        flow[r+1][c][1] -= f;
        break;
    case 3: // right
        flow[r][c+1][0] -= f;
        break;
    }
    return 0;
}

int findFlow(int w, int d, int kr, int kc) {
    int r, c, pr, pc, mincap=INT_MAX, lc;

    if (DEBUG) fprintf(stderr, "Augmenting path (in reverse order): (%d,%d)", kr,kc);
    // Back-track to find minimum capacity
    r = kr; c = kc;
    while(previous[r][c]!=-2) {
        neighbour(r,c,previous[r][c],&pr,&pc);
        lc = residualCapacity(pr,pc,3-previous[r][c]);
        if (lc<mincap) mincap = lc;
        r = pr; c = pc;
        if (DEBUG) fprintf(stderr, " (%d,%d)", r,c);
    }
    if (DEBUG) fprintf(stderr, "\n  Capacity = %d\n", mincap);

    // Back-track to mark increased flow
    r = kr; c = kc;
    while(previous[r][c]!=-2) {
        neighbour(r,c,previous[r][c],&pr,&pc);
        augmentFlow(pr,pc,3-previous[r][c],mincap);
        r = pr; c = pc;
    }

    return mincap;
}

int findAugmentingPathFlow(int w, int d, int er, int ec, int kr, int kc) {
    int r,c,n;

    // Initialize arrays
    for(r=0; r<w; r++) {
        for(c=0; c<d; c++) {
            seen[r][c] = 0;
            previous[r][c] = -1;
        }
    }
    previous[er][ec] = -2;

    // Find augmenthing path breadth-first
    std::queue< std::pair<int,int> > q;
    q.push(std::make_pair(er,ec));
    while(!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for(n=0; n<4; n++) {
            int nr, nc;
            neighbour(r,c,n,&nr,&nc);
            if (residualCapacity(r,c,n)>0 && previous[nr][nc]==-1) {
                previous[nr][nc] = 3-n; // 3-0=3, 3-1=2, 3-2=1, 3-3=0
                if (nr==kr && nc==kc) { // We found the kitchen-connected room
                    return findFlow(w, d, kr, kc);
                } else {
                    q.push(std::make_pair(nr,nc));
                }
            }
        }
    }
    return 0;
}

int maxFlow(int w, int d, int er, int ec, int kr, int kc) {
    int maxflow = 0;
    int mincap;
    while((mincap=findAugmentingPathFlow(w,d, er,ec, kr,kc))>0) {
        maxflow += mincap;
        if (DEBUG)
        for(int r=0; r<w; r++) {
            for(int c=0; c<d; c++) {
                fprintf(stderr, "(%d/%d,%d/%d) ", flow[r][c][0], cap[r][c][0], flow[r][c][1], cap[r][c][1]);
            }
            fprintf(stderr, "\n");
        }
    }
    return maxflow;
}

void run() {
    int w, d, er, ec, kr, kc, r, c;

    // Read input
    scanf("%d %d %d %d %d %d",&w,&d,&er,&ec,&kr,&kc);
    for(r=0; r<=w; r++) {
        for(c=0; c<=d; c++) {
            cap[r][c][0] = 0;
            cap[r][c][1] = 0;
            flow[r][c][0] = 0;
            flow[r][c][1] = 0;
        }
    }
    for(r=0; r<w; r++) {
        for(c=1; c<d; c++) {
            scanf("%u",&cap[r][c][0]);
            if (USE_HATCHES && cap[r][c][0]>0) cap[r][c][0] += 1; // This is for the hatches
        }
    }
    for(r=1; r<w; r++) {
        for(c=0; c<d; c++) {
            scanf("%u",&cap[r][c][1]);
            if (USE_HATCHES && cap[r][c][1]>0) cap[r][c][1] += 1; // This is for the hatches
        }
    }

    // Compute maximum flow
    int maxflow = maxFlow(w,d, er,ec, kr,kc);

    // Print result
    printf("%u\n", maxflow*1000);
}

int main() {
    int runs;
    scanf("%d",&runs);
    while(runs-->0) run();
    return 0;
}
