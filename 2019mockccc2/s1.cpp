#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  long long x, y;
  scanf("%lld %lld", &x, &y);
  printf("%.1f", max(x, y)/2 * min(x, y));
}
