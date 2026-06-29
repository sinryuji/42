#include "BitcoinExchange.hpp"

/*
 * -------------------------- Constructor --------------------------
 */

BitcoinExchange::BitcoinExchange(void) {
  this->parseDB();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& origin) {
  this->db = origin.db;
}

/*
 * -------------------------- Destructor ---------------------------
 */

BitcoinExchange::~BitcoinExchange(void) {}

/*
 * -------------------------- Operator -----------------------------
 */

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& origin)
{
  if (this != &origin)
    this->db = origin.db;

  return *this;
}

/*
 * ----------------------- Member Function -------------------------
 */

void BitcoinExchange::parseDB() {
  std::ifstream file(k_db_name.c_str(), std::ifstream::in);
  std::string line;

  if (!file.is_open())
    throw std::invalid_argument(k_open_err_msg);
  while (std::getline(file, line)) {
    std::list<std::string> l = split(line, ',');
    this->db.insert(std::pair<std::string, double>(l.front(), std::atof(l.back().c_str())));
  }
  file.close();
}

void BitcoinExchange::printDB(void) {
  std::cout << "len: " << this->db.size() << std::endl;
  std::cout.precision(9);
  for (std::map<std::string, double>::iterator it = this->db.begin(); it != this->db.end(); ++it)
    std::cout << it->first << " " << it->second << std::endl;
}

void BitcoinExchange::exchange(std::string input) {
  std::ifstream file(input.c_str(), std::ifstream::in);
  std::string line;

  if (!file.is_open())
    throw std::invalid_argument(k_open_err_msg);
  while (std::getline(file, line)) {
    std::list<std::string> l = split(line, '|');
    if (l.empty())
      continue;
    if (l.front() == "date" && l.back() == "value")
      continue;
    try {
      validateInput(l, line);
      std::cout.precision(9);
      std::cout << l.front() << " => " << l.back() << " = " << getExchangeRate(l.front()) * std::atof(l.back().c_str()) << std::endl;
    } catch (std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
  file.close();
}

void BitcoinExchange::validateInput(std::list<std::string> l, std::string line) {
  if (l.size() != 2)
    throw std::invalid_argument("bad input => " + line);
  
  std::list<std::string> v = split(l.front(), '-');

  if (v.size() == 3)
    validateDate(v);
  else
    throw std::invalid_argument("invalid date format => " + line);
  validateValue(l.back());
}

double BitcoinExchange::getExchangeRate(std::string& date) {
  std::map<std::string, double>::iterator it = this->db.find(date);
  if (it != this->db.end())
    return it->second; 
  it = db.upper_bound(date);
  if (it != this->db.begin())
    --it;
  return it->second;
}

bool BitcoinExchange::isValue(std::string& str) {
  bool point_flag = false;

  if (str[0] != '-' && !std::isdigit(str[0]))
    return false;
  for (size_t i = 1; i < str.length(); i++) {
    if (!(std::isdigit(str[i]) || str[i] == '.'))
      return false;
    if (str[i] == '.') {
      if (!point_flag)
        point_flag = true;
      else
        return false;
    }
  }
  return true;
}

void BitcoinExchange::validateDate(std::list<std::string>& v) {
  std::list<std::string>::iterator it = v.begin();
  for (; it != v.end(); ++it)
    if (!strIsDigit(*it))
      throw std::invalid_argument("invalid date => " + *it);
  if (std::atoi((*(--it)).c_str()) > 31)
    throw std::invalid_argument("invalid day => " + *it);
  if (std::atoi((*(--it)).c_str()) > 12)
    throw std::invalid_argument("invalid month => " + *it);
}

void BitcoinExchange::validateValue(std::string& str) {
  if (!isValue(str))
    throw std::invalid_argument("invalid value => " + str);
  if (std::atof(str.c_str()) < 0)
    throw std::invalid_argument("not a positive number. => " + str);
  if (std::atof(str.c_str()) > 1000)
    throw std::invalid_argument("too large a number. => " + str);
}

/*
 * ---------------------- Non-Member Function ----------------------
 */

std::list<std::string> split(std::string& str, char delim) {
  std::list<std::string> ret;
  std::stringstream ss(str);
  std::string tmp;

  while (std::getline(ss, tmp, delim)) {
    if (std::isspace(tmp[0]))
      tmp.erase(0, 1);
    if (std::isspace(tmp[tmp.length() - 1]))
      tmp.erase(tmp.length() - 1, 1);
    ret.push_back(tmp);
  }

  return ret;
}

bool strIsDigit(std::string &str) {
  for (size_t i = 0; i < str.length(); i++)
    if (!std::isdigit(str[i]))
      return false;
  return true;
}
