//Jay Olson
//CIS 1202-800
//July 17, 2025
//Final Project: Kroger Purchase Order "Renderer"

//This project takes a sample, dumbed-down purchase order ANSI X12 EDI 850 version 0040 transaction using Kroger's published implementation convention
//and "renders" it for mortals to read both in the console and in a text file. This program implements concepts from CIS 1202 in the process:
//Sorting algorithms, character data, structs, enums, classes, exceptions, and templates.
//Note: I did not attempt to implement the entire implementation convention, and I'm sure if I knew more there would be better ways of doing
//things. This is an elementary stab at it, knowing I've taken some shortcuts to cut down on complexity.

//Kroger's implementation convention is published at https://edi.kroger.com/EDIPortal/documents/Maps/kroger-modernized-systems/Kroger-Modernized-systems_EDI850.pdf.
//See the readme file on GitHub repository for this project for some EDI basics as they apply to this project.

#include <iostream>
#include <cctype>
#include <string>
#include "element.h"
using namespace std;

int main() {

	//Perhaps read all this in from a file. It's quite cumbersome here...

	/*
	
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

	
	*/

	Element segmentST01;
	segmentST01.setRef("ST01");
	segmentST01.setMinChars(3);
	segmentST01.setMaxChars(3);
	segmentST01.setFieldLabel("Transaction Set Number");
	segmentST01.setLocation(HEADING);
	segmentST01.setPosition(0);
	segmentST01.setLoopID(0);
	segmentST01.setMustUse(true);

	cout << segmentST01.getRef() << endl;
	cout << segmentST01.getFieldLabel() << endl;




	cout << endl << endl;
	system("pause");
	return 0;

}