#pragma once
#include "Wall.h"
#include <vector>


class Levels
{
	public:
		

		vector<Wall> Level1;
		vector<Wall> Level2;
		vector<Wall> Level3;
		
		void CreateLevels();


	

	private:
		void GetLevel();
		//int SetLevel();

};


