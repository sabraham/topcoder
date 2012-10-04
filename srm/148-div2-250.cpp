#include <string>
#include <sstream>

class DivisorDigits
{
public:
  int howMany(int number)
  {
    std::string s;
    std::stringstream out;
    out << number;
    s = out.str();
    int n;
    int counter = 0;
    for (std::string::const_iterator it = s.begin(); it < s.end(); ++it)
      {
        n = *it - 48;
        if (n != 0 && number % n == 0) counter++;
      }
    return (counter);
  }
};
