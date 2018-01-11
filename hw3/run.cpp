#include <iostream>

#include "StockTracker.h"

using namespace std;

void sampleUsage();


int main() {
    sampleUsage();
    return 0;
}

void sampleUsage() {

    // This is what we typically put in a run.cpp. It is by no means comprehensive testing. It is just enough to give a
    // a sample of how each function is called.
    //
    // Please note the significant difference between this and test cases!
    //

    StockTracker tracker;

    tracker.registerTicker("StockA", 100);
    tracker.registerTicker("StockB", 100);
    tracker.registerTicker("StockC", 100);
    tracker.registerTicker("StockD", 100);

    tracker.isTicker("StockA"); // return true
    tracker.isTicker("StockB"); // return true
    tracker.isTicker("StockC"); // return true
    tracker.isTicker("StockD"); // return true

    tracker.isTicker("StockE"); // return false
    tracker.isTicker("stockC"); // return false
    tracker.isTicker("Stocka"); // return false
    tracker.isTicker("GOOG"); // return false

    tracker.getSharesOutstanding("StockA"); // return 100
    tracker.getSharesOutstanding("StockB"); // return 200
    tracker.getSharesOutstanding("StockC"); // return 300
    tracker.getSharesOutstanding("StockD"); // return 200
    tracker.getSharesOutstanding("StockE"); // return 0

    tracker.updateCurrentPrice("StockA", 10.0);
    tracker.updateCurrentPrice("StockA", 10.2);
    tracker.updateCurrentPrice("StockA", 10.3);
    tracker.getCurrentPrice("StockA"); // return 10.3
    tracker.updateCurrentPrice("StockA", 11.6);
    tracker.getCurrentPrice("StockA"); // return 11.6
    tracker.updateCurrentPrice("StockB", 5.25); 
    tracker.getCurrentPrice("StockB"); // return 5.25
    tracker.getCurrentPrice("StockC"); // return 0.0

    tracker.getMarketCap("StockA"); // return 1160.0
    tracker.getMarketCap("StockB"); // return 1050.0
    tracker.getMarketCap("StockC"); // return 0.0
    tracker.getMarketCap("StockD"); // return 0.0
    tracker.getMarketCap("StockE"); // return 0.0


    tracker.topMarketCaps(1); // return vector with vector.at(0) == "StockA"
    tracker.topMarketCaps(2); // return vector with vector.at(0) == "StockA" and vector.at(1) == "StockB"


    // To get the 4th point, your code must be able to handle ties in market cap
    // register IPO1 100
    // register IPO2 200
    // register IPO3 500
    // set price IPO1 20.0
    // set price IPO2 10.0
    // set price IPO3 2.0

    // top 2 must return IPO1 and IPO2. The order doesn't matter since they are tied

}