#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <utility>
#define F first
#define S second
#define maxnm 303
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pii pair<int, int>
using namespace std;
int mi[maxnm], pi[maxnm];
pii sortedpi[maxnm];
int solve(int i, int j, int usepi) {
  if (i == j) return usepi*mi[i]+pi[i]; //Same flower doesn't affect twice
  return max((usepi*mi[i] + pi[i]) * mi[j] + pi[j], (usepi*mi[j] + pi[j]) * mi[i] + pi[i]);
}
bool comp(pii a, pii b) {
  return a.F > b.F ? true : false;
}
/**
Idea, for any pair of flowers i, j always take the biggest possible pi
*/
int main() {
  int n, m, a, b;
  bool pair[maxnm][maxnm];
  memset(pair, 1, sizeof(pair)); //default allowed to pair
  scan(n);
  scan(m);
  for (int i = 0; i < n; i++) {
    scan(mi[i]);
    scan(pi[i]);
    sortedpi[i] = make_pair(pi[i], i);
  }
  sort(sortedpi, sortedpi+n, comp);
  for (int i = 0; i < m; i++) {
    scan(a);
    scan(b);
    pair[--a][--b] = 0; //0 indexing
    pair[b][a] = 0;
  }
  int best = 0;
  int k = 0;
  for (int i = 0; i < n; i++) { //flower 1
    for (int j = i; j < n; j++) { //flower 2
      if(!pair[i][j]) continue; //can't pair i j
      k = 0;
      while(k < n && (!pair[i][sortedpi[k].S] || !pair[j][sortedpi[k].S] || sortedpi[k].S == i || sortedpi[k].S == j)) {//find first where can pair, and not the same as i or j (deal with case i==j==k later)
        k++;
      }
      if (k < n) { //no valid
          best = max(best, solve(i, j, sortedpi[k].F));
      }
    }
  }
  if (best == 0) { //didn't find a pair of valid, so pretend we combine three of the same flowers
    best = sortedpi[0].F;
  }
  printf("%d", best);
  return 0;
}
