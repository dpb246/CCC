// FULL AC
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <bitset>
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
using namespace std;

int n, m;
vector<pii> range_blue;
ll dp[31][31];
ll solve(int col, int numblue) {
  if (col >= n) return 1;
  if (dp[col][numblue] != -1) return dp[col][numblue];
  dp[col][numblue] = 0; //set for +=
  for (int blue = range_blue[col].F; blue <= min(range_blue[col].S, numblue); blue++) {
    dp[col][numblue] += solve(col+1, blue);
  }
  return dp[col][numblue];
}
int main() {
  char grid[31][31];
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    cin >> grid[i];
  }
  memset(dp, -1, sizeof(dp));
  //initialize range_blue
  range_blue.resize(n);
  for (int c = 0; c < n; c++) { //each colunm
    int s = 0;
    int e = m;
    for (int r = 0; r < m; r++) {
      if (grid[r][c] == 'B') s = r+1;
      else if (grid[r][c] == 'R') e = min(e, r);
    }
    if (s <= e) {
      range_blue[c] = make_pair(s, e);
    } else {
      range_blue[c] = make_pair(0, -1);
    }
  }
  for (auto it : range_blue) {cout << it.F << " " << it.S << endl;}
  cout << solve(0, m) << endl;

}
