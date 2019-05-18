// 7/15 TLE
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <queue>
#include <utility>
#include <bitset>
#define F first
#define S second
#define pi pair<int, int>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  int a, b, c;
  cin >> n;
  vector<vector<pi>> connections;
  connections.resize(n+1);
  for (int i = 1; i < n; i++) {
    cin >> a >> b >> c;
    connections[a].push_back(make_pair(b, c));
    connections[b].push_back(make_pair(a, c));
  }
  set<int> goodvertex;
  for (int v = 1; v <= n; v++) {
    queue<pi> q;
    q.push(make_pair(v, 0));//BFS Starting at i
    bool good = true;
    bitset<50001> visited;
    visited[v] = 1;
    while(!q.empty() && good) {
      pi cur = q.front();
      q.pop();
      for(auto it : connections[cur.F]) {
        if (visited[it.F]) continue;
        if (it.S != cur.S) {
          if (goodvertex.find(it.F) != goodvertex.end()){
            for(auto it2 : connections[it.F]) {
              if (it2.S == it.S && it2.F != cur.F) good = false;
            }
          } //already good just check the edges around it
          else {
            q.push(make_pair(it.F, it.S));
          }
          visited[it.F] = 1;
        } else {
          good = false;
        }
      }
    }
    if (good) {
      goodvertex.insert(v);
    }
  }
  cout << goodvertex.size() << "\n";
  for (auto it : goodvertex) {
    cout << it << "\n";
  }
  return 0;
}
