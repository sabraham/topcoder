#include <string>
#include <vector>

using namespace std;

class ImageDithering
{
  int count(string dithered, vector<string> screen)
  {
    int ret = 0;
    for (vector<string>::const_iterator it = screen.begin();
	 it < screen.end(); ++it)
      for(string::const_iterator pix = it->begin(); pix < it->end(); ++pix)
	if (dithered.find(*pix) != string::npos) ret += 1;
    return ret;
  }
};
