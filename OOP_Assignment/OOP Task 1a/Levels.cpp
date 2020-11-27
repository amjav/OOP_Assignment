#include "Levels.h"

void Levels::GetLevel() {

}

/*int Levels::SetLevel(string num) {

	if()


}*/

void Levels::CreateLevels() {
   
    //TO DO:
    //Questions
    //why in the wall symbol set to hole in the wall.cpp file? ANS: mistake 
    //does this intiate all places in the grid as holes automatically? ANS: 
    //is it best to create seperate vector for a level ? for example an vector for wall and a vector for floor?
    //is there a possible way to ahve one vector for all?


    //USE A TEXT FILE TO INTIATE LEVELS

    



for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            //TO DO: if statement to work out if coords has a floor assigned to it already or if it can be filled with a wall.
            //if( )    
        
        Level1.push_back(Wall(x, y));
            //walls
       
        }

    }



        //Level2.push_back(Wall(, ));
        //Level2.push_back(Wall(,))
        //Level2.push_back(Wall(,))
        //Level2.push_back(Wall(,))
        //Level2.push_back(Wall(,))
        //Level2.push_back(Wall(,))
        //Level2.push_back(Wall(,))
        //
        //Level3.push_back(Wall(,))
        //Level3.push_back(Wall(,))
        //Level3.push_back(Wall(,))
        //Level3.push_back(Wall(,))
        //Level3.push_back(Wall(,))
        //Level3.push_back(Wall(,))
        //Level3.push_back(Wall(,))
        //Level3.push_back(Wall(,))
        //Level3.push_back(Wall(,))

}


