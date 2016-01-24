/*
 * ConstraintGraph.cpp
 *
 *  Created on: Jun 14, 2011
 *      Author: shuheng
 */

#include "ConstraintGraph.h"

ConstraintGraph::ConstraintGraph(const char* filename) : Graph(filename) {
	// TODO Auto-generated constructor stub

}

bool ConstraintGraph::CheckConsistency(const char* name) {
	int id = returnid(name);
	if (id == -1)
		return false;
	return CheckConsistency(id);
}

bool ConstraintGraph::CheckConsistency(const int id) {
	std::vector<int> backtargets = getBackTargets(id);
	int numoftargets = getNumOfTargets(id);
	int targets[numoftargets];
	getTargets(id, targets);
	int cur_id;
	int cur_state;
	int my_state = getState(id);

	std::vector<int> neighbors(backtargets);

	// Append targets to a neighbors list
	for (int i=0; i < numoftargets; i++)
		neighbors.push_back(targets[i]);
	// Check through neighbors
	for (int i=0; i<neighbors.size(); i++) {
		cur_id =  neighbors[i];
		cur_state = getState(cur_id);
		if (cur_state == 0) // If undetermined
		{
			if (my_state==1)
				setState(cur_id, -1);
			else if (my_state==-1)
				setState(cur_id, 1);
			else // mystate is zero.  this is fucked up
				printf("MY STATE IS ZERO.  AHHHHHHH");
			if(!CheckConsistency(cur_id))
				return false;
		}
		else if (cur_state == 1) // If neighbor_state is true
		{
			if (my_state==1) // Check contradiction
				return false;
		}
		else if(cur_state == -1) {
			if (my_state == -1)
				return false;
		}
	}
	return true;

}
