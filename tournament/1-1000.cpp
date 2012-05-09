#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <ctype.h>
#include <algorithm>
using namespace std;

typedef std::pair<std::string, int> class_pair;

struct cls
{
  string name;
  class_pair name_pair;
  vector<cls*> parents;
  vector<cls*> children;

  bool operator < (const cls& x) const
  {
    if (name_pair.second == x.name_pair.second)
      return name_pair.first < x.name_pair.first;
    else
      return name_pair.second < x.name_pair.second;
  }

};

class Prerequisites
{

public:
  vector<string> orderClasses(vector<string> class_schedule)
  {
    vector<string> classes;
    vector<cls> classes_structured;
    for (vector<string>::const_iterator it = class_schedule.begin();
	 it < class_schedule.end(); ++it)
      {
	stringstream stream(*it);
	string class_parent, class_child;
	getline(stream, class_parent, ':');
	struct cls* parent = 0;
	struct cls* child = 0;
	//check if class hasn't been seen yet
	for (vector<cls>::iterator it = classes_structured.begin();
	     it < classes_structured.end() ; ++it)
	  if (it->name == class_parent)
	    {
	      parent = &(*it);
	      break;
	    }
	if (!parent)
	  {
	    string prefix;
	    int num;
	    int offset = isdigit(class_parent[3]) ? 0 : 1;
	    prefix = class_parent.substr(0, 3+offset);
	    stringstream convert(class_parent.substr(3+offset));
	    convert >> num;
	    cls new_class;
	    new_class.name = class_parent;
	    new_class.name_pair = class_pair(prefix, num);
	    classes_structured.push_back(new_class);
	    parent = &(*classes_structured.end()) - 1;
	  }
	while(getline(stream, class_child, ' '))
	  {
	    if (class_child.size() < 5) continue;
	    // check if class hasn't been seen yet
	    for (vector<cls>::iterator
		   it = classes_structured.begin();
		 it < classes_structured.end() ; ++it)
	      if (it->name == class_child)
		{
		  child = &(*it);
		  break;
		}
	    if (!child)
	      {
		string prefix;
		int num;
		int offset = isdigit(class_child[3]) ? 0 : 1;
		prefix = class_child.substr(0, 3+offset);
		stringstream convert(class_child.substr(3+offset));
		convert >> num;
		cls new_class;
		new_class.name = class_child;
		new_class.name_pair = class_pair(prefix, num);
		classes_structured.push_back(new_class);
		child = &(*classes_structured.end()) - 1;
	      }
	    parent->children.push_back(child);
	    child->parents.push_back(parent);
	  }
      }
    int num_classes = classes_structured.size();
    vector<string> classes_taken;
    while (num_classes > 0)
      {
	// build list of classes that are possible to take
	vector<cls> classes_consider;
	for (vector<struct cls>::const_iterator
	       class_it = classes_structured.begin();
	     class_it < classes_structured.end(); ++class_it)
	  {
	    if (find(classes_taken.begin(), classes_taken.end(),
		     class_it->name) != classes_taken.end()) continue;
	    bool prereqs_found = true;
	    for (vector<struct cls*>::const_iterator
		   prereq_it = class_it->children.begin();
		 prereq_it < class_it->children.end(); ++prereq_it)
	      {
		string search = (*prereq_it)->name;
		if (find(classes_taken.begin(), classes_taken.end(),
			 search) == classes_taken.end())
		  {
		    prereqs_found = false;
		    break;
		  }
	      }
	    if (prereqs_found) classes_consider.push_back(*class_it);
	  }
	sort(classes_consider.begin(), classes_consider.end());
	classes_taken.push_back(classes_consider[0].name);
	--num_classes;
      }
    return classes_taken;
  }
};

int
main()
{
  return 0;
}
	   
      
  
