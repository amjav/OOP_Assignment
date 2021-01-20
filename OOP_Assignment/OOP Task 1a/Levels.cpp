#include "Levels.h"
#include "Wall.h"
#include "Path.h"
#include "Key.h"
#include "Gate.h"
#include <string>
#include <iostream>
#include <fstream>


	int Levels:: GetStartX() const
	{
		return StartX;
	}

	int Levels:: GetStartY() const
	{
		return StartY;
	}

	int Levels:: GetExitX() const
	{
		return ExitX;
	}
	int Levels:: GetExitY() const
	{
		return ExitY;
	}

	//used to determine the position of the objects(hole, wall, path, key and gate)

	bool Levels::IsHoleAtPosition(int &x, int &y) {
		for (size_t i = 0; i < holes.size(); ++i)
		{
			if (holes[i].IsAtPosition(x, y))
			{
				return true;
			}
		}

		return false;
	}


	bool Levels::IsWallAtPosition(int &x, int &y)
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

	
	bool Levels::IsPathAtPosition(int &x, int &y)
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

	
	char Levels::IsGateAtPosition(int &x, int &y)
	{
		for (size_t i = 0; i < gate.size(); ++i)
		{
			if (gate[i].IsAtPosition(x, y))
			{
				return gate[i].GetSymbol();
			}
		}

		return 0;
	}


	char Levels::IsKeyAtPosition(int &x, int &y)
	{
		for (size_t i = 0; i < Keys.size(); ++i)
		{
			if (Keys[i].IsAtPosition(x, y))
			{
				return Keys[i].GetSymbol();
			}
		}

		return 0;
	}


	//used to add wall, key, gate, path and hole object to their corresponded vector so they can be displayed on the grid
	void Levels::AddWall(int &i, int &j) {
		walls.push_back(Wall(i, j));
	}


	void Levels::AddKey(int &i, int &j, char symbol) {
		Keys.push_back(Key(i, j, symbol));
	}


	void Levels::AddGate(int &i, int &j, char symbol) {
		gate.push_back(Gate(i, j, symbol));
	}

	void Levels::AddPath(int &i, int &j) {
		path.push_back(Path(i, j));
	}

	void Levels::AddHole(int &i, int &j) {
		holes.push_back(Hole(i, j));
	}

  //used before level is loaded so the value is not doubled.
	void Levels::clearVectors()
	{
		walls.clear();
		Keys.clear();
		gate.clear();
		path.clear();
		holes.clear();

		CollectedKeys.clear();
	}

	//used to open the right file for each level
	void Levels::CreateLevels(string level) {

		string myText;

		ifstream MyReadFile(level);

		if (MyReadFile.is_open())
		{
			cout << "This is open";
		}

		
		int LineNumber = 0;

		
		while (getline(MyReadFile, myText)) {
			
		  //used to determine where the keys, gets and walls are located
			for (int i = 0; i < SIZE; i++)
			{
				char c = myText[i];

				switch (c)
				{
				case '#':
					AddWall(i, LineNumber);
					break;
				case '~':
					AddPath(i, LineNumber);
					break;
				case 'H':
					AddHole(i, LineNumber);
					break;
				case 'E':
					AddGate(i, LineNumber, 'E');
					ExitX = i;
					ExitY = LineNumber;
					break;
				case 'S':
					AddGate(i, LineNumber, 'S');
					StartX = i;
					StartY = LineNumber;
					break;
				case 'Y':
					AddGate(i, LineNumber, 'Y');
					break;
				case 'V':
					AddGate(i, LineNumber, 'V');
					break;
				case 'R':
					AddGate(i, LineNumber,'R');
					break;
				case 'G':
					AddGate(i, LineNumber,'G');
					break;
				case 'O':	
					AddGate(i, LineNumber,'O');
					break;
				case 'D':
					AddGate(i, LineNumber,'D');
					break;
				case 'L':
					AddGate(i, LineNumber, 'L');
					break;
				case 'M':	
					AddGate(i, LineNumber, 'M');
					break;
				case 'v':
					AddKey(i, LineNumber,'v');
					break;
				case 'r':
					AddKey(i, LineNumber, 'r');
					break;
				case 'g':
					AddKey(i, LineNumber, 'g');
					break;
				case 'o':
					AddKey(i, LineNumber,'o');
					break;
				case 'd':
					AddKey(i, LineNumber,'d');
					break;
				case 'l':
					AddKey(i, LineNumber,'l');
					break;
				case 'm':
					AddKey(i, LineNumber,'m');
					break;
				case 'y':
					AddKey(i, LineNumber,'y');
					break; 
				case 'e':
					AddKey(i, LineNumber, 'e');
					break;
				default:
					AddWall(i, LineNumber);
					assert(false);
				}

			}
			LineNumber += 1;
		}
		
	}


	







