

#define ll long long
#define error 0.00001
using namespace std;
int n, m;
double image[1002][1002];

double calcaverage(double c) {
  long double sum = 0.0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum += min(1.0, image[i][j]*c);
    }
  }
  return sum / (double) (n*m);
}
a
int main() {

  cin >> n >> m;
  long double sum = 0.0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> image[i][j];
      sum += image[i][j];
    }
  }
  double average = sum / (double) (n*m);
  if (abs(average-0.48) < error || abs(1.0-0.48/average) < error) {
    cout << "correctly exposed\n";
    return 0;
  } else if (average < 0.48) {
    cout << "underexposed\n";
    double low = 0.48/average;
    double hi = low*10;
    double mid = (low+hi)/2.0;
    double cur = calcaverage(mid);
    while (abs(cur-0.48) >= 0.0000001) {
      if (cur < 0.48) {
        low = mid;
      } else {
        hi = mid;
      }
      mid = (low+hi)/2.0;
      cur = calcaverage(mid);
    }
    cout << mid << endl;
    return 0;
  }
  else if (average > 0.48) {
    cout << "overexposed\n";
    cout << 0.48/average << endl;
    return 0;
  }
}
