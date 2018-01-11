#include <string>
#include "GameLogic.h"

/*
 *Returns whether or not the Konami Code was contained in the input
 */
bool GameLogic::containsKonamiCode(std::string inputFile){
    // TODO BEGINS
	bool result;

	if (inputFile.length() < 10)
	{
		std::cout << "String too short for Konami. Automatic Mortality." << std::endl;
		//std::cout << "Konami Code Active: " << result << std::endl; // Should return 0
		return false; 
	}

	for (int i = 0; i < inputFile.length()-9; ++i) // Minus 9 (Size of Konami Code)
	{
		bool ups     = (inputFile.at(i)  =='u' && inputFile.at(i+1)=='u');
		bool downs   = (inputFile.at(i+2)=='d' && inputFile.at(i+3)=='d');
		bool lefts   = (inputFile.at(i+4)=='l' && inputFile.at(i+6)=='l');
		bool rights  = (inputFile.at(i+5)=='r' && inputFile.at(i+7)=='r');
		bool buttonB = (inputFile.at(i+8)=='b');
		bool buttonA = (inputFile.at(i+9)=='a');

		bool result = ups && downs && lefts && rights && buttonB && buttonA;

		if (result == true)
		{
			//std::cout << "Konami Code Active: " << result << std::endl; // Should return 1
			return true;
		}
	}
	//std::cout << "Konami Code Active: " << result << std::endl; // Should return 0
    // END TODO
    return false;
}