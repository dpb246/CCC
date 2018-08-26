/*
ID: dpb2461
TASK: milk2
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h> 
#include <string.h>
#include <iostream>
#define fori(n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
	FILE* fin, *fout;
	fin = fopen("milk2.in", "r");
	fout = fopen("milk2.out", "w");
	int n;
	fscanf(fin, "%d", &n);
	int* times = (int*)malloc(sizeof(int) * 1000001);
	memset(times, 0, sizeof(int)* 1000001);
	long s, e;
	long start = 1000001;
	long end = 0;
	assert(times[10] == 0);
	fori(n) {
		fscanf(fin, "%d %d", &s, &e);
		memset(times+s, 1, sizeof(int)*(e-s));
		if (s < start) start = s;
		if (e > end) end = e;
	}
	int count[2] = { 0 , 0 };
	int last = times[start];
	int run = 0;
	assert(start >= 0);
	assert(start < 1000000);
	assert(end >= 0);
	assert(end < 1000000);
	for (long i = start; i < end; i++) {
		if (times[i] == last) {
			run++;
		}
		else {
			if (run > count[(last != 0)]) {
				count[(last != 0)] = run;
			}
			run = 1;
			last = times[i];
		}
	}
	if (run > count[(last != 0)]) {
		count[(last != 0)] = run;
	}
	fprintf(fout, "%d %d\n", count[1], count[0]);
	delete times;
	fclose(fin);
	fclose(fout);
	return 0;
}