#include <vector>
#include <algorithm>

using namespace std;

class GoldenChain
{
public:
  long minCuts(vector<int> sections)
  {
    int num_sec = sections.size();
    long num_links = 0, ret = 0, nxt_links;
    sort(sections.begin(), sections.end());
    for (int i = 0; ret == 0; ++i)
      {
	nxt_links = num_links + sections[i];
	if (nxt_links < num_sec - i - 1) num_links = nxt_links;
	else ret = num_sec - i - ((nxt_links == num_sec - i - 1) ? 1 : 0);
      }
    return ret;
  }
};
