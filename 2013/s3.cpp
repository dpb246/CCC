#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;
bool tmax(vector<int> points, int t) {
  int m = points[t];
  for(int i = 1; i < 5; i++) {
    if (i == t) continue;
    if (m <= points[i]) return false;
  }
  return true;
}
vector<vector<int>> possiblegames;
vector<vector<int>> newgames;
bool sim(bool played[5][5]) {
  int a, b;
  for(a = 1; a < 4; a++) { //find next match
    for(b = a+1; b < 5; b++) {
      if(!played[a][b]) {
        played[a][b] = true;
        for(int i = 0; i < possiblegames.size(); i++) {
          newgames.pb(possiblegames[i]);
          newgames.back()[a]+=3; //a wins
          newgames.pb(possiblegames[i]);
          newgames.back()[b]+=3; //b wins
          newgames.pb(possiblegames[i]);
          newgames.back()[a]++; //tie
          newgames.back()[b]++; //tie
        }
        possiblegames = newgames;
        newgames.clear();
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int i, g, t, a, b, sa, sb, count = 0;
  vector<int> points(5); //1 start
  fill(points.begin(), points.end(), 0);
  bool played[5][5];
  memset(played, 0, sizeof(played));
  cin >> t >> g;
  for (i = 0; i < g; i++) {
    cin >> a >> b >> sa >> sb;
    if (sa > sb) {
      points[a] += 3;
    } else if (sb > sa) {
      points[b] += 3;
    } else {
      points[a]++;
      points[b]++;
    }
    played[a][b] = true;
  }
  possiblegames.pb(points);
  sim(played);
  for (int i = 0; i < possiblegames.size(); i++) {
    count += tmax(possiblegames[i], t);
  }
  cout << count << endl;
  return 0;
}
