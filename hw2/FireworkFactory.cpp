#include "FireworkFactory.h"

FireworkFactory::FireworkFactory(){
}

// Receive a stack of Firework pointers and add them to the factories inventory. Fireworks must be sold in the order
// that they are popped off the stack (The top of the stack is the oldest firework).
void FireworkFactory::fireworkShipment(stack<Firework*>& fireworkShipment){
    // TODO
    std::cout << "Test1: fireworkShipment | Official Starting Shipment Size: " << fireworkShipment.size() << std::endl;

    while(fireworkShipment.empty() != 1)
    {
		saleInventory.push(fireworkShipment.top());
		fireworkShipment.pop();
		// std::cout << "What is a firework?: " << fireworkShipment.top() << std::endl;
		// std::cout << "Top Firework: " << fireworkShipment.top() <<std::endl;
		// std::cout << "fireworkShipment Size: "<< fireworkShipment.size() << std::endl;
		// std::cout << "saleInventory Size: "<< saleInventory.size() << std::endl;
    }

    std::cout << "1.  fireworkShipment Size: "<< fireworkShipment.size() << std::endl;
	std::cout << "1.  saleInventory Size: "<< saleInventory.size() << std::endl;
    
    std::cout << "End Shipment and Inventory Update. Start Sales." << std::endl;

} // End FireworkFactory::fireworkShipment

// Sell quantity fireworks by pushing them onto the customerStack with the oldest fireworks being sold first (FIFO).
void FireworkFactory::sellFireworks(stack<Firework*>& customerStack, int quantity){

    std::cout << "Test2: sellFireworks | Official Quantity: " << quantity << "    Queue Size: " << saleInventory.size() << std::endl;
    
    // if (saleInventory.empty() && quantity > 0)
    /* if (saleInventory.size() < quantity)
	{
		std::cout << "Error: Inventory Empty!" << std::endl;
	}*/

	while (saleInventory.size() > 0 && quantity > 0)
	{
		std::cout << "Sale Inventory NOT Empty; Transfering Inventory to Customer." << std::endl;
		for (int i = 0; i < quantity; i++)
		{
	    	// std::cout << "Quantity: " << quantity << std::endl;
	    	customerStack.push(saleInventory.front());
	    	saleInventory.pop();
	    	quantity--;

	    	// std::cout << "customerStack Size: "<< customerStack.size() << std::endl;
			// std::cout << "saleInventory Size: "<< saleInventory.size() << std::endl;
            // std::cout << "*****************************" << std::endl;
		}
    }

    std::cout << "2.  saleInventory Size: "<< saleInventory.size() << std::endl;
    std::cout << "2.  customerStack Size: "<< customerStack.size() << std::endl;

    std::cout << "End Customer Transaction. Back to Shipment." << std::endl; 
} // FireworkFactory::sellFireworks

// Before destroying the factory you must properly dispose of all the fireworks in your inventory (On the heap).
FireworkFactory::~FireworkFactory(){
    // TODO
    while(!saleInventory.empty())
    {
        delete saleInventory.front();
    	saleInventory.pop();
    }
    std::cout << "Deleted saleInventory." << std::endl;

} // End FireworkFactory::~FireworkFactory

