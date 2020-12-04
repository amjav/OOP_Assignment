#include "Levels.h"
#include "Wall.h"
#include "Path.h"
#include "Keys.h"
#include "Gate.h"
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

	//lineNumber
	int LineNumber = 0;
	
	// Use a while loop together with the getline() function to read the file line by line
   	while (getline(MyReadFile, myText)) {
		// Output the text from the file
	  
			cout << myText << endl;

			
		  for (int i = 0; i < SIZE; i++)
		  {
			char c = myText[i];

				switch (c) 
				{
					case '#':
						Wall::Wall(i, LineNumber);
					break;
					case '~':
						Path::Path(i, LineNumber);
						break;
					case 'P':
						Gate::Gate(i, LineNumber);
						break;
					case 'H':
						Gate::Gate(i, LineNumber);
						break;
					case 'E':
						Gate::Gate(i, LineNumber);
						break;
					case 'S':
						Gate::Gate(i, LineNumber);
						break;
					case 'Y':
						Gate::Gate(i, LineNumber);
						break;
					case 'V':
						Gate::Gate(i, LineNumber);
						break;
					case 'R':
						Gate::Gate(i, LineNumber);
						break;
					case 'G':
						Gate::Gate(i, LineNumber);
						break;
					case 'O':
						Gate::Gate(i, LineNumber);	
						break;
					case 'D':
						Gate::Gate(i, LineNumber);
						break;
					case 'L':
						Gate::Gate(i, LineNumber);
						break;
					case 'M':
						Gate::Gate(i, LineNumber);	
						break;
					case 'v':
						Keys::Keys(i, LineNumber);
						break;
					case 'r':
						Keys::Keys(i, LineNumber);
						break;
					case 'g':
						Keys::Keys(i, LineNumber);
						break;
					case 'o':
						Keys::Keys(i, LineNumber);
						break;
					case 'd':
						Keys::Keys(i, LineNumber);
						break;
					case 'l':
						Keys::Keys(i, LineNumber);
						break;
					case 'm':
						Keys::Keys(i, LineNumber);
						break;
					case 'y':
						Keys::Keys(i, LineNumber);
						break;

				}
				
		  }	
			LineNumber += 1;
	}
}







