#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//print menu, prints the menu
void PrintMenu(){
	cout << endl << "MENU" << endl <<
		"c - Number of non-whitespace characters" << endl << 
		"w - Number of words" << endl <<
		"f - Find text" << endl <<
		"r - Replace all !\'s"<< endl <<
		"s - Shorten spaces"<< endl <<
		"q - Quit" << endl << endl <<
		"Choose an option:" << endl;
}

int GetNumOfNonWSCharacters(const string& text){
	int numChars = 0;
	for (char i : text) {
		if (!isspace(i)){
			numChars++;
		}
	}
	return numChars;
}

int GetNumOfWords(const string& text) {
	//variables for the counting
	stringstream str(text);
	int count = 0;
	string word;

	while(str >> word) count ++; // increment count for each word

	return count;
} 

int FindText(const string& text, const string& toFind){
	int count = 0;
	int position = 0;

	while ((position = text.find(toFind, position)) != std::string::npos) {
		count ++;
		position += toFind.length();
	}
	return count;
}

void ReplaceExclamation(string& text) {
	for (int i=0; i < text.size(); ++i) {
		if (text[i] == '!'){
			text[i] = '.';
		}
	}
}

void ShortenSpace(string& text) {
	for (int i = 0; i < text.length(); ++i) {
		if (text[i] == ' ' && (((i + 1) <= text.length()) && text[i + 1] == ' ')){
			text.erase(i, 1);
			i--;
		}
	}
}

//Exicute Menu functiun calls the apropriate function from the menu
void ExicuteMenu(char input, string text){
	//switch case to call the functions
	switch (input) {
		case 'c':
			cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(text) << endl;
			break;
		case 'w':
			cout << "Number of words: " << GetNumOfWords(text) << endl;
			break;
		case 'f': { //brackets are to help with scope issues
			string toFind;
			cin.ignore();
			cout << "Enter a word or phrase to be found:" << endl;
			getline(cin, toFind);
			cout << "\"" << toFind << "\" " << "instances: " << FindText(text, toFind) << endl;
			break; }
		case 'r':
			ReplaceExclamation(text);
			cout << "Edited text: " << text << endl;
			break;
		case 's':
			ShortenSpace(text);
			cout << "Edited text: " << text << endl;
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

	cout << "Enter a sample text:" << endl;
	getline(cin, userStr);	
	cout << endl << "You entered: " << userStr << endl;

	PrintMenu();
	cin >> input;
	ExicuteMenu(input, userStr);

   return 0;
}


