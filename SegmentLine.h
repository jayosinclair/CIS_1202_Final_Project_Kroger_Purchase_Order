#ifndef SEGMENTLINE_H
#define SEGMENTLINE_H

#include <string>
using namespace std;

class SegmentLine {

protected:

	string segmentID;


public:

	SegmentLine()  //These are all so short that I didn't break them into a separate cpp implementation file.

	{
		segmentID = "";
	}

	SegmentLine(string segID)

	{
		segmentID = segID;
	}

	~SegmentLine() {}

	void setSegmentID(string segIDVal)
	{
		segmentID = segIDVal;
	}

	string getSegmentID()	const
	{
		return segmentID;
	}

};


#endif