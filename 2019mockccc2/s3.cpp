#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define pb push_back
#define ll long long
using namespace std;
int factorial(int a) {
  int an = 1;
  for (; a > 0; a--) {
    an *= a;
  }
  return an;
}
int choose(int a) {
  if (a < 3) return 0;
  return factorial(a) / (6*factorial(a-3));
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, i, j, k;
  cin >> n;
  ll x[3001], y[3001], xi, yi;
  vector<double> slopes;
  for (i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    for(j = 0; j < i; j++) {
      slopes.pb((double) abs(x[i]-x[j]) / (double) abs(y[i]-y[j]));
    }
  }
  sort(slopes.begin(), slopes.end());
  ll count = choose(n);
  ll c = 0;
  double lastt = slopes[0];
  for (i = 1; i < n; i++) {
    if (slopes[i] == lastt) c++;
    else {
      count -= choose(c);
      c = 0;
    }
    lastt = slopes[i];
  }
  cout << count << endl;
}
