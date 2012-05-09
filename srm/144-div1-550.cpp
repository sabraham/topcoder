#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Lottery
{
private:
  long long ipow (int base, int exp)
  {
    long long res = 1;
    while (exp)
      {
	if (exp & 1) res *= base;
	exp >>= 1;
	base *= base;
      }
    return res;
  }
  long long rev_fact (int base, int depth)
  {
    long long res = 1;
    for (int i = 0; i < depth; ++i)
      {
	res *= base-i;
      }
    return res;
  }

  long long bin (int n, int k)
  {
    long long res = 1;
    if (n-k < k) k = n-k;
    for (int c = 0; c < k; ++c)
      {
	res *= n-c;
	res /= c+1;
      }
    return res;
  }
  
public:
  struct lot
  {
    string name;
    long long poss;
    bool operator < (const lot& x) const
    {
      if (poss == x.poss) return name < x.name;
      else return poss < x.poss;
      
    }
  };
  vector<string> sortByOdds(vector<string> rules)
  {
    int choices, blanks;
    long long possibilities;
    bool sorted, unique;
    vector<lot> lotteries;

    for (vector<string>::iterator it = rules.begin();
	 it < rules.end(); ++it)
      {
	string name;
	stringstream out(*it);
	getline(out, name, ':');
	out >> choices >> blanks;
	{
	  char sort_flag, uniq_flag;
	  out >> sort_flag >> uniq_flag;
	  sorted = (sort_flag == 'T') ? true : false;
	  unique = (uniq_flag == 'T') ? true : false;
	}

	if (!sorted && !unique) possibilities = ipow(choices, blanks);
	else if (sorted && !unique) possibilities = bin(choices+blanks-1, blanks);
	else if (!sorted && unique) possibilities = rev_fact(choices, blanks);
	else possibilities = bin(choices, blanks);
	lot lott;
	lott.name = name;
	lott.poss = possibilities;
	lotteries.push_back(lott);
      }
    sort(lotteries.begin(), lotteries.end());
    vector<string> res;
    for (vector<lot>::iterator it = lotteries.begin();
	 it < lotteries.end(); ++it) res.push_back(it->name);
    return res;
  }
};

#include <iostream>

int
main()
{
  vector<string> test1;
  test1.push_back("PICK ANY TWO: 10 2 F F");
  test1.push_back("PICK TWO IN ORDER: 10 2 T F");
  test1.push_back("PICK TWO DIFFERENT: 10 2 F T");
  test1.push_back("PICK TWO LIMITED: 10 2 T T");
  vector<string> test2;
  test2.push_back("INDIGO: 93 8 T F");
  test2.push_back("ORANGE: 29 8 F T");
  test2.push_back("VIOLET: 76 6 F F");
  test2.push_back("BLUE: 100 8 T T");
  test2.push_back("RED: 99 8 T T");
  test2.push_back("GREEN: 78 6 F T");
  test2.push_back("YELLOW: 75 6 F F");
  vector<string> test3;
  
  Lottery test;
  vector<string> out = test.sortByOdds(test1);
  for (vector<string>::iterator it = out.begin(); it < out.end(); ++it) cout << *it << endl;
  out = test.sortByOdds(test2);
  for (vector<string>::iterator it = out.begin(); it < out.end(); ++it) cout << *it << endl;
  
  return 0;
}



