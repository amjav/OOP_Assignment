#pragma once
#include "Wall.h"
#include "Hole.h"
#include "Key.h"
#include "Path.h"
#include "Gate.h"
#include <vector>
#include <string>

//using namespace std;

class Levels
{
	public:

		vector<Wall> walls;
		vector<Key> Keys;
		vector<Gate> gate;
		vector<Path> path;
		vector<Hole> holes;

		vector<Key> CollectedKeys;

		

		int GetExitX() const;
		int GetExitY() const;

		int GetStartX() const;
		int GetStartY() const;

		
		
		void CreateLevels(string level);

		void AddWall(int &i, int &j);
		void AddKey(int &i, int &j, char symbol);
		void AddGate(int &i, int &j, char symbol);
		void AddPath(int &i, int &j);
		void AddHole(int &i, int &j);

		bool IsWallAtPosition(int &x, int &y);
		bool IsPathAtPosition(int &x, int &y);
		char IsGateAtPosition(int &x, int &y);
		char IsKeyAtPosition(int &x, int &y);
		bool IsHoleAtPosition(int &x, int &y);
		void clearVectors();
	

	private:
		 
		int StartX;
		int StartY;
		int ExitX;
		int ExitY;
};


