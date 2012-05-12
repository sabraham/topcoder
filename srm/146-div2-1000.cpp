#include <vector>
#include <algorithm>
using namespace std;

class BridgeCrossing
{
public:
  int minTime(vector<int> times)
  {
    int ret;
    sort(times.begin(), times.end());
    int num_people = times.size();
    if (num_people <= 2) ret = times[num_people-1];
    else if (num_people == 3)
      {
	vector<int> reduced(times.begin(), times.end()-1);
	ret = times[0] + times[2] + minTime(reduced);
      }
    else
      {
	vector<int> reduced(times.begin(), times.end()-2);
	ret = times[0] + 2*times[1] + times[num_people-1] + minTime(reduced);
      }
    return ret;
  }
};
