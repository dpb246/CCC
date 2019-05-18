#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define maxq 102
using namespace std;

int times[maxq];
int maxTime(int s, int i) {
  int m = 0;
  for (int j = i-s+1; j <= i; j++) {
    m = max(m, times[j]);
  }
  return m;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int m, q;
  cin >> m >> q;
  string names[maxq];
  for(int i = 1; i <= q; i++) {
    cin >> names[i] >> times[i];
  }
  int besttime[maxq];
  int bestlength[maxq];
  besttime[0] = 0;
  bestlength[0] = 0;
  for (int i = 1; i <= q; i++) {
    int b = 100000000;
    for (int s = 1; s <= m; s++) {
      if (i-s+1 > 0) {
        int temp = besttime[i-s] + maxTime(s, i);
        if (temp < b) {
          b = temp;
          bestlength[i] = s;
        }
      }
    }
    besttime[i] = b;
  }
  //print loop
  cout << "Total Time: " << besttime[q] << "\n";
  int spot = q;
  int num = bestlength[q];
  vector<vector<string>> output;
  while (true) {
    vector<string> l;
    for (int s = spot; s > spot-num; s--) {
      l.push_back(names[s]);
    }
    spot -= num;
    num = bestlength[spot];
    output.push_back(l);
    if (spot <= 0) break;

  }
  for(auto it = output.rbegin(); it != output.rend(); it++) {
    for (auto l = (*it).rbegin(); l != (*it).rend(); l++) {
      cout << *l << " ";
    }
    cout << "\n";
  }
  return 0;
}
