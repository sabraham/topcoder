#include <string>
#include <vector>
#include <map>

using namespace std;

class CeyKaps
{
public:
  string decipher (string typed, vector <string> switches)
  {
    string ret;
    map<char, char> key_map = makeMap(switches);
    for (string::const_iterator it = typed.begin(); it < typed.end(); ++it)
      {
        if (key_map.find(*it) == key_map.end()) ret.push_back(*it);
        else ret.push_back(key_map[*it]);
      }
    return(ret);
  }
private:
  map<char, char> makeMap (vector <string> switches)
  {
    char key1, key2, val1, val2;
    map<char, char> key_map;
    for (vector <string>::const_iterator it = switches.begin();
         it < switches.end(); ++it)
      {
        key1 = (*it)[0];
        key2 = (*it)[2];
        if (key_map.find(key1) == key_map.end()) key_map[key1] = key1;
        if (key_map.find(key2) == key_map.end()) key_map[key2] = key2;
        val1 = key_map[key1];
        val2 = key_map[key2];
        key_map[key1] = val2;
        key_map[key2] = val1;
      }
    map<char, char> out_map;
    for (map<char, char>::const_iterator it = key_map.begin();
         it != key_map.end(); ++it) out_map[(*it).second] = (*it).first;
    return (out_map);
  }
};
