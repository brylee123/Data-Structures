#include <iostream>

#include "GameBoard.h"
#include "TreasureHunter.h"

using namespace std;

int main() {
    Location goalLocation(5, 7);
    GameBoard board(goalLocation);
    board.addTreasure(Location(8, 9));
    board.addTreasure(Location(-3, 6));
    board.addTreasure(Location(12, -1));

    board.addEnemy(Location(5, 6));
    board.addEnemy(Location(4, 7));


    cout << "Expect true: " << board.isTreasure(Location(8,9)) << endl;
    cout << "Expect true: " << board.isTreasure(Location(-3,6)) << endl;
    cout << "Expect true: " << board.isTreasure(Location(12,-1)) << endl;
    cout << "Expect true: " << board.isEnemy(Location(5,6)) << endl;
    cout << "Expect true: " << board.isEnemy(Location(4,7)) << endl;

    board.killEnemy(Location(5,6));
    board.removeTreasure(Location(-3,6));

    cout << "Expect false: " << board.isTreasure(Location(-3,6)) << endl;
    cout << "Expect false: " << board.isTreasure(Location(-2,6)) << endl;
    cout << "Expect false: " << board.isTreasure(Location(12,1)) << endl;
    cout << "Expect false: " << board.isEnemy(Location(5,6)) << endl;
    cout << "Expect false: " << board.isEnemy(Location(43,7)) << endl;

    cout << "Goal Location: (" << board.getGoalLocation().getX() << ", " << board.getGoalLocation().getY() << ")" <<endl;

    TreasureHunter treasureHunter(0, 0, board);

    // try different userInput strings by changing this value

    // string userInput = "udasdflkasdlfjuuddlrlrbaasdifjaweoifjewifuhweifuwehfiuwehfiewhfwuefheuwifhweufidlrrab";
    // string userInput = "udasdflkasdab";
    // string userInput = "uddlrrab";
    // string userInput = "rrrrruuuuuuu";
    // string userInput = "u";
    // string userInput = "valencia";
    // string userInput = "ababababababa";
    // string userInput = "qqqqqqqqqqqqqqqqqqqqqqqqqqq";
    string userInput = "udlaldubbbdaaarudiiodllaaabdlrlruuddlrlrba";
    // string userInput = "rrruuddlrlrbauuuudddaruuuuuuururrrldlld";
    // string userInput = "udlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlrudlr";

    cout << (treasureHunter.containsKonamiCode(userInput) ? "Found code" : "No code entered");
    cout << endl;
    cout << "=================================================" << endl;
    cout << "\nScore with old board is: " << treasureHunter.computeScore(userInput) << endl;
    cout << "=================== OLD BOARD ===================" << endl;

    Location newGoalLocation(-1, 3);
    GameBoard newBoard(newGoalLocation);
    newBoard.addTreasure(Location(0, 2));
    newBoard.addTreasure(Location(-10, 8));
    newBoard.addTreasure(Location(3, 12));

    newBoard.addEnemy(Location(-1, 1));
    newBoard.addEnemy(Location(5, 2));

    treasureHunter.changeBoard(newBoard);
    treasureHunter.changeBoard(&newBoard);

    cout << "\nScore with new board is: " << treasureHunter.computeScore(userInput) << endl;
    cout << "=================== NEW BOARD ===================" << endl;

    cout << endl;

    return 0;
}
