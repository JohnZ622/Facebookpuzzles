/*
 * Hoppity.cpp
 *
 *  Created on: Jun 1, 2011
 *      Author: shuheng
 */

#include<stdlib.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {

	FILE* pFile;
	char number[10];
	int n;
	bool divbythree;
	bool divbyfive;
//	pFile = fopen('')

	if (argc==1)
	{
		printf("Insufficient arguments\n");
		return 1;
	}
	pFile = fopen(argv[1], "r");
	if (pFile == NULL)
	{
		perror("Error opening file");
		return 1;
	}
	fgets(number, 10, pFile);
	n = atoi(number);
	fclose(pFile);

	for (int i =1; i<=10; i++)
	{
		divbythree = (i % 3 == 0);
		divbyfive = (i%5 == 0);
		if (divbythree&& divbyfive)
		{
		}
		else if (divbythree)
			printf("Hoppity\n");
		else if (divbyfive)
			printf("Hophop\n");

	}

	return 0;
}
