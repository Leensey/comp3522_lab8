
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "bidder.hpp"
#include "auction.hpp"

using namespace std;

const double MIN_PROBABILITY = 0;
const double MAX_PROBABILITY = 100;

/*
Returns a random double in [min, max). See Lab-08.pptx for why rand()/RAND_MAX
is used here instead of hardcoding a probability.
*/
double generateRandom(double min, double max)
{
  double f = (double)rand() / RAND_MAX;
  return min + f * (max - min);
}

int main()
{
  srand(time(0));

  vector<Bidder *> bidders;

  // Preloaded test bidders.
  bidders.push_back(new Bidder("Jojo", 3000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.2));
  bidders.push_back(new Bidder("Melissa", 7000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.5));
  bidders.push_back(new Bidder("Priya", 15000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.1));
  bidders.push_back(new Bidder("Kewei", 800, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 1.9));
  bidders.push_back(new Bidder("Scott", 4000, generateRandom(MIN_PROBABILITY, MAX_PROBABILITY), 2));

  // TODO: prompt the user for the item name and starting price.
  string item;
  double start_price;

  cout << "Enter item name: " << endl;
  cin >> ws;
  getline(cin, item);

  cout << "Enter item starting price: " << endl;
  cin >> start_price;

  // TODO: give the user the option to either start the auction with just
  // the preloaded bidders above, or add more bidders first (prompting for
  // each new bidder's name, budget, bid_probability, and bid_increase_perc).

int choice;

cout << "Would you like to add more bidder." << endl;
cout << "Enter 0 for \"no\" and 1 for \"yes\"" << endl;
cin >> choice;

while (choice == 1)
{

    string name;
    double budget;
    double bid_probability;
    double bid_increase_perc;

  cout << "Enter bidder name" << endl;
  cin >> ws;
  getline(cin, name);

  cout << "Enter bidder budget" << endl;
  cin >> budget;

  cout << "Enter bidder bid probability" << endl;
  cin >> bid_probability;

  cout << "Enter bidder bid increase percentage" << endl;
  cin >> bid_increase_perc;

  bidders.push_back(new Bidder(name, budget, bid_probability, bid_increase_perc));

  cout << "Would you like to add more bidder." << endl;
  cout << "Enter 0 for \"no\" and 1 for \"yes\"" << endl;
  cin >> choice;

}

  Auction my_auction(bidders);
  my_auction.simulate_auction(item, start_price);

  for (Bidder *bidder : bidders)
  {
    delete bidder;
  }
  return 0;
}
