/*
 * gattaca.c
 *
 *  Created on: Sep 11, 2011
 *      Author: shuheng
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include "GeneGraph.h"

#define MAX_LINE_SIZE 80

int main(int argc, char* argv[]) {

	std::ifstream mystream("input.txt");

	int DNAsize;
	mystream >> DNAsize; // read in DNA size
	mystream.ignore(10, '\n'); // next line
	char* DNA = new char[DNAsize];
	int numLines = DNAsize/80 + 1; // calculate number of lines

	char linein[MAX_LINE_SIZE]; // buffer for reading DNA
 	for (int count=1; count <=numLines; count++)
 	{
 		mystream.getline(linein, MAX_LINE_SIZE+1);
 		strcat(DNA, linein);
 	}
	std::cout << DNAsize << std::endl;
	std::cout << DNA << std::endl;

	int numGenes;
	mystream >> numGenes; // read in number of genes
	mystream.ignore(10, '\n');

	int temp_start, temp_stop, temp_score;

	Prediction* myPredCollection = new Prediction[numGenes];
	for (int i=0; i < numGenes; i++)
	{
		mystream >> temp_start >> temp_stop >> temp_score;
		mystream.ignore(10, '\n');
		myPredCollection[i].start = temp_start;
		myPredCollection[i].stop = temp_stop;
		myPredCollection[i].score = temp_score;
	}

	// GeneGraph myGeneGraph(myPredCollection, numGenes);

//	Prediction* tempPrediction;
	//tempPrediction = myGeneGraph.getPredCollection();

	mystream.close();
	// Read input

	Prediction pred1, pred2;
	pred1.start = 2;
	pred2.start = 1;

	std::vector<Prediction> myPred;
	myPred.insert(myPred.end(), pred1);
	myPred.insert(myPred.end(), pred2);
//	std::sort(myPred.begin(), myPred.end());
	std::cout << (pred1<pred2) << std::endl;

	return 1;

}
