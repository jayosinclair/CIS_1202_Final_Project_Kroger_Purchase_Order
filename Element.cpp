#include <iostream>
#include <cctype>
#include <string>
#include "SegmentLine.h"
#include "Element.h"
using namespace std;


Element :: Element() {

	elementNum = -1;
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

Element :: Element(string elem, int minimumChars, int maximumChars, string fieldDesc, docLocation loc, int poss, int idloop, bool required, int intVal, string strVal, double dblVal) {

	elementNum = elem;
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