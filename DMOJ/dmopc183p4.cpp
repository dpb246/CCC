#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
using namespace std;
int n;
string a, b;
set<string> visited;
bool solve(string cur) {
  if (cur == b) return 1;
  bool ans = false;
  for (int i = 0; i <= n-2; i++) {
    if (cur[i] == cur[i+1]) {
      if (cur[i] == 'F') {
        cur[i] = 'A';
        cur[i+1] = 'A';
        if (visited.find(cur) == visited.end()) {
          visited.insert(cur);
          ans |= solve(cur);
        }
        cur[i] = 'F';
        cur[i+1] = 'F';
      } else if (cur[i] == 'A') {
        cur[i] = 'F';
        cur[i+1] = 'F';
        if (visited.find(cur) == visited.end()) {
          visited.insert(cur);
          ans |= solve(cur);
        }
        cur[i] = 'A';
        cur[i+1] = 'A';
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> a >> b;
  visited.insert(a);
  if (solve(a)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
