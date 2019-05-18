#pragma GCC optimize "O3"
#include <iostream>
#include <set>
#include <utility>
using namespace std;
int main() {
  int covers[1000001] = {};
  set<pair<int,int>> given;
  int n, c;
  cin >> n >> c;
  int c1, c2;
  for (int i = 0; i < c; i++) {
    cin >> c1 >> c2;
    if (c1 > c2) {
      int t = c1;
      c1 = c2;
      c2 = t;
    }
    if (given.find(make_pair(c1, c2)) == given.end()) {
      covers[c1]++;
      covers[c2]++;
      given.insert(make_pair(c1, c2));
    }
  }
  int max_i = 0;
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (covers[i] >= m) {
      m = covers[i];
      max_i = i;
    }
  }
  cout << max_i << "\n";
  return 0;
}
