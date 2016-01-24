/*
 * Mastermind.cpp
 *
 *  Created on: Nov 12, 2012
 *      Author: shuheng
 */

#include <fstream>
#include <iostream>

using namespace std;

int main() {
	fstream in("input00.txt", ios_base::in);
	int C, n, k, q;  //C is the number of trials, n is the size of the alphabet, k , q is the number of guesses
	in >> C;

	for (int c=1; c<= C; c++) {
		in >> n >> k >> q;
		int guesses[q][k+1];
		for (int line = 0; line < q; line++) {
			for (int j=0; j < k+1; j++) {
				in >> guesses[line][j];
				cout << guesses[line][j];
			}
			cout << endl;
		}
		cout << endl;

	}

	in.close();

	return 0;
}
