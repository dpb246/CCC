#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long

using namespace std;

int n;
int v[200002], w[200002];
ll solve(int person, int hat) {
  if (person == n-1) return abs(hat-w[person]);
  return min(abs(hat-w[person])+solve(person+1, v[person+1]) , abs(v[person+1]-w[person])+solve(person+1, hat));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> v[i] >> w[i];
  }
  cout << solve(0, v[0]) << endl;
  return 0;
}
