#include <string>

using std::string;

class district
{
private:
  int province_id;
  int canton_id;
  int district_id;
  string name;
  string formatCode(int code);
public:
  district(
    int province_id,
    int canton_id,
    int district_id,
    string name
  );
  ~district();

  int getProvinceId();
  int getCantonId();
  int getDistrictId();
  string getName();
  string getPostalCode();

  bool operator < (const district& district_obj) const
    {
        return (province_id < district_obj.province_id) ||
              (province_id == district_obj.province_id && canton_id < district_obj.canton_id) || 
              (province_id == district_obj.province_id && canton_id == district_obj.canton_id && district_id < district_obj.district_id);
    }
};

district::district(
  int province_id,
  int canton_id,
  int district_id,
  string name
)
{
  this->province_id = province_id;
  this->canton_id = canton_id;
  this->district_id = district_id;
  this->name = name;
}

district::~district()
{
}


int district::getProvinceId()
{
  return this->province_id;
}
int district::getCantonId()
{
  return this->canton_id;
}
int district::getDistrictId()
{
  return this->district_id;
}
string district::getName()
{
  return this->name;
}

string district::getPostalCode()
{
  return std::to_string(this->province_id) + 
         this->formatCode(this->canton_id) +
         this->formatCode(this->district_id);
}

string district::formatCode(int code)
{
  if(code > 9) return std::to_string(code);

  return "0" + std::to_string(code);
}

