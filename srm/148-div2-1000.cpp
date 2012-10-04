q#include <algorithm>
#include <vector>

using namespace std;

class MNS
{
public:
  int combos(vector <int> numbers)
  {
    sort(numbers.begin(), numbers.end());
    int row0, row, col;
    int ret = 0;
    do
      {
        row0 = numbers[coord(0,0)] + numbers[coord(0,1)] + numbers[coord(0,2)];
        bool valid = true;
        for (int i = 0; i < 3; ++i)
          {
            row = numbers[coord(i,0)] + numbers[coord(i,1)] + numbers[coord(i,2)];
            col = numbers[coord(0,i)] + numbers[coord(1,i)] + numbers[coord(2,i)];
            if (row != row0 || col != row0)
              {
                valid = false;
                break;
              }
          }
        if (valid) ret++;
      }
    while (next_permutation(numbers.begin(), numbers.end()));
    return(ret);
  }
private:
  inline int coord(int x, int y){return(3*y + x);}
};