// Receive a shipment of metal which will be used to make new fireworks in the factory. Whenever the factory has 5 of
// any type of metal it must immediately make a firework of the corresponding color and add it to the inventory.
// To make a firework, you must use the new keyword to create it dynamically on the heap and manage a pointer to
// the firework.
void FireworkFactory::metalShipment(stack<Metal>& metalShipment){
    // TODO 
    std::cout << "metalShipment Incoming." << std::endl;

    while(!metalShipment.empty())
    {
        std::cout << "metalShipment.top: *" << metalShipment.top() << std::endl;
    	orangeCounter += (metalShipment.top() == 0)	? 1:0;
    	greenCounter  += (metalShipment.top() == 1)	? 1:0;
    	blueCounter   += (metalShipment.top() == 2)	? 1:0;
    	purpleCounter += (metalShipment.top() == 3)	? 1:0;
    	//std::cout << "orangeCounter: " << orangeCounter << "   " << ((metalShipment.top() == 0) ? "+1":"") << std::endl;
    	//std::cout << "greenCounter:  " << greenCounter  << "   " << ((metalShipment.top() == 1) ? "+1":"") << std::endl;
        //std::cout << "blueCounter:   " << blueCounter   << "   " << ((metalShipment.top() == 2) ? "+1":"") << std::endl;
        //std::cout << "purpleCounter: " << purpleCounter << "   " << ((metalShipment.top() == 3) ? "+1":"") << std::endl;

    	// std::cout << "Top Metal Color: " << metalShipment.top() << std::endl;

    	if (orangeCounter == 5)
    	{
    		Firework* orangefireworkPointer = new Firework(Orange);
    		std::cout << "fireworkPointer:  " << orangefireworkPointer << " (Pushed Orange)" << std::endl;
    		saleInventory.push(orangefireworkPointer);
    		orangeCounter = 0;
    	}

    	if (greenCounter == 5)
    	{
    		Firework* greenfireworkPointer = new Firework(Green);
    		std::cout << "fireworkPointer:  " << greenfireworkPointer << " (Pushed Green)" << std::endl;
    		saleInventory.push(greenfireworkPointer);
    		greenCounter = 0;
    	}

    	if (blueCounter == 5)
    	{
    		Firework* bluefireworkPointer = new Firework(Blue);
    		std::cout << "fireworkPointer:  " << bluefireworkPointer << " (Pushed Blue)" << std::endl;
    		saleInventory.push(bluefireworkPointer);
    		blueCounter = 0;
    	}

    	if (purpleCounter == 5)
    	{
    		Firework* purplefireworkPointer = new Firework(Purple);
    		std::cout << "fireworkPointer:  " << purplefireworkPointer << " (Pushed Purple)" << std::endl;
    		saleInventory.push(purplefireworkPointer);
    		purpleCounter = 0;
    	}

        metalShipment.pop();

        std::cout << "Inventory Bottom: " << saleInventory.back() << std::endl;
        // std::cout << "saleInventory.size(): " << saleInventory.size() << std::endl;

        std::cout << "----- End Shipment Count ----- " << std::endl;
    } // End for loop metalShipment.size()

} // End FireworkFactory::metalShipment

// A customer is purchasing quantity fireworks, but they must all be of the color specified by the customer. The order
// in which the fireworks are sold must be maintained (FIFO), but fireworks of the specified color can be sold before
// other colors if there is no other way to fulfil the order. Be sure not to sell the same firework more than once with
// either of the sellFireworks functions.
//
// For the efficient point of this assignment, this function must run in O(quantity) time. If only 1 firework is being
// purchased, the runtime must be O(1) regardless of where the firework to be sold is in the inventory.
void FireworkFactory::sellFireworks(stack<Firework*>& customerStack, int quantity, Color color){
    // TODO
    queue<Firework*> tempInventory;

    //while (!saleInventory.empty())
    for (int i = 0; i < saleInventory.size(); i++)
    {
        std::cout << "saleInventory.size(): " << saleInventory.size() << std::endl;

        if ((saleInventory.front()->getColor() == color) && quantity > 0)
        {
            customerStack.push(saleInventory.front());
            saleInventory.pop();
            quantity--;
            std::cout << "Matched:     " << quantity << "    " << color << "    " << saleInventory.front() << std::endl;
        }

        else if ((saleInventory.front()->getColor() == color) && quantity <= 0)
        {
            tempInventory.push(saleInventory.front());
            saleInventory.pop();
            std::cout << "Match !Want: " << quantity << "    " << color << "    " << saleInventory.front() << std::endl;
        }

        else if ((saleInventory.front()->getColor()) != color)
        {
            tempInventory.push(saleInventory.front());
            saleInventory.pop();
            std::cout << "No Match:    " << quantity << "    " << color << "    " << saleInventory.front() << std::endl;
        }
    }

    saleInventory = tempInventory;
    
    while(!tempInventory.empty())
    {
        tempInventory.pop();
    }

    std::cout << "tempInventory.empty FINAL: " << tempInventory.empty() << std::endl;

}























