#include <string>

using std::string;

class canton
{
private:
  int id;
  int canton_id;
  int province_id;
  string name;
public:
  canton(
    int canton_id,
    int province_id,
    string name
  );
  ~canton();
  int getCantonId();
  int getProvinceId();
  string getName();
};

canton::canton(
  int canton_id,
  int province_id,
  string name)
{
  this->canton_id = canton_id;
  this->province_id = province_id;
  this->name = name;
}

canton::~canton()
{
}

int canton::getCantonId()
{
  return this->canton_id;
}

int canton::getProvinceId()
{
  return this->province_id;
}

string canton::getName()
{
  return this->name;
}
