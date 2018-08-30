/*
ID: dpb2461
TASK: crypt1
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h> 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <string>
#include <vector> 
#include <fstream>

#define fori(n) for(int i = 0; i < n; i++)
#define MAXSTALLS 201
using namespace std;

int three_digit(int number) {
	if (number < 100) return false;
	if (number > 999) return false;
	return true;
}
int four_digit(int number) {
	if (number < 1000) return false;
	if (number > 9999) return false;
	return true;
}
int from_set(int number, int* set) {
	string num = to_string(number);
	for (char c : num) {
		if (!set[(int)c - '0']) return false;
	}
	return true;
}
int main() {
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");
	assert(fin.is_open());
	assert(fout.is_open());
	int n, d, digits[10], list[10], count = 0;
	fill(digits, digits + 10, 0);
	fill(list, list + 10, 0);
	fin >> n;
	assert(n < 10);
	fori(n) {
		fin >> d;
		digits[d] = 1;
		list[i] = d;
	}
	for (int ai = 0; ai < 10; ai++) {
		int a = list[ai];
		if (!a) continue;
		for (int bi = 0; bi < 10; bi++) {
			int b = list[bi];
			if (!b) continue;
			for (int ci = 0; ci < 10; ci++) {
				int c = list[ci];
				if (!c) continue;
				for (int di = 0; di < 10; di++) {
					int d = list[di];
					if (!d) continue;
					for (int ei = 0; ei < 10; ei++) {
						int e = list[ei];
						if (!e) continue;
						int pp1 = (100 * a + 10 * b + c)*e;
						int pp2 = (100 * a + 10 * b + c)*d;
						int sum = pp1 + 10 * pp2;
						if (!(three_digit(pp1) && from_set(pp1, digits))) continue;
						if (!(three_digit(pp2) && from_set(pp2, digits))) continue;
						if (!(four_digit(sum) && from_set(sum, digits))) continue;
						//cout << a << b << c << " * " << d << e << endl;
						count++;
					}
				}
			}
		}
	}
	//cout << count;
	fout << count << endl;
	return 0;
}