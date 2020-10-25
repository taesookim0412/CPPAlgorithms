#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
using namespace std;

//8 neighbors
//a, b, c
//d, _, e,
//f, g, h

//Two different ways to bounds check and iterate are provided.
int getPeaksFromMatrix( int** a , int nrows, int ncols)
{
	int totalPeaks = 0;
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			int target = a[i][j];
			bool peak = true;
			string neighbors = "";
			//a
			if (i > 0 && j > 0)
			{
				neighbors += to_string(a[i - 1][j - 1]) + " ";
				if (a[i - 1][j - 1] >= target) {
					peak = false;
				}
			}
			//b
			if (i > 0) {
				neighbors += to_string(a[i - 1][j]) + " ";
				if (a[i - 1][j] >= a[i][j]) {
					peak = false;
				}
			}
			//c
			if (i > 0 && j < ncols - 1)
			{
				neighbors += to_string(a[i - 1][j + 1]) + " ";
				if (a[i - 1][j + 1] >= target) {
					peak = false;
				}
			}
			//d
			if (j > 0) {
				neighbors += to_string(a[i][j - 1]) + " ";
				if (a[i][j - 1] >= a[i][j]) {
					peak = false;
				}
			}
			//e
			if (j < ncols - 1) {
				neighbors += to_string(a[i][j + 1]) + " ";
				if (a[i][j + 1] >= a[i][j]) {
					peak = false;
				}
			}

			//f
			if (i < nrows - 1 && j > 0) {
				neighbors += to_string(a[i+1][j - 1]) + " ";
				if (a[i+1][j-1] >= a[i][j]) {
					peak = false;
				}
			}
			//g
			if (i < nrows - 1) {
				neighbors += to_string(a[i+1][j]) + " ";
				if (a[i + 1][j] >= a[i][j]) {
					peak = false;
				}
			}
			//g
			if (i < nrows - 1 && j < ncols - 1) {
				neighbors += to_string(a[i+1][j + 1]) + " ";
				if (a[i + 1][j + 1] >= a[i][j]) {
					peak = false;
				}
			}
			if (peak)
			{
				//Cout debug
				cout << "Peak found at row=" << i << ", col=" << j << " number " << a[i][j] << endl;
				cout << "Neighbors: " << neighbors << endl;
				int lower_i = i - 1;
				if (lower_i < 0) lower_i = i;
				int upper_i = i + 1;
				if (upper_i > nrows - 1) upper_i = i;
				int lower_j = j - 1;
				if (lower_j < 0) lower_j = j;
				int upper_j = j + 1;
				if (upper_j > ncols - 1) upper_j = j;
				for (int i = lower_i; i <= upper_i; i++) {
					for (int j = lower_j; j <= upper_j; j++) {
						cout << a[i][j] << " ";
					}
					cout << endl;
				}
				totalPeaks += 1;
			}
		}
	}
	return totalPeaks;
}