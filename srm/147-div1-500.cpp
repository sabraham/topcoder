#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull m, ull n)
{
  if (!m || !n) return 0;
  if (m < n)
    {
      m = m+n;
      n = m-n;
      m = m-n;
    }
  ull r = m % n;
  if (r == 0) return n;
  else return gcd(n, r);
}

ull lcm(ull m, ull n)
{
  ull t = gcd(m, n);
  return  t ? (m / gcd(m, n) * n) : 0;
}

class Dragons
{
private:
  int total_food;
  struct pair
  {
    ull n;
    ull d;
  };
  void initialize(vector<int> &initial_food, vector<pair> &food)
  {
    total_food = 0;
    for (vector<int>::const_iterator it = initial_food.begin();
	 it < initial_food.end(); it += 2)
      {
	pair x;
	x.n = *it + *(it+1);
	x.d = 1;
	food.push_back(x);
	total_food += x.n;
      }
  }
  void reduce(pair &x)
  {
    ull g = gcd(x.n, x.d);
    if (g)
      {
	x.n /= g;
	x.d /= g;
      }
    else x.d = 1;
  }
  pair addTwo(pair x, pair y)
  {
    ull m = lcm(x.d, y.d);
    x.n *= m / x.d;
    y.n *= m / y.d;
    pair z;
    z.n = x.n + y.n;
    z.d = m;
    reduce(z);
    return z;
  }
  pair add(pair *array[])
  {
    pair ret = *array[0];
    int i = 1;
    while (array[i]) ret = addTwo(ret, *array[i++]);
    return ret;
  }
  string translateResult(pair &answer)
  {
    stringstream out;
    out << answer.n;
    if (answer.d != 1) out << '/' << answer.d;
    string res;
    out >> res;
    return res;
  }
  void update(vector<pair> &new_food, vector<pair> &food, int box)
  {
    int i = 0;
    pair *array[3] = { NULL };
    for (int j = 0; j < 3; ++j)
      if (j != box) array[i++] = &food[j];
    pair update = add(array);
    new_food[box].n = update.n;
    new_food[box].d = update.d;
  }

public:
  string snaug(vector<int> initial_food, int rounds)
  {
    pair ans;
    if (rounds == 0)
      {
	ans.n = initial_food[2];
	ans.d = 1;
      }
    else
      {
	vector<pair> food;
	initialize(initial_food, food);
	vector<pair> new_food = food;
	for (int round = 0; round < rounds; ++round)
	  {
	    for (int i = 0; i < 3; ++i) food[i].d *= 2;
	    update(new_food, food, 0);
	    update(new_food, food, 1);
	    update(new_food, food, 2);
	    food = new_food;
	  }
	// values are twice what they should be, as each bin is actually two bins worth
	ans = food[1];
	ans.d *= 2;
      }
    reduce(ans);
    string ret = translateResult(ans);
    return ret;
  }
};
