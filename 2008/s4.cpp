#include <iostream>
#include <algorithm>

using namespace std;

int hand[4], n, largest;

void solve(int cur, int next, int op) {
  if(op == 4) {//2 operations have occured just need the final
    if (cur+next <= 24) largest = max(largest, cur+next);
    if (cur-next <= 24) largest = max(largest, cur-next);
    if (cur*next <= 24) largest = max(largest, cur*next);
    if (next != 0 && cur%next == 0 && cur/next <= 24) largest = max(largest, cur/next);
    return;
  }
  solve(cur+next, hand[op], op+1);
  solve(cur-next, hand[op], op+1);
  solve(cur*next, hand[op], op+1);
  if (next != 0 && cur%next == 0) solve(cur/next, hand[op], op+1);
  solve(cur, next+hand[op], op+1);
  solve(cur, next-hand[op], op+1);
  solve(cur, next*hand[op], op+1);
  if (hand[op] != 0 && next%hand[op] == 0) solve(cur, next/hand[op], op+1);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for(int round = 0; round < n; round++) {
    largest = -1;
    for(int i = 0; i < 4; i++) {
      cin >> hand[i];
    }
    sort(hand, hand+4);//sorted to start
    do {
      solve(hand[0], hand[1], 2);
    } while(next_permutation(hand, hand+4)); //try all permutations of the list order
    cout << largest << "\n";
  }
}
