/*
 * GeneGraph.cpp
 *
 *  Created on: Sep 11, 2011
 *      Author: shuheng
 */

#include "GeneGraph.h"
#include <cstring>
#include <vector>
#include <algorithm>

Prediction *GeneGraph::getPredCollection()
{
	return predCollection;
}

int GeneGraph::getCollectionSize()
{
	return collectionSize;
}

GeneGraph::~GeneGraph()
{
	delete[] predCollection;
	delete[] nodeCollection;
}

GeneGraph::GeneGraph(Prediction predCollection[], int collectionSize) {
	this->predCollection = new Prediction[collectionSize+1];
	// the rootNode is at position 0
	(this->predCollection[0]).start = -10;
	(this->predCollection[0]).stop = -1;
	(this->predCollection[0]).score = 0;

	std::vector<Prediction> predCollectionList(predCollection, predCollection+collectionSize);
//	std::sort(predCollectionList.begin(), predCollectionList.end());

	memcpy(++(this->predCollection), &predCollectionList[0], sizeof(Prediction)*collectionSize);



	// initialize the nodeCollection
	nodeCollection = new Node[collectionSize+1];
	for (int i=0; i<= collectionSize; i++)
	{
		nodeCollection[i].predID = i;
	}

}

