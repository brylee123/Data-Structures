#include "StockTracker.h"

StockTracker::StockTracker(){}

void StockTracker::registerTicker(string tickerSymbol, int sharesOutstanding){
    // TODO
    // registeredTicker[tickerSymbol] = sharesOutstanding;
	registeredTicker.insert(std::pair<std::string, int> (tickerSymbol, sharesOutstanding));
	stockPrices.insert(std::pair<std::string, double> (tickerSymbol, 0.0));
    std::cout << "Ticker Symbol:      " << tickerSymbol << std::endl;
    std::cout << "Shares Outstanding: " << sharesOutstanding << std::endl;
}

bool StockTracker::isTicker(std::string tickerSymbol){
    // TODO
	std::map<string, int>::iterator it;
	it = registeredTicker.find(tickerSymbol);

	if (it != registeredTicker.end()) // Match
	{
		std::cout << tickerSymbol << ": Return 1" << std::endl;
		std::cout << "--------------------" << std::endl;
		return 1;
	}
	else // No Match
	{
		std::cout << tickerSymbol << ": Return 0" << std::endl;
		std::cout << "--------------------" << std::endl;
		return 0; 
	}

	// return 0; // Temporary Warning Inhibitor // Update: Finalized Deletion
}

int StockTracker::getSharesOutstanding(string tickerSymbol){
    // TODO
	std::map<string, int>::iterator it;
	it = registeredTicker.find(tickerSymbol);

	if (it != registeredTicker.end()) // Match
	{
		std::cout << tickerSymbol << ": Return " << registeredTicker.find(tickerSymbol)->second << std::endl;
		std::cout << "====================" << std::endl;
		return (registeredTicker.find(tickerSymbol)->second);
	}
	else // No Match
	{
		std::cout << tickerSymbol << ": Return 0" << std::endl;
		std::cout << "====================" << std::endl;
		return 0; 
	}
    // return 0; // Temporary Warning Inhibitor // Update: Finalized Deletion
}


void StockTracker::updateCurrentPrice(string tickerSymbol, double price){
    // TODO
    if (price != stockPrices.find(tickerSymbol)->second)
    {
	    stockPrices.erase(tickerSymbol);
	    stockPrices.insert(std::pair<std::string, double> (tickerSymbol, price));
	    std::cout << "Ticker Symbol: " << tickerSymbol << std::endl;
	    std::cout << "Stock Price:   $" << price << std::endl;
	    std::cout << "********************" << std::endl;
    }

    else
    {
    	stockPrices.insert(std::pair<std::string, double> (tickerSymbol, price));
	    std::cout << "Ticker Symbol: " << tickerSymbol << std::endl;
	    std::cout << "Stock Price:   $" << price << std::endl;
	    std::cout << "********************" << std::endl;
    }
    // Make sure Stock C and D are priced at $0.0

}

double StockTracker::getCurrentPrice(string tickerSymbol){
    // TODO
	std::map<string, double>::iterator it;
	it = stockPrices.find(tickerSymbol);

    if (it != stockPrices.end()) // Match
	{
		std::cout << tickerSymbol << ": Return $" << stockPrices.find(tickerSymbol)->second << std::endl;
		std::cout << "####################" << std::endl;
		return (stockPrices.find(tickerSymbol)->second);
	}

	else // No Match
	{
		std::cout << tickerSymbol << ": Return $" << stockPrices.find(tickerSymbol)->second << std::endl;
		std::cout << "####################" << std::endl;
		return 0; 
	}
    return 0.0; // Temporary Warning Inhibitor
}

double StockTracker::getMarketCap(string tickerSymbol){
    // TODO
	std::map<string, double>::iterator it;
	it = stockPrices.find(tickerSymbol);

    if (it != stockPrices.end()) // Match
	{
		marketCap = (stockPrices.find(tickerSymbol)->second)*(registeredTicker.find(tickerSymbol)->second);
		std::cout << "*** tickerSymbol *** :" << tickerSymbol << std::endl;
		std::cout << "Stock Price:        $" << stockPrices.find(tickerSymbol)->second << std::endl;
		std::cout << "Outstanding Shares:  " << registeredTicker.find(tickerSymbol)->second << std::endl;
		std::cout << "Market Cap:         $" << marketCap << std::endl;
		std::cout << "++++++++++++++++++++" << std::endl;
	}

	else // No Match
	{
		marketCap = 0.0;
		std::cout << "*** tickerSymbol *** : " << tickerSymbol << std::endl;
		std::cout << "Stock Price:        Not Registered" << std::endl;
		std::cout << "Outstanding Shares: Not Registered " << std::endl;
		std::cout << "Market Cap:         $" << marketCap << std::endl;
		std::cout << "++++++++++++++++++++" << std::endl;
		return marketCap;
	}

	stockMarketCap.insert(std::pair<std::string, int> (tickerSymbol, marketCap));
	marketCapSort.push_back(marketCap);

    return marketCap; // Temporary Warning Inhibitor
}


vector<string> StockTracker::topMarketCaps(int k){
    // TODO
    if (returnSorted.empty() != 1) {
    	returnSorted.clear();
    }

	std::sort(marketCapSort.begin(), marketCapSort.end(), std::greater<int>()); // Sorting Vector

	// std::cout << marketCapSort.at(0) << "   " << marketCapSort.at(1) << std::endl;

	for (int i = 0; i < k; i++)
	{ // Iterate through 0 -> k (size)
		int j = 0;

		for (std::map<std::string,double>::iterator it = stockMarketCap.begin(); it != stockMarketCap.end(); ++it)
		{ // Iterate through stockMarketCap (tickerSymbol, marketCap)

			std::cout << "Loop #" << i << "." << j << "     int k value: " << k << std::endl;
			
			std::cout << it->first << " => " << it->second << std::endl;

			if (it->second == marketCapSort.at(i)  && it->second > 0) // Make sure they pair up // !=0 to weed out empty stocks
			{
				returnSorted.push_back(it->first);

				std::cout << "returnSorted Size: "<< returnSorted.size() << std::endl;
				std::cout << "MATCH! Printing returnSorted: " << returnSorted.at(i) << std::endl;
				std::cout << std::endl;
			}

			j+=1;
			std::cout << "===== End Loop =====" << std::endl;
		}
		std::cout << "**********************************************" << std::endl;
	}

	for (int i = 0; i < returnSorted.size(); i++)
	{
		std::cout << "@@ Printing FINAL returnSorted: " << returnSorted.at(i) << std::endl;
	}

	std::cout << "**************** END OF PRINT ****************" << std::endl;
	std::cout << std::endl;


    return returnSorted;

}