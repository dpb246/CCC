#include <iostream>
#include <string>
#include <deque>
using namespace std;
string solve (deque<int> cars, int n) {
  int next = 1;
  deque<int> branch;
  branch.push_front(0);
  while(!cars.empty() || next == branch.front()) {
    //cout << next << " " << cars.front() << " " << branch.front() << endl;
    if (next == cars.front()) {
      cars.pop_front();
      next++;
    } else if (next == branch.front()) {
      branch.pop_front();
      next++;
    } else {
      branch.push_front(cars.front());
      cars.pop_front();
    }
  }
  return next >= n-1 ? "Y\n" : "N\n";
}
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int t, n, i, loop;
  cin >> t;
  for (loop = 0; loop < t; loop++) {
    cin >> n;
    int t;
    deque<int> cars;
    for (i = 0; i < n; i++) {
      cin >> t;
      cars.push_front(t);
    }
    cout << solve(cars, n);
  }

}
