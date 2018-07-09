#include <cstdint>
#include <cmath>
#include <stdio.h>
#include <cstring>
/*
CCC 2018 Senior 4
Score: 15/15
*/
using namespace std;
long long int countMap[100000000];//Store computed results
long long int n;
//Based on logic provided by https://dmoj.ca/problem/ccc18s4
long long int count(long long int w) {
	if (w == 1) return 1; //Ensure 1 becomes 1
	if (w < (100000000)) {
		if (countMap[w] != 0) {
			return countMap[w];
		}
	}
	long long int value = 0;
	double root = sqrt(w);//Only calculate this once
	for (long long int i = 1; i <= root; i++) {
		value += count(i) * (w / i - w / (i + 1));
	}
	for (long long int i = 2; i < w; i++) {
		long long int temp = w / i;
		if (temp <= root) break;
		value += count(temp);
	}
	if (w <  (100000000)) {
		countMap[w] = value;
	}
	return value;
}

int main() {
	scanf("%lld", &n);
	memset(countMap, 0, (100000000) * sizeof(long long int));
	countMap[1] = 1;
	printf("%lld", count(n));
}
