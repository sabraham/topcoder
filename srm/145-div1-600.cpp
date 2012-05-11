#include <vector>
#include <string>
#include <sstream>

using namespace std;

class VendingMachine
{
private:
  struct col
  {
    vector<int> prices;
    vector<bool> purchased;
    int cost;
  };
  struct purchase
  {
    int col;
    int shelf;
    unsigned int time;
  };
  int current_pos;
  unsigned int current_time;
  int most_expensive;
  int num_col;
  vector<int> split(const string &s, char sep)
  {
    vector<int> pieces;
    stringstream temp(s);
    string piece_str;
    while(getline(temp, piece_str, sep))
      {
	stringstream convert(piece_str);
	int piece;
	convert >> piece; 
	pieces.push_back(piece);
      }
    return pieces;
  }
  vector<col> parse_prices(vector<string> prices)
  {
    vector<int> shelf = split(prices[0], ' ');
    num_col = shelf.size();
    vector<col> machine;
    for (int i = 0; i < num_col; ++i)
      {
	col c;
	c.cost = 0;
	machine.push_back(c);
      }
    for (vector<string>::iterator it = prices.begin();
	 it < prices.end(); ++it)
      {
	shelf = split(*it, ' ');
	for (int i = 0; i < num_col; ++i)
	  {
	    machine[i].prices.push_back(shelf[i]);
	    machine[i].purchased.push_back(false);
	    machine[i].cost += shelf[i];
	  }
      }
    // built machine: machine[i].X[j] = ith col, jth shelf
    return machine;
  }
  vector<purchase> parse_purchases(vector<string> purchases)
  {
    vector<purchase> ret;
    for (vector<string>::iterator it = purchases.begin();
	 it < purchases.end(); ++it)
      {      
	stringstream out(*it);
	string piece;
	getline(out, piece, ',');
	int shelf;
	stringstream temp(piece);
	temp >> shelf;
	temp.clear();
	temp.str("");
	getline(out, piece, ':');
	int column;
	temp << piece;
	temp >> column;
	unsigned int time;
	out >> time;
	purchase p;
	p.col = column;
	p.shelf = shelf;
	p.time = time;
	ret.push_back(p);
      }
    return ret;
  }
  // sets most expensive column to most_expensive
  void calcMostExpensive(vector<col> &machine)
  {
    int ret = 0;
    for (int i = 0; &machine[i] != &*machine.end(); ++i)
      if (machine[i].cost > machine[ret].cost) ret = i;
    most_expensive = ret;
  }
  int calcTurnTime(int from, int to, int num_col)
  {
    int delta = (from >= to) ? from - to : to - from;
    return (delta < num_col - delta) ? delta : num_col - delta;
  }
  // subtract delta from total cost of column col
  void adjustCost(vector<col> &machine, int col, int delta)
  {
    machine[col].cost -= delta;
  }
public:
  int motorUse(vector<string> prices, vector<string> purch)
  {
    int ret = 0;
    current_time = 0;
    vector<col> machine = parse_prices(prices);
    vector<purchase> purchases = parse_purchases(purch);
    // initialize turn
    current_pos = 0;
    calcMostExpensive(machine);
    int turn_time = calcTurnTime(0, most_expensive, num_col);
    ret += turn_time;
    // current_time += turn_time;
    current_pos = most_expensive;
    for (vector<purchase>::const_iterator it = purchases.begin();
	 it < purchases.end(); ++it)
      {
	// time elapses, moves to most expensive
	if (it->time - current_time >= 5)
	  {
	    turn_time = calcTurnTime(current_pos, most_expensive, num_col);
	    ret += turn_time;
	    current_pos = most_expensive;
	  }
	// incorrect simulation: person purchases empty item
	if (machine[it->col].purchased[it->shelf] == true) return -1;
	// correct simulation: person purchases present item
	turn_time = calcTurnTime(current_pos, it->col, num_col);
	ret += turn_time;
	current_time = it->time;
	machine[it->col].purchased[it->shelf] = true;
	adjustCost(machine, it->col, machine[it->col].prices[it->shelf]);
	calcMostExpensive(machine);
	current_pos = it->col;
      }
    turn_time = calcTurnTime(current_pos, most_expensive, num_col);
    ret += turn_time;
    return ret;
  }
};

int
main()
{
  return 0;
}
