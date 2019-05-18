#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#define maxn 252

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int gN, gK, i, j, n, k;
    cin >> gN >> gK;

    int ways[maxn][maxn]; //k, n
    memset(ways, 0, sizeof(ways));
    for (i = 0; i < maxn; i++) {
      ways[1][i] = 1; //1 way to do it
    }

    for (k = 2; k < gK+1; k++) {
      for (n = 1; n < gN+1; n++) {
        if (n < k) ways[k][n] = 0;
        else if (n == k) ways[k][n] = 1;
        else {
          for(i = n-k+1; i >= n-i-k+2; i--) {
            ways[k][n] += ways[k-1][n-i];
          }
        }
        cout << ways[k][n] << " ";
      }
      cout << endl;
    }
    cout << ways[gK][gN] << endl;
}
