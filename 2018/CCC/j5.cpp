//Full Marks 15/15
//Dijkstra’s Shortest Path

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back
#define maxn 10002
using namespace std;

int n; //global because

int mindistance(int dist[], bool visited[]) {
  int m = 0x7F7F7F7F, mindex;
  for (int v = 1; v < n+1; v++) {
    if (!visited[v] && dist[v] < m) {
      m = dist[v];
      mindex = v;
    }
  }
  return mindex;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int i, mi, mn;
    vector<int> con[maxn];

    cin >> n;
    for(i = 1; i < n+1; i++) {
      cin >> mn;
      if (mn == 0) con[i].pb(0);
      for (; mn > 0; mn--) {
        cin >> mi;
        con[i].pb(mi);
      }
    }
    int shortest = maxn;
    bool visited[maxn];
    memset(visited, 0, sizeof(visited));
    int dist[maxn];
    memset(dist, 0x7F, sizeof(dist));
    dist[1] = 0; //no distance to self
    for (int count = 0; count < n; count++) {
      int u = mindistance(dist, visited);
      //cout << u << " " << dist[u] << endl;
      visited[u] = true;

      for (auto it : con[u]) {
        //cout << "it " << it << endl;
        if (it == 0) { //end
          shortest = min(shortest, dist[u]+1);
        }
        if (!visited[it] && dist[u] != 0x7F7F7F7F && dist[u] + 1 < dist[it]) {
          dist[it] = dist[u] + 1;
        }
      }
    }
    //check if all visited
    bool all = true;
    for (i = 1; i < n+1; i++) {
      all &= visited[i];
    }
    if (all) {
      cout << "Y\n";
    } else {
      cout << "N\n";
    }
    cout << shortest << "\n";
}
