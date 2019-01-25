#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  int n, li, i, j;
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int boards[4001];
  int bucket[2001];
  memset(boards, 0, sizeof(boards));
  memset(bucket, 0, sizeof(bucket));
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> li;
    bucket[li]++;
  }
  for (i = 0; i < 2001; i++) {
    if (!bucket[i]) continue;
    for (j = i; j < 2001; j++) {
      if (i==j) boards[i+j] += bucket[i]/2;
      else if (bucket[j]) boards[i+j] += min(bucket[i], bucket[j]);
    }
  }
  int dif = 0, length = 0;
  for (i = 0; i < 4001; i++) {
    if (boards[i] > length) {
      length = boards[i];
      dif = 1;
    } else if(boards[i] == length) {
      dif++;
    }
  }
  cout << length << " " << dif << "\n";
  return 0;
}
