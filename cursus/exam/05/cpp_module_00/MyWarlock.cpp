#include "MyWarlock.hpp"

MyWarlock::MyWarlock(std::string name, std::string title) : name(name), title(title) { 
  std::cout << this->name << ": This looks like another boring day." << std::endl;
}

MyWarlock::~MyWarlock() {
  std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string& MyWarlock::getName() const {
  return this->name;
}

const std::string& MyWarlock::getTitle() const {
  return this->title;
}

void MyWarlock::setTitle(const std::string& title) {
  this->title = title;
}

void MyWarlock::introduce() const {
  std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}
