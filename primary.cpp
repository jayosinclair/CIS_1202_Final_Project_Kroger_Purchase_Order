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

void preProcessEdiFile(int*);
int getNumLines();
void tokenizeSegmentLine(int*);

int main() {

	int numSegmentLines; //Set up to demonstrate mechanics of making a pointer for the number of segment lines.
	int* numSegmentLinesPtr = &numSegmentLines;
	*numSegmentLinesPtr = 0;

	preProcessEdiFile(numSegmentLinesPtr);


	cout << endl << endl;
	system("pause");
	return 0;

}


//******************************************************************************************************************************
//
//Function readEdiFile calls functions needed to figure out how many rows/lines exist in the file.
//
//******************************************************************************************************************************

void preProcessEdiFile(int *numSegmentLinesPtr) {

	char retry = 'Y';

	while (retry == 'Y') {

		try {

			*numSegmentLinesPtr = getNumLines();
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
				exit(EXIT_SUCCESS);
			}

		}

	}

	cout << "Number of lines: " << *numSegmentLinesPtr << endl;

	tokenizeSegmentLine(numSegmentLinesPtr);

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


void tokenizeSegmentLine(int* numSegmentLinesPtr) {

	int lineCounter = 0;
	int rowDelimiterCounter = 0;
	string wholeLine; //Read in entire line before processing it.
	string segmentID; //Will need to store every token as a string before casting it to a correct data type later.
	string tempToken;
	
	string fileNotFound = "Error! Please be sure \"Kroger_EDI850_PurchaseOrder.txt\" is placed in the directory.\n\n"; //We already did this, but just to be safe...

	ifstream inputFile;

	inputFile.open("Kroger_EDI850_PurchaseOrder.txt");

	while (getline(inputFile, wholeLine) && lineCounter < *numSegmentLinesPtr) {

		rowDelimiterCounter = 0; //Reset delimiter counter

		if (!inputFile) {

			throw fileNotFound; //An exception is thrown here, making it so the entire program isn't nuked without giving some grace to try again in an associated catch.

			//TODO: This throw statement needs to be tied to a try/catch correctly.

		}

		stringstream stringObject(wholeLine); //String stream object used in reading entire line as a string before parsing it.

		getline(stringObject, segmentID, '*');
		cout << segmentID << " "; //TODO: segmentIDs can be fed into a dynamic array and be copied into another array as names of objects carrying other data?

		//TODO: Need to figure out how many elements are in the file for each segmentID.

		while (getline(stringObject, tempToken, '*')) {

			rowDelimiterCounter++;

		}

		cout << rowDelimiterCounter++ << endl;


	}


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