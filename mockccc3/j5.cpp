#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#define F first
#define S second
#define maxn 100005
#define pii pair<int, int>
using namespace std;

bool comp(pii a, pii b) {
  if (a.F > b.F) return false;
  else if (b.F > a.F) return true;
  else if (a.S > b.S) return false;
  else return true;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, a, b;
  pii people[maxn];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> people[i].F >> people[i].S;
  }
  sort(people, people+n, comp);
  int count = 0;
  for (int i = 0; i < n; i++) {
    int c = 0;
    int j = 0;
    while (j+i < n){
      if (people[i+j].F != people[i].F) break;
        if (people[i+j].S == people[i].S){
            c++;
        }
        j++;
    }
    count += (n-1-i) - (j-c);
  }
  cout << count << "\n";
}
