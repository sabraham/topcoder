#include <string>
#include <map>

using namespace std;

class CircleGame
{
public:
  int cardsLeft (string deck)
  {
    int current, next;
    string ret;
    map<char, int> card_map = makeCardMap();
    for (string::const_iterator it = deck.begin(); it < deck.end() - 1; it++)
      {
        current = card_map[*it];
        next = card_map [*(it+1)];
        if (current == 13);
        else if (current + next == 13) it++;
        else ret.push_back(*it);
      }
    current = card_map[*(deck.end() - 1)];
    next = card_map[*deck.begin()];
    if (current == 13);
    else if (current + next == 13) ret.erase(0, 1);
    else ret.push_back(*(deck.end() - 1));
    if (deck.size() == ret.size() || ret.size() == 0) return(ret.size());
    else return(cardsLeft(ret));
  }
 private:
  map<char, int> makeCardMap ()
  {
    map<char, int> card_map;
    card_map ['A'] = 1;
    card_map ['2'] = 2;
    card_map ['3'] = 3;
    card_map ['4'] = 4;
    card_map ['5'] = 5;
    card_map ['6'] = 6;
    card_map ['7'] = 7;
    card_map ['8'] = 8;
    card_map ['9'] = 9;
    card_map ['T'] = 10;
    card_map ['J'] = 11;
    card_map ['Q'] = 12;
    card_map ['K'] = 13;
    return (card_map);
  }
};
