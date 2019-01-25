#include <iostream>
#include <cstring>
#define maxn 101
#define maxw 1000000001
#define ll long long

using namespace std;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, w, vi, wi, i;
  int weights[maxn];
  int value[maxn];

  ll dpcur[maxw];
  ll dplast[maxw];
  memset(dplast, 0, sizeof(dplast));
  cin >> n >> w;
  for (i = 0; i < n; i++) {
    cin >> wi >> vi;
    weights[i] = wi;
    value[i] = vi;
  }
  for (i = 0; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      if (i == 0 || j == 0) dpcur[j] = 0l;
      if (weights[i-1] <= j) {
        dpcur[j] = max(dplast[j], dplast[j-weights[i-1]]+value[i-1]);
      }
      else {
        dpcur[j] = dplast[j];
      }
    }
    memcpy(dplast, dpcur, sizeof(dpcur));
  }
  cout << dpcur[w];
  return 0;
}
