#include <iostream>
#include <bitset>
#include <string>
#define ll long long
#define maxn 4001
using namespace std;

int main() {
  ll n, t;
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> t;
  string in;
  cin >> in;
  bitset<maxn> line(in);
  bitset<maxn> nextline;
  for (; t > 0; t--) {
    for (int i = 0; i < n; i++) {
      int f = (i - 1 + n) % n;
      int s = (i + 1) % n;
      nextline[i] = line[f] ^ line[s];
    }
    line = nextline;
  }
  for (int i = n-1; i > -1; i--) {
    cout << line[i];
  }
  cout << endl;
}
