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
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include "SegmentLine.h"
#include "Element.h"
using namespace std;

int getNumLines();

int main() {

	int numSegmentLines = 0;
	char retry = 'Y';


	while (retry == 'Y') {

		try {

			numSegmentLines = getNumLines();
			retry = 'N';

		}

		catch (string fileNotFoundMsg) { //Handle exception by allowing user to check the file name/placement and try again without quitting the program.

			cout << fileNotFoundMsg;

			cout << "Try again? (Y/N): ";
			cin.get(retry);
			retry = toupper(retry);
			cin.ignore();

			if (retry != 'Y') {

				cout << "Please check the file name and placement before re-running the program." << endl << endl;
				return 0;
			}

		}

	}

	cout << "Number of lines: " << numSegmentLines << endl;


	cout << endl << endl;
	system("pause");
	return 0;

}


//******************************************************************************************************************************
//
//Function getNumLines preprocesses the EDI inputFile object to count the number of lines present.
//
//******************************************************************************************************************************

int getNumLines() {

	string bufferStr;
	int numLines = 0;
	string fileNotFound = "Error! Please be sure \"Kroger_EDI850_PurchaseOrder.txt\" is placed in the directory.\n\n";

	ifstream inputFile; //inputFile object has many rows, each aligning to a "segment."

	inputFile.open("Kroger_EDI850_PurchaseOrder.txt");

	if (!inputFile) {
		
		throw fileNotFound; //An exception is thrown here, making it so the entire program isn't nuked without giving some grace to try again in an associated catch.

	}

	while (getline(inputFile, bufferStr)) {

		numLines++;

	}

	inputFile.close();

	return numLines;

}







/*

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


*/