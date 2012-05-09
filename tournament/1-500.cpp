#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <cstring>

class SquareDigits
{
public:
  int smallestResult(int n)
  {
    int x = 0;
    while (true)
      {
	std::vector<int> T;
	int num = x;
	while (std::find(T.begin(), T.end(), num) == T.end())
	  {
	    T.push_back(num);
	    int sum = 0;
	    std::stringstream out;
	    out << num;
	    {
	      const std::string &temp = out.str();
	      const char* num_str = temp.c_str();
	      int i = 0;
	      while(num_str[i])
		{
		  char d[1];
		  strncpy(d, num_str+(i++), 1);
		  int digit = atoi(d);
		  sum += digit*digit;
		}
	    }
	    num = sum;
	    if (num == n) return x;
	  }
	++x;
      }
  }
};


int
main()
{
  SquareDigits res;
  return 0;
}
