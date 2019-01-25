#include <iostream>
#include <string>
using namespace std;
int pow(int m) {
  if (m <= 0) return 1;
  return 5*pow(m-1);
}
string solve(int m, int x, int y) {
  if(m == 0) return "empty";
  int p = pow(m-1);
  int conx = x / p;
  int cony = y / p;
  if (cony == 0) {
    if (conx == 1 || conx == 2 || conx == 3) {
      return "crystal";
    }
  } else if (cony == 1) {
    if (conx == 2) return "crystal";
    if (conx == 1 || conx == 3) return solve(m-1, x%p, y%p);
  } else if (cony == 2 && conx == 2){
    return solve(m-1, x%p, y%p);
  }
  return "empty";
}
int main() {
  int t, m, x, y;
  cin >> t;
  for (; t > 0; t--) {
    cin >> m >> x >> y;
    cout << solve(m, x, y) << "\n";
  }
  return 0;
}
