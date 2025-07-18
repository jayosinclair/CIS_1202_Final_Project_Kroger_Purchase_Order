#ifndef SEGMENTS.H
#define SEGMENTS.H

#include <string>
using namespace std;

enum docLocation { UNDEFINED, HEADING, DETAIL };

class Element {

	private:

		string ref;
		int minChars;
		int maxChars;
		string fieldLabel;
		docLocation location;
		int position;
		int loopID;
		bool mustUse;

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

		}

		Element(string reference, int minimumChars, int maximumChars, string fieldDesc, docLocation loc, int poss, int idloop, bool required) {

			ref = reference;
			minChars = minimumChars;
			maxChars = maximumChars;
			fieldLabel = fieldDesc;
			location = loc;
			position = poss;
			loopID = idloop;
			mustUse = required;

		}

		//Mutators

		void setRef(string refVal)
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


		//Accessors

		string setRef(string refVal) const
		{ return ref; }

		int setMinChars(int minimumChars) const
		{ return minChars; }

		int setMaxChars(int maximumChars) const
		{ return maxChars; }

		string setFieldLabel(string fieldDesc) const
		{ return fieldLabel; }

		docLocation setLocation(docLocation loc) const
		{ return location; }

		int setPosition(int poss) const
		{ return position; }

		int setLoopID(int idLoop) const
		{ return loopID; }

		bool setMustUse(bool required) const
		{ return mustUse; }

};


#endif