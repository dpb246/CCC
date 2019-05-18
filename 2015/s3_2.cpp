//This one works for DMOJ
//Better solution
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int g, p, i, gi, count = 0;
  set<int> gates;
  for (i = 0; i < 100001; i++) { //need zero to make gate 1 not the beginning
    gates.insert(i);
  }
  cin >> g >> p;
  for (i = 0; i < p; i++) {
    cin >> gi;
    auto it = gates.upper_bound(gi); //upper_bound points to next element
    it--;
    if (it != gates.begin()) {
      gates.erase(it);
      count++;
    } else {
      break;
    }
  }
  cout << count << endl;
}
