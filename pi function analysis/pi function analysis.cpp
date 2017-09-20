// pi function analysis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream ifs("primes1.txt");
	ofstream ofs("outputanalysis.txt");
	static int prastevila[128];
	static int zaporedja[732][8];
	for (int i = 1; i < 128; i++) {
		ifs >> prastevila[i];
		cout << i<<'\n';
		ofs << prastevila[i];
	}
	int number;
	for (int i = 2; i < 710; i++) {
		number = i;
		cout << i<<'\n';
		int a = 0;
		do {
			for (int j = 1; j < 128; j++) {
				if (number == prastevila[j]) {
					number = j;
					j = 128;
					zaporedja[i][a] = 0;
					ofs << i << ' ' << a << '\n';
				}
				else if (number < prastevila[j]) {
					number = j - 1;
					j = 128;
					zaporedja[i][a] = 1;
				}
			}
			a++;
		} while (number >= 1);
	}

	for (int i = 2; i < 710; i++) {
		ofs << i << ' ';
		for (int j = 0; j < 8; j++) {
			ofs << zaporedja[i][j];
		}
		ofs << '\n';
	}

	for (int i = 1; i < 709; i++) {
		zaporedja[i][7] = zaporedja[i][6] + 2 * zaporedja[i][5] + 4 * zaporedja[i][4] + 8 * zaporedja[i][3] + 16 * zaporedja[i][2] + 32 * zaporedja[i][1] + 64 * zaporedja[i][0];
	}
	int counter;
	for (int i = 1; i < 709; i++) {
		if (zaporedja[i][7] != 1000) {
			counter = 1;
			for (int j = i +1; j < 709; j++) {
				if (zaporedja[i][7] == zaporedja[j][7]) {
					counter++;
					zaporedja[j][7] = 1000;
				}
			}
			ofs << i << ' ';
			for (int j = 0; j < 7; j++) {
				ofs << zaporedja[i][j];
			}

			ofs<<'0'<<' '<<counter << '\n';
		}
	}

    return 0;
}

