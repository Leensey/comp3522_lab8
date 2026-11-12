#include "bidder.hpp"
#include "auctioneer.hpp"

void Bidder::update(Auctioneer *auctioneer) {
    // TODO: decide whether to retaliate with a new bid. Only bid if:
    //   - the new highest bid wasn't placed by this same bidder
    //   - this bidder's next bid (highest bid * bid_increase_perc) would not
    //     exceed its budget
    //   - a randomly generated probability roll succeeds, per bid_probability
    //     (see Lab-08.pptx on <random> / rand())
    // If all three hold, compute the new bid and call
    // auctioneer->accept_bid(new_bid, this).

    if (auctioneer->getHighestBidder() != this)
    {
        double new_bid = auctioneer->getHighestBid() * bid_increase_perc;

        if (new_bid <= budget)
        {
            double random_roll = (double)rand() / RAND_MAX * 100;

            if (random_roll < bid_probability)
            {
                cout << name << " bidded $" << new_bid;
                cout << " in response to " << 
                
                (((auctioneer->getHighestBidder()) == nullptr) ? "Starting bid"  : (auctioneer->getHighestBidder())->name ) 
                
                << "'s";
                cout << " bid of " << auctioneer->getHighestBid()<< endl;
                
                highest_bid = new_bid;
                auctioneer->accept_bid(new_bid, this);

            }
        }
    }
}
