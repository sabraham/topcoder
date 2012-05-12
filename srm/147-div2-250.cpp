// Caesar Cipher
#include <string>
using namespace std;
class CCipher
{
public:
  string decode(string cipherText, int shift)
  {
    int len = cipherText.size();
    for (int i = 0; i < len; ++i)
	cipherText[i] = (cipherText[i] - 'A' < shift) ?
	  'Z' - (shift - (cipherText[i] - 'A')) + 1 :
	  cipherText[i] - shift;
    return cipherText;
  }
};
