/*
ID: dpb2461
TASK: friday
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() {
	int count[7];//Sat, Sun, Mon.... Fri
	memset(count, 0, sizeof(count));
	int current_day = 0;//Start on sat 13th jan 1900
	int length[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	count[0]++; //Cause sat is a 13th
	FILE* fin, *fout;
	fin = fopen("friday.in", "r");
	fout = fopen("friday.out", "w");
	int n;
	fscanf(fin, "%d", &n);
	for (int i = 1900; i < 1900+n; i++) {
		for (int m = 0; m < 12; m++) {
			if (((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) && m==1) {//Leap year
				current_day = (length[m]+ 1 + current_day) % 7;
			}
			else {
				current_day = (length[m] + current_day) % 7;
			}
			count[current_day]++;
		}
	}
	count[current_day]--; //Remove extra day because start/end in jan (going an extra year)
	for (int i = 0; i < 7; i++) {
		fprintf(fout, "%d", count[i]);
		if (i < 6) fprintf(fout, " ");
	}
	fprintf(fout, "\n");
	fclose(fin);
	fclose(fout);
	return 0;
}