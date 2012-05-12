#include <string>

using namespace std;

class PeopleCircle
{
public:
  string order(int num_males, int num_females, int K)
  {
    int num_people = num_males + num_females;
    char ret[num_people+1];
    ret[num_people] = '\0';
    for (int i = 0; i < num_people; ++i) ret[i] = 'M';
    for (int i = 1; i <= num_females; ++i) ret[i*K-1 % num_people] = 'F';
    string r(ret);
    return r;
  }
};
