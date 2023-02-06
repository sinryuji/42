#include "MyWarlock.hpp"

MyWarlock::MyWarlock() {
  std::cout << this->name << ": This looks like another boring day." << std::endl;
}

MyWarlock::MyWarlock(const MyWarlock& origin) : name(origin.getName()), title(origin.getTitle()) {
  std::cout << this->name << ": This looks like another boring day." << std::endl;
}

MyWarlock::MyWarlock(std::string name, std::string title) : name(name), title(title) { 
  std::cout << this->name << ": This looks like another boring day." << std::endl;
}

MyWarlock::~MyWarlock() {
  std::cout << this->name << ": My job here is done!" << std::endl;
}

MyWarlock& MyWarlock::operator=(const MyWarlock& origin) {
  if (this != &origin) {
     this->name = origin.getName();
     this->title = origin.getName();
  }
  return *this;
}

void MyWarlock::introduce() const {
  std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}
