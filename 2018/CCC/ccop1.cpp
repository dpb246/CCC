#include <iostream>

using namespace std;
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, i;
  int a[1001], b[1001];
  char aw[1001], bw[1001];
  cin >> n;
  for(i = 0; i < n; i++) {
    cin >> aw[i];
  }
  for(i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(i = 0; i < n; i++) {
    cin >> bw[i];
  }
  for(i = 0; i < n; i++) {
    cin >> b[i];
  }
  long long m = 0;
  for(i = 0; i < n; i++) {
    if(aw[i] == bw[i]) continue; //can't be same
    if(aw[i] == 'W' && a[i] > b[i]) {
      m += a[i] + b[i];
    } else if (bw[i] == 'W' && b[i] > a[i]) {
      m += a[i] + b[i];
    }
  }A
  cout << m << endl;
}
