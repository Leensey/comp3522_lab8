#include "auction.hpp"
#include <iostream>

using namespace std;

Auction::Auction(vector<Bidder *> bidders) 
{
    // TODO: register every bidder with this auction's auctioneer.
    for(auto& b : bidders)
    {
        auctioneer.register_bidder(b);
    }
}

void Auction::simulate_auction(string item, double start_price) 
{
    // TODO: announce the item and starting price, then place the opening
    // bid via auctioneer.accept_bid(start_price) to kick off the chain of
    // notifications (see README for the observer flow this triggers).
    // Once the chain settles, print the winner (auctioneer's highest
    // bidder/bid) and a per-bidder summary of each bidder's highest bid.
    cout << "Starting Auction!!" << endl << "------------------" << endl 
        << "Auctioning " + item + " at starting price " << start_price << endl;

    auctioneer.accept_bid(start_price, nullptr);

    cout << "The " + item + " goes to " << auctioneer.getHighestBidder() << " for " << auctioneer.getHighestBid() << endl;

    auctioneer.printBidders();
    auctioneer.reset_auctioneer();
}
