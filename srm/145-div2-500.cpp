#include <string>
#include <sstream>
#include <vector>

using namespace std;

class ExerciseMachine
{
private:
  void split(string time, vector<string> &ret)
  {
    stringstream s(time);
    string piece;
    while (getline(s, piece, ':')) ret.push_back(piece);
  }
  void toInt(vector<string> &s, vector<int> &ret)
  {
    stringstream ss("");
    for(vector<string>::const_iterator it = s.begin();
	it < s.end(); ++it)
      {
	ss << *it;
	int out;
	ss >> out;
	ret.push_back(out);
	ss.clear();
	ss.str("");
      }
  }
  long getSeconds(vector<int> &s)
  {
    return 3600 * (long) s[0] + 60 * s[1] + s[2];
  }
public:
  int getPercentages(string time)
  {
    int ret = 0;
    vector<string> time_split;
    split(time, time_split);
    vector<int> time_int;
    toInt(time_split, time_int);
    long sec = getSeconds(time_int);
    for (int i = 1; i < 100; ++i)
      if (sec*i % 100 == 0) ret += 1;
    return ret;
  }
};
