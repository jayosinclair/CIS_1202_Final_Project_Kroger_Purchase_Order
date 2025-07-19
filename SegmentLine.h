#ifndef SEGMENTLINE_H
#define SEGMENTLINE_H

#include <iostream>
#include <string>
using namespace std;

class SegmentLine {

protected:

	string segmentID;
	int numElements;


public:

	//Constructors and destructor

	SegmentLine()  //These are all so short that I didn't break them into a separate cpp implementation file.

	{
		segmentID = "";
		numElements = 0;
		
	}

	SegmentLine(string segID, int numElems)

	{
		segmentID = segID;
		numElements = numElems;

	}

	~SegmentLine() {}

	
	//Mutators

	void setSegmentID(string segIDVal)
	{ segmentID = segIDVal; }

	void setNumElements(int numElems)
	{ numElements = numElems; }

	
	//Accessors

	string getSegmentID() const
	{ return segmentID; }

	int getNumElements() const
	{ return numElements; }

	void displaySegmentID() //TODO: Should const be displayed here? There's already a guard with the accessor in the called get functions.
	{ std::cout << getSegmentID(); }

	void displayNumElements()
	{ std::cout << getNumElements(); }

};


#endif