#include <iostream>
#include <string>
using namespace std;

//print menu, prints the menu
void PrintMenu(){
	cout << "MENU" << endl <<
		"c - Number of non-whitespace characters" << endl << 
		"w - Number of words" << endl <<
		"f - Find text" << endl <<
		"r - Replace all !/'s"<< endl <<
		"s - Shorten spaces"<< endl <<
		"q - Quit";
}

//Exicute Menu functiun calls the apropriate function from the menu
void ExicuteMenu(char input, string text){
	//switch case to call the functions
	switch (input) {
		case 'c':
			break;
		case 'w':
			break;
		case 'f':
			break;
		case 'r':
			break;
		case 's':
			break;
		case 'q':
			break;
		default:
			cout << "Invallid input, please try again" << endl;

	}
}

int main() {

	string userStr; // the users input text
	char input;

	cout << "Please enter a string: " << endl;
	getline(cin, userStr);	
   return 0;
}

