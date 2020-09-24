#include <string>

using std::string;

class province
{
private:
  int id;
  string name;
public:
  province(int id, string name);
  ~province();
  int getId();
  string getName();
};

province::province(int id, string name)
{
  this->id = id;
  this->name = name;
}

province::~province()
{
}

int province::getId()
{
  return this->id;
}

string province::getName()
{
  return this->name;
}

