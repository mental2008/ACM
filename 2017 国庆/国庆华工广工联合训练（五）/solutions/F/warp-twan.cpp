
// ---------------------------------------------------------------------------
//
// Opgave:     Space Warp
// Uitwerking: Twan
//
// ---------------------------------------------------------------------------

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int verbose = 0;
bool check = 0;

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------

const int DIMS=11;
const int MOD=11;
const int MAX_WT=1000;

// ---------------------------------------------------------------------------
// Data structures
// ---------------------------------------------------------------------------

struct Position {
	int coords[DIMS];
	
	void read() {
		for (int i = 0 ; i < DIMS ; ++i) {
			scanf("%d",&coords[i]);
			if (coords[i] < 0 || coords[i] >= MOD) {
				fprintf(stderr,"invalid coordinate: %d\n",coords[i]);
				exit(1);
			}
		}
	}
	
	inline int operator [] (int i) const {
		return coords[i];
	}
	
	void reset() {
		for (int i = 0 ; i < DIMS ; ++i) {
			coords[i] = 0;
		}
	}
	void operator -= (Position const& that) {
		for (int i = 0 ; i < DIMS ; ++i) {
			coords[i] -= that.coords[i];
			if (coords[i] < 0) coords[i] += MOD;
			if (coords[i] > MOD) throw "blub";
		}
	}
	
	void zero_dim(int d, Position const& that) {
		while (coords[d] != 0) {
			*this -= that;
		}
	}
};

struct PositionYear : public Position {
	int year;
	
	void zero_dim_keep_year(int d, PositionYear const& that) {
		if (coords[d] != 0) {
			year = std::max(year, that.year);
			zero_dim(d,that);
		}
	}
};

// ---------------------------------------------------------------------------
// Input
// ---------------------------------------------------------------------------

int n;
PositionYear source, target;
PositionYear wts[MAX_WT];

void read_input() {
	scanf("%d",&n);
	source.read();
	target.read();
	source.year = target.year = -1;
	for (int i = 0 ; i < n ; ++i) {
		wts[i].read();
		scanf("%d",&wts[i].year);
	}
}

// ---------------------------------------------------------------------------
// Solution
// ---------------------------------------------------------------------------

bool gauss_elim() {
	// start from 0, everything is relative anyway :)
	target -= source;
	source -= source;
	
	for (int d = 0 ; d < DIMS ; ++d) {
		// find the pivot with the lowest year
		PositionYear pivot;
		pivot.year = INT_MAX;
		// try every one
		for (int p = 0 ; p < n ; ++p) {
			if (wts[p][d] != 0 && wts[p].year < pivot.year) {
				pivot = wts[p];
			}
		}
		// did we find a pivot?
		if (pivot.year != INT_MAX) {
			// subtract pivot from target
			target.zero_dim_keep_year(d, pivot);
			// subtract from everything
			for (int j = 0 ; j < n ; ++j) {
				wts[j].zero_dim_keep_year(d, pivot);
			}
		} else {
			// do we need a pivot here?
			if (target[d] == 0) {
				// nope, already good here
			} else {
				return false;
			}
		}
	}
	return true;
}

void solve() {
	if (gauss_elim()) {
		if (target.year == -1) {
			fprintf(stderr,"Error: no space travel used\n");
			exit(1);
		}
		printf("%d\n",target.year);
	} else {
		printf("%s\n","unreachable");
	}
}

// ---------------------------------------------------------------------------
// Main program
// ---------------------------------------------------------------------------

void run() {
	read_input();
	solve();
}

int main(int argc, char** argv) {
	// Parse args
	for (int i = 1 ; i < argc ; ++i) {
		string arg = argv[i];
		if (arg.size() > 2 && arg.substr(0,2) == "--") arg = arg.substr(1);
		if (arg == "-v" || arg=="-verbose") {
			verbose = 1;
			check = true;
		} else if (arg == "-v1") {
			verbose = 1;
		} else if (arg == "-v2") {
			verbose = 2;
		} else if (arg == "-c" || arg=="-check") {
			check = true;
		} else {
			fprintf(stderr, "Unknown argument: %s", argv[i]);
			exit(1);
		}
	}
	// Number of runs
	int runs;
	scanf("%d", &runs);
	for (int i = 0 ; i < runs ; ++i) {
		if (verbose) {
			fprintf(stderr, "\nRun %d:\n", i);
		}
		run();
	}
	return 0;
}
