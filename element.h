#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
using namespace std;

enum docLocation { UNDEFINED, HEADING, DETAIL };

class Element {

	const int INT_UNDEFINED = 9999999;
	const string STR_UNDEFINED = "UNDEFINED";
	const double DBL_UNDEFINED = 9999999.0;


	private:

		string ref;

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

		//Default Constructor.

		Element() {
		
			ref = "";
			minChars = 0;
			maxChars = 0;
			fieldLabel = "";
			location = UNDEFINED;
			position = -1;
			loopID = -1;
			mustUse = false;
			intValue = INT_UNDEFINED;
			strValue = STR_UNDEFINED;
			dblValue = DBL_UNDEFINED;

		}

		Element(string reference, int minimumChars, int maximumChars, string fieldDesc, docLocation loc, int poss, int idloop, bool required, int intVal, string strVal, double dblVal) {

			ref = reference;
			minChars = minimumChars;
			maxChars = maximumChars;
			fieldLabel = fieldDesc;
			location = loc;
			position = poss;
			loopID = idloop;
			mustUse = required;
			intValue = intVal;
			strValue = strVal;
			dblValue = dblVal;

		}

		//Mutators

		void setRef(string refVal)				//These are all so short that I didn't break them into a separate cpp implementation file.
		{ ref = refVal; }

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
		{
			intValue = intVal;
		}

		void setDblValue(double dblVal)
		{
			dblValue = dblVal;
		}

		void setStrValue(string strVal)
		{
			strValue = strVal;
		}


		//Accessors

		string getRef() const
		{ return ref; }

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