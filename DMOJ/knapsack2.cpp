#include <iostream>
#include <cstring>
#include <stdlib.h>
#define maxw 100002

using namespace std;
typedef long long ll;
ll* dp = (ll *) malloc(1000000001*sizeof(ll));
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, w, vi, wi, i;

  cin >> n >> w;
  for (i = 0; i < n; i++) {
    cin >> wi >> vi;
    for (int j = w; j >= wi; j--) {
      dp[j] = max(dp[j], dp[j-wi]+vi);
    }
  }
  cout << dp[w] << "\n";
  free(dp);
  return 0;
}
