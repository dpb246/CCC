/*
ID: dpb2461
TASK: dualpal
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h> 
#include <iostream>
#include <math.h>
#include <string>
#define fori(n) for(int i = 0; i < n; i++)
using namespace std;

string convert(int number, int base) {
	const char* reference = "0123456789ABCDEFGHIJK";
	string output;
	bool started = false;
	for (int i = 19; i >= 0; i--) {
		int n = ((int)pow((double)base, (double)i));
		if ((int)number / n == 0 && !started) continue;
		output += reference[(int)number / n];
		number = number % n;
		started = true;
	}
	return output;
}
int pally(string str) {
	const char* s = str.c_str();
	for (int i = 0; i < str.size() / 2; i++) {
		if (s[i] != s[str.size() - i - 1]) return 0;
	}
	return 1;
}
int main() {
	FILE* fin, *fout;
	fin = fopen("dualpal.in", "r");
	fout = fopen("dualpal.out", "w");
	assert(fin != NULL && fout != NULL);
	int n, s;
	fscanf(fin, "%d %d", &n, &s);
	s++;
	int i = 0;
	while (i < n) {
		int count = 0;
		for(int j = 2; j < 11; j++) {
			//cout << s << " " << j << " " << convert(s, j) << " " << pally(convert(s, j)) << " " << count << endl;
			count += pally(convert(s, j));
		}
		if (count >= 2) {
			//cout << s << endl;
			fprintf(fout, "%d\n", s);
			i++;
		}
		s++;
	}
	fclose(fin);
	fclose(fout);
	return 0;
}