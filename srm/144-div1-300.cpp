// Solution to TopCoder SRM 144
// Sunil Abraham

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

class BinaryCode
{
public:
  // message = coded binary string, ie "0110.."
  // binary original P is coded as Q where
  // Q[i] = P[i-1] + P[i] + P[i+1]
  vector<string> decode(string message)
  {
    int n = message.length();
    int Q[n+2], P[n+2];
    vector<string> ret;
    Q[0] =  Q[n+1] =  P[0] = P[n+1] = 0;
    // read message into Q
    for (int i = 0; i < n; ++i)
      {
	stringstream s(message.substr(i, 1));
	s >> Q[i+1];
      }
    // analysis
    for (int p1 = 0; p1 < 2; ++p1)
    {
      bool poss = true;
      P[1] = p1;
      for (int i = 2; i < n+1; ++i)
	{
	  P[i] = Q[i-1] - P[i-1] - P[i-2];
	  if (P[i] > 1 || P[i] < 0)
	    {
	      poss = false;
	      break;
	    }
	}
      if (poss)
	// check if coding forward gets decoding backward
	// quick hack for invalid Qs, eg, Q = "3"
	for (int i = 1; i < n+1; ++i)
	  if (Q[i] != P[i-1] + P[i] + P[i+1])
	    {
	      poss = false;
	    }
      if (!poss)
	{
	  ret.push_back("NONE");
	  continue;
	}
      // decoding is in array. join into string.
      stringstream p;
      for (int i = 1; i < n+1; ++i) p << P[i];
      ret.push_back(p.str());
    }
    return ret;
  }
};
