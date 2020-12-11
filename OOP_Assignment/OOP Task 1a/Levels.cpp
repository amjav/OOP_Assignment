#include "Levels.h"
#include "Wall.h"
#include "Path.h"
#include "Keys.h"
#include "Gate.h"
#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


	void Levels::GetLevel() {

	}

	bool Levels::IsWallAtPosition(int x, int y)
	{
		for (size_t i = 0; i < walls.size(); ++i)
		{
			if (walls[i].IsAtPosition(x, y))
			{
				return true;
			}
		}

		return false;
	}

	bool Levels::IsPathAtPosition(int x, int y)
	{
		for (size_t i = 0; i < path.size(); ++i)
		{
			if (path[i].IsAtPosition(x, y))
			{
				return true;
			}
		}

		return false;
	}

	bool Levels::IsGateAtPosition(int x, int y)
	{
		for (size_t i = 0; i < gate.size(); ++i)
		{
			if (gate[i].IsAtPosition(x, y))
			{
				return true;
			}
		}

		return false;
	}

	char Levels::IsKeyAtPosition(int x, int y)
	{
		for (size_t i = 0; i < Key.size(); ++i)
		{
			if (Key[i].IsAtPosition(x, y))
			{
				return Key[i].GetSymbol();
			}
		}

		return 0;
	}



	void Levels::AddWall(int i, int j) {
		walls.push_back(Wall(i, j));
	}

	void Levels::AddKey(int i, int j) {
		Key.push_back(Keys(i, j));
	}

	void Levels::AddGate(int i, int j) {
		gate.push_back(Gate(i, j));
	}

	void Levels::AddPath(int i, int j) {
		path.push_back(Path(i, j));
	}

	void Levels::CreateLevels() {


		//USE A TEXT FILE TO INTIATE LEVELS

	   // Create a text string, which is used to output the text file
		string myText;

		// Read from the text file
		ifstream MyReadFile("level1.txt");

		if (MyReadFile.is_open())
		{
			cout << "This is open";
		}

		//lineNumber
		int LineNumber = 0;

		// Use a while loop together with the getline() function to read the file line by line
		while (getline(MyReadFile, myText)) {
			// Output the text from the file

			  //cout << myText << endl;

			for (int i = 0; i < SIZE; i++)
			{
				char c = myText[i];

				switch (c)
				{
				case '#':
					//Wall::Wall(i, LineNumber);
					AddWall(i, LineNumber);
					break;
				case '~':
					//Path::Path(i, LineNumber);
					AddPath(i, LineNumber);
					break;
				case 'P':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'H':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'E':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'S':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'Y':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'V':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'R':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'G':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'O':
					//Gate::Gate(i, LineNumber);	
					AddGate(i, LineNumber);
					break;
				case 'D':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'L':
					//Gate::Gate(i, LineNumber);
					AddGate(i, LineNumber);
					break;
				case 'M':
					//Gate::Gate(i, LineNumber);	
					AddGate(i, LineNumber);
					break;
				case 'v':
					//Keys::Keys(i, LineNumber);
					AddKey(i, LineNumber);
					break;
				case 'r':
					//Keys::Keys(i, LineNumber);
					AddKey(i, LineNumber);
					break;
				case 'g':
					//Keys::Keys(i, LineNumber);
					AddKey(i, LineNumber);
					break;
				case 'o':
					//Keys::Keys(i, LineNumber);
					AddKey(i, LineNumber);
					break;
				case 'd':
					//Keys::Keys(i, LineNumber);
					AddKey(i, LineNumber);
					break;
				case 'l':
					//Keys::Keys(i, LineNumber);
					AddKey(i, LineNumber);
					break;
				case 'm':
					//Keys::Keys(i, LineNumber);
					AddKey(i, LineNumber);
					break;
				case 'y':
					//Keys::Keys(i, LineNumber);
					AddKey(i, LineNumber);
					break;

				}

			}
			LineNumber += 1;
		}
	}
	







