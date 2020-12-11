#pragma once
#include "Wall.h"
#include "Game.h"
#include <vector>


class Levels
{
	public:
		

		vector<Wall> Level1;
		vector<Wall> Level2;
		vector<Wall> Level3;

	    vector<Wall> walls;
		vector<Keys> Key;
		vector<Gate> gate;
		vector<Path> path;
		
		void CreateLevels();

		void AddWall(int i, int j);
		void AddKey(int i, int j);
		void AddGate(int i, int j);
		void AddPath(int i, int j);

		bool IsWallAtPosition(int x, int y);
		bool IsPathAtPosition(int x, int y);
		bool IsGateAtPosition(int x, int y);
		bool IsKeyAtPosition(int x, int y);

		char whatIsKey(int x, int y);
	

	private:
		void GetLevel();
		//int SetLevel();

};


