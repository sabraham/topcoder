#include <string>
#include <sstream>
#include <vector>
#include <regex.h>

class HowEasy
{
public:
  static int pointVal(std::string s)
  {
    int num_words = 0, words_length = 0;
    std::vector<std::string> words;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, ' ')) words.push_back(item);
    for (std::vector<std::string>::const_iterator it = words.begin();
	 it < words.end(); ++it)
      {
	regex_t exp;
	if(!regcomp(&exp, "^[:alpha:]+\\.?$", REG_EXTENDED))
	  {
	    words_length += (int) (*it).size();
	    ++num_words;
	  }
	regfree(&exp);
      }
    int avg = num_words > 0 ? words_length/num_words : 0;
    return avg <= 3 ? 250 : avg <= 5 ? 500 : 1000;
  }
};

int
main()
{
  return 0;
}
