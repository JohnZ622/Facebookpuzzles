/*
 * Graph.cpp
 *
 *  Created on: Jun 9, 2011
 *      Author: shuheng
 */

#include "Graph.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

Graph::Graph(const char* filename) {
	char line[30];

	FILE* file = fopen(filename, "r");
	char* status=fgets(line, 30, file);
	if (status==NULL)
			perror("Problem reading file");
			//TO DO: Throw exception here
	size = atoi(line);
	persons = new Person[size];
	names = new char *[size];
	currentsize = 0;

	while (!feof(file))
	{
		char nextPerson[MAX_NAME_SIZE];
		int id;
		unsigned int numOfTargets;
		fscanf(file, "%s %u \n", nextPerson, &numOfTargets);

		// Check if exists
		id = returnid(nextPerson);
		if (id == -1) // nextPerson doesn't exist yet
		{
			id = addPerson(nextPerson);
			EmptySet.insert(nextPerson); // EmptySet is the set of Persons with no targets
		}
		setNumOfTargets(nextPerson, numOfTargets);
		for (unsigned int i=0; i<numOfTargets; i++)  // Cycle through the targets of this person
		{
			fscanf(file, "%s \n", line); // line contains the name of the next target
			id = returnid(line);
			if (id == -1)
				id = addPerson(line);
			addTarget(nextPerson, line);
		}
	}

	fclose(file);
}

Graph::~Graph()
{
	delete[] persons;
	delete[] names;
}

int Graph::getSize() const{
	return size;
}

void Graph::getNames(char** ptr) const {
	for (int i=0; i < size; i++)
		strcpy(ptr[i], names[i]);
}

int Graph::returnid(const char* name) const{
	for (int i=0; i<currentsize; i++)
	{
		if (strcmp(name, names[i])==0) // ==0 means both strings are equal
			return i;
	}
	return -1;
}

int Graph::addPerson(const char* name) {
	int id = returnid(name);
	if (id!= -1)
		return id;
	// currentsize contains the ID to the new guy (remember ID = size-1)
	names[currentsize] = new char[MAX_NAME_SIZE];
	strcpy(names[currentsize], name);
	persons[currentsize].state = 0;
	persons[currentsize].cur_num_targets = 0;
	return currentsize++; // finally inflate the current size
}

void Graph::setNumOfTargets(const char* name, const int numoftargets)
{
	int id = returnid(name);;
	if (id == -1)
	{
		// Throw exception here
	}
	persons[id].targets = new int[numoftargets];
}

void Graph::addTarget(const char* source, const char* target) { // Should throw no source exception
	int sourceid = returnid(source);
	int targetid = returnid(target);
	if (targetid == -1)
		targetid = addPerson(target);
	persons[sourceid].targets[persons[sourceid].cur_num_targets++] = targetid;
	persons[targetid].backTargets.push_back(sourceid);
}

int Graph::getState(const char* source) const {
	int id = returnid(source);
	return getState(id);
}

int Graph::getState(const int sourceid) const {
	return persons[sourceid].state;
}

void Graph::setState(const char* source, int newState) {
	int id = returnid(source);
	setState(id, newState);
}

void Graph::setState(int sourceid, int newState) {
	persons[sourceid].state = newState;
	if (newState != 0)  // New state is not the empty state
		EmptySet.erase(names[sourceid]);
}

int Graph::getNumOfTargets(const char* source) const {
	int id = returnid(source);
	if (id==-1)
		return -1;
	else
		return getNumOfTargets(id);
}

int Graph::getNumOfTargets(const int sourceid) const{
	return persons[sourceid].cur_num_targets;
}

void Graph::getTargets(const char* source, int* ptr) const {
	int id = returnid(source);
	if (id == -1)
	{
		*ptr = -1;
	}
	else
	{
		getTargets(id, ptr);
	}
	return;
}

void Graph::getTargets(const int sourceid, int* ptr) const{
	// Copy over array
	for (int i=0; i<persons[sourceid].cur_num_targets; i++)
		ptr[i] = persons[sourceid].targets[i];
}

std::vector<int> Graph::getBackTargets(const char* source) const{
	int id = returnid(source);
	if (id == -1)
		return std::vector<int>();
	return getBackTargets(id);
}

std::vector<int> Graph::getBackTargets(const int sourceid) const{
	return persons[sourceid].backTargets;
}

bool Graph::getEmptyPerson(char* returnPtr) const{
	if (EmptySet.empty())
		return false;
	else
	{
		strcpy(returnPtr, (*EmptySet.begin()).c_str());
		return true;
	}
}

void Graph::resetStates() {
	for (int i=0; i < size; i++)
		persons[i].state = 0;
}

int Graph::getLargerGroupSize()
{
	int z = 0;
	for (int i = 0; i < size; i++)
	{
		if (persons[i].state == 1)
			z++;

	}
	if (z > size/2)
		return z;
	else
		return size-z;
}


