/*
ID: dpb2461
TASK: combo
LANG: C++11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h> 
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstring>
#include <string>
#include <vector> 
#include <fstream>

#define fori(n) for(int i = 0; i < n; i++)
#define MAXN 100
using namespace std;
int within(int num, int num2) {
	return abs(num - num2) <= 2;
}
int n;
int check(int a, int b, int c, int* combo) {
	if ( !(within(a, combo[0]) || within(a, combo[0] + n) || within(a + n, combo[0])) ) {
		//cout << "A";
		return false;
	}
	if ( !( within(b, combo[1]) || within(b, combo[1] + n) || within(b + n, combo[1]))) {
		//cout << "b";
		return false;
	}
	if ( !(within(c, combo[2]) || within(c, combo[2] + n) || within(c + n, combo[2]))) {
		//cout << "c";
		return false;
	}
	return true;
}
int main() {
	ifstream fin("combo.in");
	ofstream fout("combo.out");
	int temp, farmer[3], master[3], total = 0;
	//IO
	fin >> n;
	fori(3) {
		fin >> farmer[i];
		farmer[i]--; //lowest to 0 to allow mod to work nicely
	}
	fori(3) {
		fin >> master[i];
		master[i]--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (check(i, j, k, farmer) || check(i, j, k, master)) {
					//cout << i+1 << " " << j+1 << " " << k+1 << " " << check(i, j, k, farmer) << " " << check(i, j, k, master) << endl;
					total++;
				}
			}
		}
	}
	//cout << total << endl;
	fout << total << endl;
	return 0;
}