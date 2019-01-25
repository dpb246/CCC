#include <iostream>
#include <cstring>
using namespace std;

int main() {
  int g, p, gi, i;
  bool visited[100001];
  memset(visited, 0, sizeof(visited));
  cin.sync_with_stdio(0); cin.tie(0);
  cin >> g;
  cin >> p;
  bool found;
  for (i = 0; i < p; i++) {
    cin >> gi;
    if (gi > g) {
      cout << i << endl;
      return 0;
    }
    found = false;
    for (; gi > 0; gi--) {
      if (!visited[gi]) {
        visited[gi] = true;
        found = true;
        break;
      }
    }
    if (!found) {
      cout << i << endl;
      return 0;
    }
  }
  cout << p << endl;
  return 0;
}
