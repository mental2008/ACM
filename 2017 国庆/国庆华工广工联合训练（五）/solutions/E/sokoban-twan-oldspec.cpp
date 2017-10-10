
// ---------------------------------------------------------------------------
//
// Opgave:     Sokoban
// Uitwerking: Twan
//
// ---------------------------------------------------------------------------

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

int verbose = 0;

// ---------------------------------------------------------------------------
// Input
// ---------------------------------------------------------------------------

struct Pos {
	short x,y;
	Pos(){}
	Pos(short x, short y) : x(x),y(y) {}
	inline bool operator < (const Pos& p) const {
		if (x < p.x) return true;
		if (x > p.x) return false;
		return y < p.y;
	}
	inline bool operator > (const Pos& p) const {
		return p < *this;
	}
	inline bool operator == (const Pos& p) const {
		return x == p.x && y == p.y;
	}
};

#define MAX_W 50
#define MAX_H 50
#define MAX_BOX 2
//#define MAX_BOX 12

int w,h;
char grid[MAX_H][MAX_W+1];
const char EMPTY  = '.';
const char WALL   = '#';
const char START  = 'S';
const char BOX    = 'X';
const char GOAL   = 'G';

void dump() {
	for (int y = 0 ; y < h ; ++y) {
		for (int x = 0 ; x < w ; ++x) {
			fprintf(stderr,"%c",grid[y][x]);
		}
		fprintf(stderr,"\n");
	}
}

void read_input() {
	// Read number
	scanf("%d %d", &h, &w);
	if (h > MAX_H || w > MAX_W) {
		fprintf(stderr, "Grid too large!\n");
		exit(1);
	}
	// Read grid
	for (int y = 0 ; y < h ; ++y) {
		scanf(" ");
		fgets(grid[y], MAX_W+1, stdin);
	}
}

// ---------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------

int number_of_boxes;
class State;
void add_state(const State& s);

struct State {
	Pos me;
	Pos box[MAX_BOX];
	int step;
	
	inline bool operator < (const State& s) const {
		if (me < s.me) return true;
		if (me > s.me) return false;
		for (int i = 0 ; i < number_of_boxes ; ++i) {
			if (box[i] < s.box[i]) return true;
			if (box[i] > s.box[i]) return false;
		}
		return false;
	}
	
	bool done() const {
		for (int i = 0 ; i < number_of_boxes ; ++i) {
			if (grid[box[i].y][box[i].x] != GOAL) return false;
		}
		return true;
	}
	
	void try_move(int dx, int dy) const {
		// new state
		State s2;
		s2.me   = Pos(me.x+dx, me.y+dy);
		s2.step = step + 1;
		// valid?
		if (!is_valid(s2.me.x, s2.me.y)) return;
		// push a box?
		Pos push_from = s2.me;
		Pos push_to(s2.me.x+dx, s2.me.y+dy);
		for (int i = 0 ; i < number_of_boxes ; ++i) {
			s2.box[i] = box[i];
			if (box[i] == push_from) {
				if (!is_valid_box(push_to.x, push_to.y)) return;
				s2.box[i] = push_to;
			}
		}
		if (verbose >= 2) {
			fprintf(stderr, "   move x%d y%d ", dx,dy);
		}
		// normal form
		sort(s2.box, s2.box + number_of_boxes);
		// good state
		add_state(s2);
	}
	
	bool is_valid(int x, int y) const {
		if (y < 0 || x < 0 || y >= h || x >= w) return false;
		if (grid[y][x] == WALL) return false;
		return true;
	}
	bool is_valid_box(int x, int y) const {
		if (y < 0 || x < 0 || y >= h || x >= w) return false;
		if (grid[y][x] == WALL) return false;
		for (int i = 0 ; i < number_of_boxes ; ++i) {
			if (box[i] == Pos(x,y)) return false; // double push
		}
		return true;
	}
	
	void dump() const {
		fprintf(stderr, "  %d: (%d,%d)", step, me.x,me.y);
		for (int i = 0 ; i < number_of_boxes ; ++i) {
			fprintf(stderr, " [%d,%d]", box[i].x, box[i].y);
		}
		fprintf(stderr, "\n");
	}
};

deque<State> to_process;
set<State> seen;

void add_state(const State& s) {
	if (seen.find(s) != seen.end()) {
		if (verbose >= 2) fprintf(stderr, ":(\n");
		return;
	} else {
		if (verbose >= 2) fprintf(stderr, ":)\n");
	}
	seen.insert(s);
	to_process.push_back(s);
}

void init_states() {
	to_process.clear();
	seen.clear();
	// initial state
	State initial;
	initial.me = Pos(-1,-1);
	initial.step = 0;
	number_of_boxes = 0;
	for (int y = 0 ; y < h ; ++y) {
		for (int x = 0 ; x < w ; ++x) {
			if (grid[y][x] == START) {
				if (initial.me.x != -1) {
					fprintf(stderr,"More than one intitial position");
					exit(1);
				}
				initial.me = Pos(x,y);
			} else if (grid[y][x] == BOX) {
				initial.box[number_of_boxes] = Pos(x,y);
				number_of_boxes++;
			}
		}
	}
	if (initial.me.x == -1) {
		fprintf(stderr,"No initial position");
		exit(1);
	}
	add_state(initial);
}

int solve() {
	init_states();
	while (!to_process.empty()) {
		const State& s = to_process.front();
		if (verbose >= 2) s.dump();
		// is this state done?
		if (s.done()) return s.step;
		// make a move
		s.try_move(-1,0);
		s.try_move(1,0);
		s.try_move(0,-1);
		s.try_move(0,1);
		// done with s
		to_process.pop_front();
	}
	return -1;
}

// ---------------------------------------------------------------------------
// Main program
// ---------------------------------------------------------------------------

void run() {
	read_input();
	int steps = solve();
	if (steps == -1) {
		printf("%s\n","impossible");
	} else {
		printf("%d\n",steps);
	}
	if (verbose >= 1) {
		fprintf(stderr, " total seen: %d\n", seen.size());
		dump();
	}
}

int main(int argc, char** argv) {
	// Flags
	for (int i = 1 ; i < argc ; ++i) {
		string arg = argv[i];
		if (arg.size() > 2 && arg.substr(0,2) == "--") arg = arg.substr(1);
		if (arg == "-v" || arg=="-verbose") {
			verbose = 1;
		} else if (arg == "-v2") {
			verbose = 2;
		} else {
			fprintf(stderr, "Unknown argument: %s", argv[i]);
		}
	}
	// Number of runs
	int runs;
	scanf("%d", &runs);
	while (runs --> 0) run();
	return 0;
}
