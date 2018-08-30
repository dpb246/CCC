/*
ID: dpb2461
TASK: palsquare
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
bool pally(string str) {
	const char* s = str.c_str();
	for (int i = 0; i < str.size() / 2; i++) {
		if (s[i] != s[str.size() - i - 1]) return false;
	}
	return true;
}
int main() {
	FILE* fin, *fout;
	fin = fopen("palsquare.in", "r");
	fout = fopen("palsquare.out", "w");
	assert(fin != NULL && fout != NULL);
	int base;
	fscanf(fin, "%d", &base);
	for (int i = 1; i < 300; i++) {
		string number = convert( i*i , base );
		if (pally(number)) {
			fprintf(fout, "%s %s\n", convert(i, base).c_str(), number.c_str());
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}