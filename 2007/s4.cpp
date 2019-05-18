#include <vector>
#include <iostream>
#include <set>
#include <cstring>
#define maxn 10000
#define pb push_back
#define end "\n"

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, a, b;
  vector<int> con[maxn];
  cin >> n;
  while (cin >> a >> b, a != 0 && b != 0) {
    con[a].pb(b);
  }
  int dis[maxn];
  memset(dis, 0, sizeof(dis));
  dis[1] = 1;
  for (int i = 1; i <= n; i++) {
    for(auto it : con[i]) {
      dis[it] += dis[i];
    }
  }
  cout << dis[n] << end;
}
