#ifndef MYWARLOCK_HPP
#define MYWARLOCK_HPP

#include <iostream>

class MyWarlock {
  public:
    MyWarlock(std::string name, std::string title);
    ~MyWarlock();
    const std::string& getName(void) const;
    const std::string& getTitle(void) const;
    void setTitle(const std::string& title);
    void introduce() const;
  private:
    std::string name;
    std::string title; 

    MyWarlock(); 
    MyWarlock(const MyWarlock& origin);
    MyWarlock& operator=(const MyWarlock& origin);
};

#endif
