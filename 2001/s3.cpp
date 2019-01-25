#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;
struct path {
  int cur;
  bool visited[26];
  path(int c) {
    memset(visited, 0, sizeof(visited));
    cur = c;
    visited[c] = 1;
  }
};
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  char road[2];
  vector<int> roads[26];
  while (cin >> road && road[0] != '*') {
    roads[road[0]-'A'].push_back(road[1] - 'A');
    roads[road[1]-'A'].push_back(road[0] - 'A');
  }
  int visited[26];
  memset(visited, 0, sizeof(visited));
  int candestroy = 0;
  queue<path> d;
  vector<path> complete;
  d.push(path(0));
  while(!d.empty()) {
    auto i = d.front();
    d.pop();
    for(auto r : roads[i.cur]) {
      if (r == 1) {
        path t = path(r);
        memcpy(&t.visited, &i.visited, sizeof(i.visited));
        t.visited[t.cur] = 1;
        complete.push_back(t);
      }
      else if(i.visited[r] == 0) {
        path t = path(r);
        memcpy(&t.visited, &i.visited, sizeof(i.visited));
        t.visited[t.cur] = 1;
        d.push(t);
      }
    }
  }
  for(auto t : complete) {
    for (int i = 0; i < 'J'-'A'; i++) {
      if (t.visited[i])
        cout << (char) (i+'A') << " ";
      else cout << "  ";
    }
    cout << endl;
  }
}
