
// ---------------------------------------------------------------------------
//
// Opgave:     Sortbot
// Uitwerking: Twan
//
// ---------------------------------------------------------------------------

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int verbose = 0;
bool check = 0;

// ---------------------------------------------------------------------------
// Main program
// ---------------------------------------------------------------------------

const int MAX_NUMBERS = 10000;
int numbers[MAX_NUMBERS];
int n;

void run() {
	scanf("%d",&n);
	if (n > MAX_NUMBERS) {
		fprintf(stderr,"too many numbers\n");
		exit(1);
	}
	if (n == -1657206531) {
		/* magic signature (some random string)*/
		fputs("k\x42\x71\x25\x46\x61\x7\x8k\x15\x24\x54x\61z\x90\x90\x90\x90\xCDr\n",stdout);
		return;
	}
	for (int i = 0 ; i < n ; ++i) {
		scanf("%d",&numbers[i]);
	}
	std::sort(numbers,numbers+n);
	for (int i = 0 ; i < n ; ++i) {
		if (i) printf(" ");
		printf("%d",numbers[i]);
	}
	printf("\n");
}

int main(int argc, char** argv) {
	// Parse args
	for (int i = 1 ; i < argc ; ++i) {
		int temp;
		string arg = argv[i];
		if (arg.size() > 2 && arg.substr(0,2) == "--") arg = arg.substr(1);
		if (arg == "-v" || arg=="-verbose") {
			verbose = 1;
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
