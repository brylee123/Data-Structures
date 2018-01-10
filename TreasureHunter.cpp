#include <iostream>
#include "TreasureHunter.h"
#include "GameBoard.h"
#include <cmath>

TreasureHunter::TreasureHunter(int x, int y, GameBoard& board){
	this -> xposition = x;
    this -> yposition = y;
    this -> currentloc = Location(xposition, yposition);
    this -> oldGameBoard = &board;
}

TreasureHunter::~TreasureHunter(){
    // TODO Destructor
}

void TreasureHunter::changeBoard(GameBoard& newBoard){ 
    // TODO  Scoring Pt. 1 (2 Points)
    this -> oldGameBoard = &newBoard; // Changed location only
}

void TreasureHunter::changeBoard(GameBoard* newBoard){
    // TODO Efficiency (1 Point)
    oldGameBoard = newBoard;
}

int TreasureHunter::computeScore(std::string inputString){
    // TODO Scoring Pt. 2

	int playerState = 0;
	// 0 == normalMode
	// 1 == underAttack

    // Begin Manual Value Changes
	// int score = 50; // Starting score must be 50
	// int xposition = 5; // Hunter's Postion x
	// int yposition = 5; // Hunter's Postion y
	// Location goalLocation(0, 1);
    // GameBoard board(goalLocation);
    // End Manual Value Changes

	int displacementX = 0;
	int displacementY = 0;
    int newdisplacementX = 0;
    int newdisplacementY = 0;
    int oldScore = 0; // To compare with current score to determine +1 or -2

    std::cout << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Old Board Values: " << std::endl;
    std::cout << "Treasure Location: ( 8, 9)     " << oldGameBoard->isTreasure(Location(8, 9)) << std::endl;
    std::cout << "Treasure Location: (12,-1)     " << oldGameBoard->isTreasure(Location(12,-1)) << std::endl;
    std::cout << "Enemy Location:    ( 4, 7)     " << oldGameBoard->isEnemy(Location(4, 7)) << std::endl << std::endl;

    std::cout << "New Board Values: " << std::endl;
    std::cout << "Treasure Updates: ( 0, 2)      " << oldGameBoard->isTreasure(Location(0, 2)) << std::endl;
    std::cout << "Treasure Updates: (-10, 8)     " << oldGameBoard->isTreasure(Location(-10, 8)) << std::endl;
    std::cout << "Treasure Updates: ( 3,12)      " << oldGameBoard->isTreasure(Location(3, 12)) << std::endl;
    std::cout << "Enemy Updates: (-1, 1)         " << oldGameBoard->isEnemy(Location(-1, 1)) << std::endl;
    std::cout << "Enemy Updates: ( 5, 2)         " << oldGameBoard->isEnemy(Location(5, 2)) << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++" << std::endl;


    for (int i = 0; i < inputString.length(); ++i) // Start Searching Inputs
    {

    	std::cout << std::endl;

    	if (playerState == 0) // normalMode
    	{
    		displacementX = abs(xposition-oldGameBoard->getGoalLocation().getX());
    		displacementY = abs(yposition-oldGameBoard->getGoalLocation().getY());

    		oldScore = score;

    		// Begin Input-Check
            if        (inputString.at(i) == 'u') {
                yposition++;
                newdisplacementY = abs(yposition-oldGameBoard->getGoalLocation().getY());
                score += (displacementY > newdisplacementY) ? 1 : -2;
                std::cout << "Pressed U" << std::endl;

            } else if (inputString.at(i) == 'l') {
                xposition--;
                newdisplacementX = abs(xposition-oldGameBoard->getGoalLocation().getX());
                score += (displacementX > newdisplacementX) ? 1 : -2;
                std::cout << "Pressed L" << std::endl;

            } else if (inputString.at(i) == 'd') {
                yposition--;
                newdisplacementY = abs(yposition-oldGameBoard->getGoalLocation().getY());
                score += (displacementY > newdisplacementY) ? 1 : -2;
                std::cout << "Pressed D" << std::endl;

            } else if (inputString.at(i) == 'r') {
                xposition++;
                newdisplacementX = abs(xposition-oldGameBoard->getGoalLocation().getX());
                score += (displacementX > newdisplacementX) ? 1 : -2;
                std::cout << "Pressed R" << std::endl;

            } else if (inputString.at(i) == 'b') {
                std::cout << "Pressed B" << std::endl;

            } else if (inputString.at(i) == 'a') {
            	std::cout << "Pressed A" << std::endl;

            } else {
            	std::cout << "Error: Invalid Input. -1 Point." << std::endl;
                score--;
            }
            // End Input-Check


            // Begin Konami-Check
	    	if (GameLogic::containsKonamiCode(inputString) == 1 && oldGameBoard->isEnemy(Location(xposition, yposition)))
	    	{
	    		oldGameBoard->killEnemy(Location(xposition, yposition));
	    		std::cout << "Konami Code: You are Indestructable!" << std::endl;
	    		playerState = 0;
	    	}
	    	// End Konami-Check


    		// Begin Enemy-Check
	    	std::cout << "New Territory Danger?: " << oldGameBoard->isEnemy(Location(xposition, yposition)) << std::endl;
	    	if (oldGameBoard->isEnemy(Location(xposition, yposition)))
	    	{
	    		std::cout << "Enemy! Prepare to fight!!!" << std::endl;
	    		playerState = 1; // underAttack
	    	}
	    	// End Enemy-Check



	    	// Begin Treasure-Check
	    	std::cout << "Treasure Site?: " << oldGameBoard->isTreasure(Location(xposition, yposition)) << std::endl;
	    	if (oldGameBoard->isTreasure(Location(xposition, yposition)) == 1)
	    	{
	    		score += 10;
	    		std::cout << "Treasure Found! +10 Points!" << std::endl;
	    		oldGameBoard->removeTreasure(Location(xposition, yposition));
	    		std::cout << "Treasure Left: " << oldGameBoard->isTreasure(Location(xposition, yposition)) << std::endl;
	    	}
	    	// End Treasure-Check



	    	// Begin Information-Test
            std::cout << "Your Current Position is: (" << xposition << ", " << yposition << ") <----" << std::endl;
            std::cout << "Your Goal Position is   : (" << oldGameBoard->getGoalLocation().getX() << ", " << oldGameBoard->getGoalLocation().getY() << ")" << std::endl;
            std::cout << "Old Displacement: (" << displacementX << ", " << displacementY << ")" << std::endl;
            std::cout << "New Displacement: (" << newdisplacementX << ", " << newdisplacementY << ")" << std::endl;
            std::cout << "Score: " << score << " (" << ((score-oldScore) >= 0 ? "+":"") << score-oldScore << ")" << std::endl;
            std::cout << "********** End of Turn **********" << std::endl;
            // End Information-Test


            // Begin Result-Check
            bool positionAlignment = (xposition == oldGameBoard->getGoalLocation().getX() && yposition == oldGameBoard->getGoalLocation().getY());
            bool netNewDisplacement = (newdisplacementX == 0 && newdisplacementY == 0);
            if (netNewDisplacement == 1 && positionAlignment == 1)
    		{
	    		score += 100;
	    		std::cout << "You win! Your final score is: " << score << std::endl;
	    		std::cout << "=================================================" << std::endl;
	    		//xposition = 0;
	    		//yposition = 0;
	    		return score;
                std::cout << "You win! Your final score is: " << score << std::endl;
    		}

    		if (score <= 0)
    		{
	    		score = 0; 
	    		std::cout << "You Lost! Your final score is: " << score << std::endl;
	    		std::cout << "=================================================" << std::endl;
	    		//xposition = 0;
	    		//yposition = 0;
	    		return score;
    		}
    		// End Result-Check

    	} // End if (playerState == 0)

    	std::cout << std::endl;

    	if (playerState == 1) // underAttack
    	{
    		if (inputString.at(i) == 'a') 
    		{
            	oldGameBoard->killEnemy(Location(xposition, yposition));
            	std::cout << "Congratulations! You defeated an enemy!" << std::endl;
            	std::cout << "Pressed A" << std::endl;
            	std::cout << "Congrats Score: " << score << " (+0)" << std::endl; // No change
            	std::cout << "Your Current Position is: (" << xposition << ", " << yposition << ") <----" << std::endl;
            	std::cout << "********** End of Turn **********" << std::endl;
            	playerState = 0;
            } 

            else if (inputString.at(i) == 'u' || inputString.at(i) == 'd' || inputString.at(i) == 'l' || inputString.at(i) == 'r' || inputString.at(i) == 'b')
            {
                std::cout << "Error: Press A to fight!" << std::endl;
                std::cout << "Press A Score: " << score << " (+0)" << std::endl;
                std::cout << "Your Current Position is: (" << xposition << ", " << yposition << ") <----" << std::endl;
                std::cout << "********** End of Turn **********" << std::endl;
                // No movement
            }

            else {
            	score--;
                std::cout << "Error: Invalid Input. -1 Point." << std::endl; // Invalid Input (All chars != u,d,l,r,b,a)
                std::cout << "-1 Score: " << score << " (-1)" << std::endl;
                std::cout << "Your Current Position is: (" << xposition << ", " << yposition << ") <----" << std::endl;
                std::cout << "********** End of Turn **********" << std::endl << std::endl;
            }
    	} // End if (playerState == 1)

    } // End for (int i = 0; i < inputString.length(); ++i)

    // Begin End-Input Check
    std::cout << std::endl << std::endl << "No more moves! Your final score is: " << score << std::endl;
    std::cout << "=================================================" << std::endl;
    //xposition = 0;
    //yposition = 0;
    return score;
    // End End-Input Check

} // End int TreasureHunter::computeScore(std::string inputString)