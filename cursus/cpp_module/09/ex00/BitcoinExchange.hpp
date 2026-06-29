#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <list>
# include <fstream>
# include <sstream>
# include <cctype>
# include <stdexcept>
# include <cstdlib>

static std::string k_db_name = "data.csv";
static const std::string k_open_err_msg = "file open error!";

class BitcoinExchange {
  public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange& origin);
    ~BitcoinExchange(void);
    BitcoinExchange& operator=(const BitcoinExchange& origin);
    void printDB(void);
    void exchange(std::string input);

  private:
    std::map<std::string, double> db;

    void parseDB(void);
    void validateInput(std::list<std::string> s, std::string line);
    double getExchangeRate(std::string& date);
    bool isValue(std::string& str);
    void validateDate(std::list<std::string>& v);
    void validateValue(std::string& str);
};

std::list<std::string> split(std::string& str, char delim);
bool strIsDigit(std::string& str);

#endif
