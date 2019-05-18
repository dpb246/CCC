#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string fs = "";
char love[4] = {'l', 'o', 'v', 'e'};
long long w[10001][4];
long long  ways(int spot, int letter) {
  if (letter == 4) return 1;
  if (w[spot][letter] != -1) return w[spot][letter];
  long long  count = 0;
  for (int i = spot; i < fs.size(); i++) {
    if (fs[i] == love[letter]) {
      count += ways(i+1, letter+1);
    }
  }
  w[spot][letter] = count;
  return count;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  memset(w, -1, sizeof(w));
  for (int i = 0; i < s.size(); i++) {
    s[i] = tolower(s[i]);
    if (s[i] == 'l' || s[i] == 'o' || s[i] == 'v' || s[i] == 'e') {
      fs += s[i];
    }
  }
  cout << ways(0, 0) << endl;
  return 0;
}
