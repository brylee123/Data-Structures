#ifndef UNTITLED_TREASUREHUNTER_H
#define UNTITLED_TREASUREHUNTER_H

#include "GameBoard.h"


class TreasureHunter : public GameLogic  {
    private:
    	int xposition;
    	int yposition;
    	Location currentloc;
    	GameBoard* oldGameBoard;
        int score = 50;

    public:

        //The Params are the starting locations of the Hunter, x and y respectively
        TreasureHunter(int, int, GameBoard&);
        ~TreasureHunter();

        void changeBoard(GameBoard&);
        void changeBoard(GameBoard*);

        virtual int computeScore(std::string inputString);
};

#endif //UNTITLED_TREASUREHUNTER_H
