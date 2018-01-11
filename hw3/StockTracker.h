#ifndef HW3_STOCKTRACKER_H
#define HW3_STOCKTRACKER_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional> 

using namespace std;

class StockTracker {
private:

public:

    StockTracker();
    std::map<std::string, int> registeredTicker;
    std::map<std::string, double> stockPrices;
    std::map<std::string, double> stockMarketCap;
    double marketCap = 0.0;
    std::vector<double> marketCapSort;
    std::vector<std::string> returnSorted;

    /*** part 1 ***/

    // Registers a stock by it's ticker symbol and gives the number of shares outstanding for that stock.
    // Shares outstanding is the total number of shares that exist for the stock. Your implementation should store this
    // information in a data structure of your choice. Since this is a set/map homework those are the intended
    // structures, but you are free to use any data structure you'd like.
    void registerTicker(string tickerSymbol, int sharesOutstanding);

    // Returns true if tickerSymbol has been registered, false otherwise
    bool isTicker(string tickerSymbol);

    // returns the number of shares outstanding for the stock corresponding to tickerSymbol. If the symbol has not
    // been registered, return 0.
    int getSharesOutstanding(string tickerSymbol);


    /*** part 2 ***/

    // Updates the current price of a share of stock corresponding to tickerSymbol. This information must be stored in
    // a data structure of your choosing. If the stock price was previously set, it must be updated. This function will
    // be called multiple times with the same tickerSymbol.
    void updateCurrentPrice(string tickerSymbol, double price);

    // Return the current price of the given stock. If the stock has not been registered or the price was
    // never set, return 0.0.
    double getCurrentPrice(string tickerSymbol);

    // Return the current market capitalization for the given tickerSymbol. Market capitalization is the current market
    // value of the company and can be computed by multiplying its price by its number of shares outstanding. If the
    // stock has not been registered or the price was never set, return 0.0.
    double getMarketCap(string tickerSymbol);


    /*** part 3 ***/

    // Return the ticker symbols of the k highest market cap stocks in order of their market cap. The highest market
    // cap stock should be in index 0 of the return vector, the second highest in index 1 and so on.
    vector<string> topMarketCaps(int k);


    /*** part 4 - efficiency ***/
    // void updateCurrentPrice(string tickerSymbol, double price);
    // vector<string> topMarketCaps(int k);
    //
    // These two functions must run in O(log(n)) time where n is the number of registered stocks. The runtime for
    // topMarketCaps can also depend linearly on k making its runtime O(k*log(n)).
    //
    // Each of these functions will be called repeatedly to check the runtime.
};


#endif //HW3_STOCKTRACKER_H
