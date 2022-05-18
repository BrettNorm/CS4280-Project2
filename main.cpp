/*
*** Author: Brett Bax
*** Assignment: Project 2
*** Class: CS4280
***
*** main.cpp is the main driver for Project 2.
*/

#include <fstream>
#include <iostream>

#include "parser.h"
#include "makeTree.h"

using namespace std;

int main(int argc, char *argv[]) {
	
	ifstream inFile;
	string file;
	
	if(argc == 1){
		try {
			string input;
			ofstream inputFile;
			file = "userInputFile.sp2022";
			inputFile.open(file.c_str());
			while(getline(cin, input)) {
				inputFile << input << "\n";
			}

			inputFile.close();

		} catch(const ifstream::failure& e){
			cout << "File does not exist\n";
			return 1;
		}

	} else if(argc == 2){
		file = argv[1];
		file.append(".sp2022");

	} else if(argc > 2){ 
		cout << "ERROR: Too many arguments. 2 or less, please.\n";
		cout << "USAGE: 	   './scanner'	(hit enter, then keyboard input to userInputFile),\n";
		cout << "	or './scanner [fileName]'	(.sp2022 extension added automatically),\n";
		cout << "  	or './scanner < [fileName.ext]'\n";
		return 1;
	}
	cout << "\nOpening file stream...\n\n";
	inFile.open(file.c_str());

	node *parseTree = parser(inFile);

	treeMaker(parseTree);

	
	inFile.close();
	cout << "\nFile stream closed. Bye!\n\n";
		
	return 0;
}
