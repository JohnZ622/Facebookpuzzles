//============================================================================
// Name        : liarliar.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ANSI-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <string>
#include "ConstraintGraph.h"
#include <typeinfo>
#include <cstdlib>

int main(int argc, char* argv[]) {

	if (argc==1)
	{
		std::cout << "Insufficient arguments" << std::endl;
		return 1;
	}

	ConstraintGraph myGraph(argv[1]);

	// Print name sequence
	int size = myGraph.getSize();
	char* myArray[size];
	for (int i=0; i<size; i++)
		myArray[i] = new char[MAX_NAME_SIZE];
	myGraph.getNames(myArray);
	for (int i=0; i <size; i++)
		printf("%d %s \n", i, myArray[i]);

	char emptyperson[MAX_NAME_SIZE];
	bool status = myGraph.getEmptyPerson(emptyperson);

	if (status == false) { // There is still an empty person
		std::cerr << "No empty persons" << std::endl;
		return 1;
	}

	myGraph.setState(emptyperson, 1); // Set an initial state to truthful

	if (myGraph.CheckConsistency(emptyperson)) {
		std::cout << "Graph is consistent" << std::endl;
		int largesize = myGraph.getLargerGroupSize();
		std::cout << largesize << " ";
		int smallsize = myGraph.getSize() - largesize;
		std::cout<< smallsize << std::endl;
		return 1;
	}

	myGraph.resetStates();
	status = myGraph.getEmptyPerson(emptyperson);
	if (status == false) { // There is still an empty person
			std::cerr << "No empty persons" << std::endl;
			return 1;
	}
	myGraph.setState(emptyperson, -1);
	if (myGraph.CheckConsistency(emptyperson)) {
		std::cout << "Graph is consistent" << std::endl;
		int largesize = myGraph.getLargerGroupSize();
		std::cout << largesize << " ";
		int smallsize = myGraph.getSize() - largesize;
		std::cout<< smallsize << std::endl;
		return 1;
	}

	std::cout << "Graph is INCONSISTENT!!!" << std::endl;
	return 1;
}
