#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include "SegmentLine.h"
using namespace std;

enum docLocation { UNDEFINED, HEADING, DETAIL };

class Element : public SegmentLine {

	const int INT_UNDEFINED = 9999999;
	const string STR_UNDEFINED = "UNDEFINED";
	const double DBL_UNDEFINED = 9999999.0;

	private:

		string elementNum;
		int minChars;
		int maxChars;
		string fieldLabel;
		docLocation location;
		int position;
		int loopID;
		bool mustUse;
		int intValue;
		string strValue;
		double dblValue;

	public:

		Element(); //See element.cpp for definition

		Element(string elem, int minimumChars, int maximumChars, string fieldDesc, docLocation loc, int poss, int idloop, bool required, int intVal, string strVal, double dblVal);

		~Element(){ }

		//Mutators

		void setElementNum(string elem)
		{ elementNum = elem; }

		void setMinChars(int minimumChars)
		{ minChars = minimumChars; }

		void setMaxChars(int maximumChars)
		{ maxChars = maximumChars; }

		void setFieldLabel(string fieldDesc) 
		{ fieldLabel = fieldDesc; }

		void setLocation(docLocation loc)
		{ location = loc; }

		void setPosition(int poss)
		{ position = poss; }

		void setLoopID(int idLoop)
		{ loopID = idLoop; }

		void setMustUse(bool required)
		{ mustUse = required; }

		void setIntValue(int intVal)
		{ intValue = intVal; }

		void setDblValue(double dblVal)
		{ dblValue = dblVal; }

		void setStrValue(string strVal)
		{ strValue = strVal; }


		//Accessors

		string getElementNum() const
		{ return elementNum; }

		int getMinChars() const
		{ return minChars; }

		int getMaxChars() const
		{ return maxChars; }

		string getFieldLabel() const
		{ return fieldLabel; }

		docLocation getLocation() const
		{ return location; }

		int getPosition() const
		{ return position; }

		int getLoopID() const
		{ return loopID; }

		bool getMustUse() const
		{ return mustUse; }

		int getIntValue() const
		{ return intValue; }

		double getDblValue() const
		{ return dblValue; }

		string getStrValue() const
		{ return strValue; }

};


#endif