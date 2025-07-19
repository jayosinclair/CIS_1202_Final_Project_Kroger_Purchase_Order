//Jay Olson
//CIS 1202-800
//July 17, 2025
//Final Project: Kroger Purchase Order "Renderer"

//This project takes a sample, dumbed-down purchase order ANSI X12 EDI 850 version 0040 transaction using Kroger's published implementation convention
//and "renders" it for mortals to read both in the console and in a text file. This program implements concepts from CIS 1202 in the process:
//Sorting algorithms, character data, structs, enums, pointers, classes, exceptions, and templates.
//Note: I did not attempt to implement the entire implementation convention, and I'm sure if I knew more there would be better ways of doing
//things. This is an elementary stab at it, knowing I've taken some shortcuts to cut down on complexity.

//Kroger's implementation convention is published at https://edi.kroger.com/EDIPortal/documents/Maps/kroger-modernized-systems/Kroger-Modernized-systems_EDI850.pdf.
//See the readme file on GitHub repository for this project for some EDI basics as they apply to this project.

#include <iostream>
#include <cctype>
#include <string>
#include "SegmentLine.h"
#include "Element.h"
using namespace std;

int main() {

	//Driver for now...

	SegmentLine seg;
	seg.setSegmentID("ST");

	Element e01;
	e01.setSegmentID("ST");
	e01.setElementNum("01");
	e01.setMinChars(3);
	e01.setMaxChars(3);
	e01.setFieldLabel("Transaction Set Number");
	e01.setLocation(HEADING);
	e01.setPosition(0);
	e01.setLoopID(0);
	e01.setMustUse(true);

	cout << e01.getSegmentID() << e01.getElementNum() << endl;
	cout << "Min chars: " << e01.getMinChars() << endl;
	cout << "Max chars: " << e01.getMaxChars() << endl;
	cout << "Field: " << e01.getFieldLabel() << endl;


	cout << endl << endl;
	system("pause");
	return 0;

}