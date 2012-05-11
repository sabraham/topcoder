#include <vector>
#include <algorithm>
using namespace std;

class Bonuses
{
private:
  struct bonus_pair
  {
    int pos;
    int bonus;
    int points;
    bool operator < (const bonus_pair& x) const
    {
      if (points == x.points) return pos < x.pos;
      else return points > x.points;
    }
  };
public:
  vector<int> getDivision(vector<int> points)
  {
    int total = 0;
    for (vector<int>::iterator it = points.begin();
	 it < points.end(); ++it) total += *it;
    vector<int> bonus;
    int left_over = 100;
    for (vector<int>::iterator it = points.begin();
	 it < points.end(); ++it)
      {
	bonus.push_back(*it*100/total);
	left_over -= *(bonus.end()-1);
      }
    int len = points.size();
    vector<bonus_pair> bonus_pairs;
    for (int i = 0; i < len; ++i)
      {
	bonus_pair x;
	x.pos = i;
	x.bonus = bonus[i];
	x.points = points[i];
	bonus_pairs.push_back(x);
      }
    sort(bonus_pairs.begin(), bonus_pairs.end());
    for (vector<bonus_pair>::iterator it = bonus_pairs.begin();
	 it < bonus_pairs.begin()+left_over ; ++it)
      bonus[it->pos] += 1;
    return bonus;
  }
};
