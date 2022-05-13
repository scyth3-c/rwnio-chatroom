#include "namecon.h"


const char* Name::fileName = ".name";

Name::Name(std::string temp)  {
    asingName = std::make_shared<std::string>(std::move(temp));
    if(!verify()) {
        generateNamecon();
    }
}
Name::Name() {
    asingName = std::make_shared<std::string>("unkown");
    if(!verify()) {
        generateNamecon();
    }
}
Name::~Name() {
    asingName.reset();
    storage.reset();
    reader.reset();
}

bool Name::verify() {

reader = std::make_shared<std::ifstream>(fileName);
if(reader->good()) { 
    reader.reset();
    return true;
}
else {
    reader.reset();
    return false;
}

}

void Name::generateNamecon() {
     storage = std::make_shared<std::ofstream>(fileName);
    *storage << *asingName;
     storage = nullptr;
}

std::string Name::getName() {
  reader = std::make_shared<std::ifstream>(fileName);
  std::string name{};
  *reader >> name;
  reader.reset();
  return name;
}


void Name::setName(std::string temp) {
 asingName.reset();
 asingName = std::make_shared<std::string>(std::move(temp));
 generateNamecon();
}