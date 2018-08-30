/*
ID: dpb2461
TASK: barn1
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h> 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <vector> 
#include <fstream>

#define fori(n) for(int i = 0; i < n; i++)
#define MAXSTALLS 201
using namespace std;

int main() {
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int i, m, s, c, pos, filled[MAXSTALLS];
	memset(filled, 0, sizeof(int) * MAXSTALLS);
	fin >> m >> s >> c;
	s = MAXSTALLS;
	for (i = 0; i < c; i++) {
		fin >> pos;
		filled[pos] = 1;
	}
	//frontfill
	int* start = filled;
	while (*start == 0) {start++; }
	fill_n(filled, start-filled, 2);
	s -= start - filled;
	//backfill
	start = filled + MAXSTALLS - 1;
	while (*start == 0) { start--; }
	start++;
	fill_n(start, MAXSTALLS - (start - filled), 2);
	s -= MAXSTALLS - (start - filled);
	for (i = 1; i < m; i++) {
		int count = 0, maxcount = 0, index = 1;
		for (int j = 0; j < MAXSTALLS; j++) {
			if (filled[j]) {
				if (count > maxcount) {
					maxcount = count;
					index = j; //set to last pos
				}
				count = 0;
			}
			else {
				count += 1;
			}
		}
		fill_n(filled + (index - maxcount), maxcount, 2);
		s -= maxcount;
	}
	cout << "answer " << s << endl;
	fout << s << endl;
	return 0;
}