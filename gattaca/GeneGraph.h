/*
 * GeneGraph.h
 *
 *  Created on: Sep 11, 2011
 *      Author: shuheng
 */

#include <vector>

#ifndef GENEGRAPH_H_
#define GENEGRAPH_H_

typedef struct _Prediction{
	int start;
	int stop;
	int score;

	_Prediction():start(0),stop(0),score(0) {}
	bool operator<(const _Prediction& rhs);


} Prediction;

bool Prediction::operator <(const _Prediction& rhs)
{
	return (this->start) < (rhs.start);
}

class GeneGraph {
private:
	typedef struct {
		int predID; // ID of -1 refers to the rootNode
		std::vector<int> children;
	} Node;

	Prediction* predCollection;
	int collectionSize;
	Node* nodeCollection;

	void ConstructNode(int nodeID, const std::vector<int> PredIDCollection);

public:
	Prediction* getPredCollection();
	int getCollectionSize();
	GeneGraph(Prediction predCollection[], int collectionSize);
	~GeneGraph();
};

#endif /* GENEGRAPH_H_ */
