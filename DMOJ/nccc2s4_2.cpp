//
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

bitset<50001> goodvertex;
vector<vector<pi>> connections;
bitset<50001> visited;
void setBad(int v) {
  goodvertex[v] = 0;
  for (auto it : connections[v]) {
    if(!visited[it.F]) {
      visited[it.F] = 1;
      setBad(it.F);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  int a, b, c;
  cin >> n;
  connections.resize(n+1);
  for (int i = 1; i < n; i++) {
    cin >> a >> b >> c;
    connections[a].push_back(make_pair(b, c));
    connections[b].push_back(make_pair(a, c));
  }
  goodvertex.flip(); //set all to 1
  for (int root = 1; root <= n; root++) {
    vector<int> colours;
    colours.resize(n);
    for (auto it : connections[root]) {
      if (colours[it.S]) {//found duplicate
        visited.reset();
        visited[root] = 1;
        setBad(colours[it.S]);
        setBad(it.F);
      } else {
        colours[it.S] = it.F;
      }
    }
  }
  vector<int> output;
  for (int i = 1; i <= n; i++) {
    if (goodvertex[i]) {
      output.push_back(i);
    }
  }
  cout << output.size() << "\n";
  for (auto it : output) {
    cout << it << "\n";
  }
  return 0;
}
