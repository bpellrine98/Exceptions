// Brian Pellrine
// CIS 1202 101
// December 2, 2023

#include <iostream>

using namespace std;

//Exception classes
class invalidCharacterExcpeption{};
class invalidRangeException{};
class caseConversionException{};

//Function to find the character offset value
char character(char start, int offset) {

	//Find the ascii value of start
	int startAsciiValue = int(start);
	
	//Add character offset of start's ascii value to target value
	int target = startAsciiValue + offset;
	
	try {
		//if start is not a lower/upper case alphabetical letter
		if(startAsciiValue < 65 || (startAsciiValue > 90 && startAsciiValue < 97) || startAsciiValue > 122) {
			throw invalidCharacterExcpeption();
		}

		//if target is not a lower/upper case alphabetical letter
		if(target < 65 || (target > 90 && target < 97) || target > 122 ) {
			throw invalidRangeException();
		}

		//if target is lower case and start is upper case or vice versa
		if((target >= 65 && target <= 90 && startAsciiValue >= 95 && startAsciiValue <= 122) || (target >= 95 && target <= 122 && startAsciiValue >= 65 && startAsciiValue <= 90)) {
			throw caseConversionException();
		}
	}
	
	//catch all exceptions
	catch (invalidCharacterExcpeption exception1) {
		cout << "Invalid Character Exception" << endl;
		return ' ';
	}

	catch(invalidRangeException exception2) {
		cout << "Invalid Range Exception" << endl;
		return ' ';
	}

	catch(caseConversionException exception3) {
		cout << "Cannot make case changes from upper to lower or otherwise" << endl;
		return ' ';
	}
	
	//if no exception was catched return the character value of target
	return char(target);
}

int main() {
	cout << character('a', 1) << endl << endl;
	cout << character('a', -1) << endl;
	cout << character('Z', -1) << endl << endl;
	cout << character('?', 5) << endl;
	cout << character('A', 32);
}