/*
 * ConstraintGraph.h
 *
 *  Created on: Jun 14, 2011
 *      Author: shuheng
 */

#ifndef CONSTRAINTGRAPH_H_
#define CONSTRAINTGRAPH_H_

#include "Graph.h"

class ConstraintGraph: public Graph {
public:
	ConstraintGraph(const char* filename);
	bool CheckConsistency(const char* name);
	bool CheckConsistency(const int id);
};

#endif /* CONSTRAINTGRAPH_H_ */
