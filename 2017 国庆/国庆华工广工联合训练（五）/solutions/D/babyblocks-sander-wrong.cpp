#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


#define MAXN 26
unsigned long long facs[MAXN+1] = {1,1};
int done[256];

int main() {
  for(int i=2; i<=MAXN; ++i) facs[i] = facs[i-1] * i;

  string blocks,target;
  int r; cin >> r;
  getline(cin,blocks); // newline
  while(r--) {
    getline(cin,target);
    blocks = target;
    sort(blocks.begin(),blocks.end());
    unsigned long long tot = 0;
    int s = target.size();
    for(int i=0;i<256;++i) done[i]=0;
    for(int i=0;i<s;i++) {
      for(int j=0; blocks[j] < target[i] ;j++) if(!done[blocks[j]]) tot += facs[s - i - 1];
      done[target[i]] = 1;
    }
    cout << tot << endl;
  }
  return 0;
} 
