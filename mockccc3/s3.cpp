#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define maxn 100003
#define maxm 9
#define inf 10000000000000
#define ll long long
using namespace std;
int pi[maxn];
double gi[maxm];
ll range_sum[maxn];
int n, m;
ll best_overall = inf;
vector<ll>> pos;
ll solve(int start, int person, vector<ll> sums) {
  if (start > n) return 0; //bad case
  if (person == m-1) { //end
    sums[person] = range_sum[n]-range_sum[start-1];
    sort(sums.begin(), sums.end());
  }
  sums[person] = 0; //to allow empty range
  solve(start, person+1, sums);
  for (int i = start; i <= n; i++) {
    sums[person] = range_sum[i]-range_sum[start-1];
    solve(i+1, person+1, sums);
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  range_sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> pi[i];
    range_sum[i] = range_sum[i-1]+pi[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> gi[i];
  }
  sort(gi, gi+m);
  vector<ll> sums;
  sums.resize(m);
  solve(1, 0, sums);
  ll score = 0;
  for (int i = 0; i < m; i++) {
    score = max(score, (ll) ceil( (double) sums[i] / gi[i]));
  }
  best_overall = min(score, best_overall);
  return 0;
  cout << best_overall << endl;
}
