#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include "province.h"
#include "district.h"
#include "canton.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::string;

string getProvinceName(vector<province> provinces, int province_id) {
  
  for (size_t i = 0; i < provinces.size(); i++)
  {
    if(provinces[i].getId() == province_id ) return provinces[i].getName();
  }
  
  return "";
}

string getCantonName(vector<canton> cantons, int canton_id, int province_id) {

  for (size_t i = 0; i < cantons.size(); i++)
  {
    if(cantons[i].getCantonId() == canton_id && cantons[i].getProvinceId() == province_id) 
      return cantons[i].getName();
  }
  
  return "";
}



int main(int argc, const char** argv) {

  ifstream provinces_file("input_files/provinces.txt");
  ifstream canton_file("input_files/cantons.txt");
  ifstream districts_file("input_files/districts.txt");
  
  ofstream output_file("output.xlsx");

  int province_id;
  int canton_id;
  int district_id;

  string province_name = "";
  string canton_name = "";
  string district_name = "";

  string line;
  string delimiter = ",";
  string token = "";

  size_t pos = 0;

  vector<province> provinces;
  vector<district> districts;
  vector<canton> cantons;


  while (getline (provinces_file, line)) {

    string province_name;

    pos = line.find(delimiter);
    token = line.substr(0, pos);
    province_id = stoi(token);
    
    line.erase(0, pos + delimiter.length());
    
    province_name = line;

    province province_obj(province_id, province_name);

    provinces.push_back(province_obj);

  }

  provinces_file.close();

  while(getline (canton_file, line)) {

    pos = line.find(delimiter);
    token = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());

    pos = line.find(delimiter);
    token = line.substr(0, pos);
    province_id = stoi(token);
    line.erase(0, pos + delimiter.length());

    pos = line.find(delimiter);
    token = line.substr(0, pos);
    canton_id = stoi(token);
    line.erase(0, pos + delimiter.length());

    canton_name = line;
    
    canton canton_obj(canton_id, province_id, canton_name);

    cantons.push_back(canton_obj);

  }

  canton_file.close();

  while(getline(districts_file, line)) {
    pos = line.find(delimiter);
    token = line.substr(0, pos);
    line.erase(0, pos + delimiter.length());

    pos = line.find(delimiter);
    token = line.substr(0, pos);
    province_id = stoi(token);
    line.erase(0, pos + delimiter.length());

    pos = line.find(delimiter);
    token = line.substr(0, pos);
    canton_id = stoi(token);
    line.erase(0, pos + delimiter.length());

    pos = line.find(delimiter);
    token = line.substr(0, pos);
    district_id = stoi(token);
    line.erase(0, pos + delimiter.length());

    district_name = line;

    district district_obj(province_id, canton_id, district_id, district_name);

    districts.push_back(district_obj);
  }

  districts_file.close();

  std::sort(districts.begin(), districts.end());

  output_file << "Provincia,Canton,Distrito,Codigo Postal" << endl;

  for (size_t i = 0; i < districts.size(); i++)
  {
    output_file  << getProvinceName(provinces, districts[i].getProvinceId()) << ","
                 << getCantonName(cantons, districts[i].getCantonId(), districts[i].getProvinceId()) << ","
                 << districts[i].getName() << "," 
                 << districts[i].getPostalCode() << endl;
  }
  
  output_file.close();

  return 0;
}