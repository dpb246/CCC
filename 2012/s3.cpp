#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

#define vi vector<int>

using namespace std;
int count[2000001];
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, i, r;
  memset(count, 0, sizeof(count));
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> r;
    count[r]++;
  }
  int most = 0, second = 0;
  vi m, s;
  for (i = 0; i < 2000001; i++) {
    if (count[i] > most) {
      second = most;
      most = count[i];
      s = m;
      m.clear();
      m.push_back(i);
    } else if (count[i] == most) {
      m.push_back(i);
    } else if (count[i] > second) {
      s.clear();
      s.push_back(i);
      second = count[i];
    } else if (count[i] == second) {
      s.push_back(i);
    }
  }
  if (m.size() > 1) {
    int v = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
      for(auto it2 = m.begin(); it2 != m.end(); it2++) {
        v = max(v, abs(*it-*it2));
      }
    }
    cout << v << endl;
  } else {
    int v = 0;
    for(auto it = s.begin(); it != s.end(); it++) {
      v = max(v, abs(m.at(0)-*it));
    }
    cout << v << endl;
  }
  return 0;
}
