#include "Levels.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


void Levels::GetLevel() {

}

/*int Levels::SetLevel(string num) {

	if()


}*/

void Levels::CreateLevels() {


	//USE A TEXT FILE TO INTIATE LEVELS

   // Create a text string, which is used to output the text file
	string myText;

	// Read from the text file
	ifstream MyReadFile("level1.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
	  
			cout << myText << endl;


		//for (int i = 0; i < SIZE; i++)
		//{
		//	char c = myText[i];

		//	for (int j = 0; j < SIZE; j++) {
		//		switch (c) {
		//		case '#':
		//			//walls.push_back(Wall(i, j));
		//			break;
		//		case '~':
		//			break;
		//		case 'P':
		//			break;
		//		case 'H':
		//			break;
		//		case 'E':
		//			break;
		//		case 'S':
		//			break;
		//		case 'Y':
		//			break;
		//		case 'V':
		//			break;
		//		case 'R':
		//			break;
		//		case 'G':
		//			break;
		//		case 'O':
		//			break;
		//		case 'D':
		//			break;
		//		case 'y':
		//			break;
		//		case 'L':
		//			break;
		//		case 'M':
		//			break;
		//		case 'v':
		//			break;
		//		case 'r':
		//			break;
		//		case 'g':
		//			break;
		//		case 'o':
		//			break;
		//		case 'd':
		//			break;
		//		case 'l':
		//			break;
		//		case 'm':
		//			break;

		//		}

		//	}
		//}
	}

	// Close the file
	MyReadFile.close();
}




