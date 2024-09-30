#include <cctype>
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
		"q - Quit" << endl;
}

void GetNumOfNonWSCharacters(const string text){
	int numChars = 0;
	for (int i = 0; i < text.length(); i++){
		if (!isspace(text.at(i))){
			numChars++;
		}
	}
	cout << numChars << endl;
}

//Exicute Menu functiun calls the apropriate function from the menu
void ExicuteMenu(char input, string text){
	//switch case to call the functions
	switch (input) {
		case 'c':
			GetNumOfNonWSCharacters(text);
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
			return;
			break;
		default:
			cout << "Invallid input, enter a new selection" << endl;
			break;
	}
	PrintMenu();
	char temp;
	cin >> temp;
	ExicuteMenu(temp, text);
}

int main() {

	string userStr; // the users input text
	char input;

	cout << "Please enter a string: " << endl;
	getline(cin, userStr);	

	PrintMenu();
	cin >> input;
	ExicuteMenu(input, userStr);

   return 0;
}

