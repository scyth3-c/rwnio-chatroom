#ifndef _NAMECON_H
#define _NAMECON_H

#include <string>
#include <memory>
#include <fstream>

class Name {

private:
   
   std::shared_ptr<std::ofstream> storage = nullptr;
   std::shared_ptr<std::ifstream> reader = nullptr;
   std::shared_ptr<std::string> asingName = nullptr;

   static const char* fileName; 

public:

  Name();
  Name(std::string);
  ~Name();
  bool verify();
  void generateNamecon();
  void setName(std::string);
  std::string chargeName();
  std::string getName();

};

#endif // !_NAMECON_H