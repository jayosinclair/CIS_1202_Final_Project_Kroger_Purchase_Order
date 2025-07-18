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

};


#endif