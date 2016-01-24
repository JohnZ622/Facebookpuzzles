/*
 * Graph.h
 *
 *  Created on: Jun 9, 2011
 *      Author: shuheng
 */

#include <stdio.h>
#include <string>
#include <set>
#include <vector>

#ifndef GRAPH_H_
#define GRAPH_H_

#define MAX_NAME_SIZE 30


struct Person{
	int state;  // 0 undetermined, 1 true, -1 false
	int cur_num_targets;
	int* targets;
	std::vector<int> backTargets;
};


class Graph {
private:
	int size;
	char** names;
	int currentsize;
	Person* persons;
	int addPerson(const char* name); // returns the ID of the person
	void addTarget(const char* source, const char* target);//TO DO might want to throw exception here
	void setNumOfTargets(const char* name, const int num_targets);
	std::set<std::string> EmptySet; // contains the set of Persons with empty states
public:
	Graph(const char* filename);
	~Graph();
	int returnid(const char* name) const;
	int getSize() const;
	int getState(const char* source) const;
	int getState(const int sourceid) const;
	void setState(const char* source, int newState);
	void setState(const int sourceid, int newState);
	std::vector<int> getBackTargets(const char* source) const;
	std::vector<int> getBackTargets(const int sourceid) const;
	void getTargets(const char* source, int* ptr) const;
	void getTargets(const int sourceid, int* ptr) const;
	int getNumOfTargets(const char* source) const;
	int getNumOfTargets(const int sourcied) const;
	bool getEmptyPerson(char* returnPtr) const;
	void getNames(char** ptr) const;
	void resetStates();
	int getLargerGroupSize();
};

#endif /* GRAPH_H_ */
