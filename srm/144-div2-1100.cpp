#include <vector>

using namespace std;

class PowerOutage
{
public:
  int estimateTimeOut(vector<int> from_junction, vector<int> to_junction,
		      vector<int> duct_length)
  {
    int len = (int) from_junction.size();
    while (true)
      {
	bool graph_finished = true;
	for (int to = 0; to < len; ++to)
	  for (int from = 0; from < len; ++from)
	    {
	      if (duct_length[from] >= 0 && to_junction[to] == from_junction[from])
		{
		  to_junction[to] = to_junction[from];
		  duct_length[to] += duct_length[from];
		  duct_length[from] = -1;
		  graph_finished = false;
		}
	    }
	if (graph_finished) break;
      }
      int i_max = 0;
      for (int i = 0; i < len; ++i)
	if (duct_length[i] > duct_length[i_max]) i_max = i;
      int ret = 0;
      for (int i = 0; i < len; ++i)
	if (duct_length[i] > 0)
	  ret += (i == i_max) ? duct_length[i] : 2*duct_length[i];
      return ret;
  }
};
