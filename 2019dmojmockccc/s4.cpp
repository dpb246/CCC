#include <iostream>

using namespace std;
#define max 10000001

int f[max];
int a, b, c, d, q;
inline int ab(int i, int x, int y) {
  int t = i/x - y;
  return t > 0 ? t : 0;
}
int fun(int x) {
  if (x < max) return f[x];
  return fun(ab(x, a, b)) +  fun(ab(x, c, d));
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cout.sync_with_stdio(0); cout.tie(0);
  int x;
  cin >> a >> b >> c >> d >> q;
  int i;
  f[0] = 1;
  for (i = 1; i < max; i++) {
    f[i] = f[ab(i, a, b)] +  f[ab(i, c, d)];
  }
  for (i = 0; i < q; i++) {
    cin >> x;
    cout << fun(x) << "\n";
  }
  return 0;
}
