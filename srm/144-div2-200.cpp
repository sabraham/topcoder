#include <string>
#include <sstream>

class Time
{
public:
  string whatTime(unsigned int seconds)
  {
    unsigned int hours = seconds / 3600;
    unsigned int minutes = (seconds - hours*3600) / 60;
    unsigned int secs = seconds - hours*3600 - minutes*60;
    stringstream out;
    string ret;
    out << hours << ":" << minutes << ":" << secs;
    out >> ret;
    return ret;
  }

};
