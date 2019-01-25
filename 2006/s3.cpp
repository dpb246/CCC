#include <iostream>
#include <cmath>
#define maxb 101
#define maxp 33
using namespace std;

int gcd(int a, int b) {
  a = abs(a);
  b = abs(b);
  return b == 0 ? a : gcd(b, a%b);
}

struct building {
  int s;
  int x[maxp];
  int y[maxp];
  int mx = -1000, my = -1000, sx = 1000, sy = 1000; //bounding box
};



int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int xr, yr, xj, yj, n, i, s;
  cin >> xr >> yr >> xj >> yj;
  cin >> n;
  building b[maxb];
  for (i = 0; i < n; i++) {
    cin >> s;
    b[i].s = s;
    for (; s > 0; s--) {
      cin >> b[i].x[s] >> b[i].y[s];
      b[i].mx = max(b[i].mx, b[i].x[s]);
      b[i].my = max(b[i].my, b[i].y[s]);
      b[i].sx = min(b[i].sx, b[i].x[s]);
      b[i].sy = min(b[i].sy, b[i].y[s]);
    }
  }
  cout << b[0].mx << " " << b[0].my << " " << b[0].sx << " " << b[0].sy << endl;
}
