#ifndef HW2_FIREWORKFACTORY_H
#define HW2_FIREWORKFACTORY_H

#include <stack>
#include <queue>
#include <vector>

#include "Firework.h"

class FireworkFactory {

private:

    // TODO: Track quantities of metals
    // TODO: Track finished fireworks in the proper order
    std::queue<Firework*> saleInventory;
    // std::queue<Firework*> tempInventory;
    int orangeCounter = 0;
    int greenCounter = 0;
    int blueCounter = 0;
    int purpleCounter = 0;

public:
    FireworkFactory();

    // Point 1
    void fireworkShipment(stack<Firework*>&);
    void sellFireworks(stack<Firework*>&, int quantity);

    // Point 2
    void metalShipment(stack<Metal>&);
    ~FireworkFactory();

    // Point 3 for correctness, Point 4 for O(1) runtime
    void sellFireworks(stack<Firework*>&, int quantity, Color color);
};


#endif //HW2_FIREWORKFACTORY_H
