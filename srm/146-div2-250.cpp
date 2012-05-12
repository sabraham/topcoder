#include <vector>

using namespace std;

class YahtzeeScore
{
public:
  int maxPoints(vector<int> toss)
  {
    int ret = 0;
    int poss[6] = {0};
    for (int i = 0; i < 5; ++i) poss[toss[i]-1] += toss[i];
    for (int i = 0; i < 6; ++i) if (poss[i] > ret) ret = poss[i];
    return ret;
  }
};
