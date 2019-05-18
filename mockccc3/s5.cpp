#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#define maxn 100002
#define inf 10000000000000
#define pb push_back
using namespace std;
int n, q, a, b;
vector<int> con[maxn];
bitset<maxn> visited;
bool dfs(int goal, int cur, int last) {
  if (goal == cur) {
    return 1;
  }
  bool on = false;
  for (int c : con[cur]) {
      if (c != last && !visited[c]) {
        on |= dfs(goal, c, cur);
      }
  }
  visited[cur] = on;
  return on;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    con[a].pb(b);
    con[b].pb(a);
  }
  for (int querry = 0; querry < q; querry++) {
    visited.reset();
    int v, k, cur, next;
    cin >> v >> k >> cur >> next;
    visited[cur] = 1;
    bool possible = dfs(next, cur, -1);
    for (int i = 0; i < k-2; i++) {
      cur = next;
      cin >> next;
      possible &= dfs(next, cur, -1);
      visited[next] = 1;
    }
    cout << possible << endl;
  }
}
