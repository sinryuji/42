#ifndef MYWARLOCK_HPP
# define MYWARLOCK_HPP

# include <iostream>

class MyWarlock {
  public:
    MyWarlock(); 
    MyWarlock(const MyWarlock& origin);
    MyWarlock(std::string name, std::string title);
    ~MyWarlock();
    MyWarlock& operator=(const MyWarlock& origin);
    std::string& getName(void) const;
    std::string& getTitle(void) const;
    void setTitle(const std::string& title);
    void introduce() const;
  private:
    std::string name;
    std::string title; 
};

#endif
