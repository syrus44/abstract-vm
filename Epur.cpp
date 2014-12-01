//
// Epur.cpp for Epur in /home/caille_l//Dropbox/Abstract-Vm
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Wed Feb 13 11:52:32 2013 louis cailleux
// Last update Sat Feb 23 10:08:34 2013 jordan bettin
//

#include	"Epur.hh"
#include	"Exception.hh"

Epur::Epur(const std::string str)
{
  this->_epured = str;
}

Epur::Epur(const Epur & other)
{
  this->_epured = other.getEpured();
}

Epur & Epur::operator=(const Epur & other)
{
  if (&other != this)
    this->_epured = other.getEpured();
  return (*this);
}

Epur::~Epur()
{
}

void Epur::removeSpaces()
{
  std::string		temp;
  std::istringstream	iss;
  std::string		result = "";

  iss.str(this->_epured);
  while (iss >> temp >> std::ws)
    {
      if (result != "")
	result += " ";
      result += temp;
    }
  iss.clear();
  if (!result.empty())
    this->setEpured(result);
}

std::string Epur::getEpured() const
{
  return (this->_epured);
}

void	Epur::setEpured(const std::string str)
{
  this->_epured = str;
}

std::vector<int> Epur::findLocation(std::vector<int> location, std::string str, char find)
{
  unsigned int		  i;

  i = 0;
  while (i < str.size())
    {
      if (str[i] == find)
	location.push_back(i);
      i++;
    }
  if (find != '(' && find != ')')
    location.push_back(str.size());
  return (location);
}

eOperandType	Epur::guessType(int j)
{
  if (this->_epured.compare("int8") == 0 && j == 0)
    return (INT8);
  else if (this->_epured.compare("int16") == 0 && j == 0)
    return (INT16);
  else if (this->_epured.compare("int32") == 0 && j == 0)
    return (INT32);
  else if (this->_epured.compare("float") == 0 && j <= 1)
    return (FLOAT);
  else if (this->_epured.compare("double") == 0 && j <= 1)
    return (DOUBLE);
  else
    throw Exception("Invalid type or operand");
  return (UNKNOWN);
}

void		Epur::findMistakes()
{
  std::string		whatsbehind;
  std::vector<int>	count_o;
  std::vector<int>	count_c;
  
  count_o = this->findLocation(count_o, this->_epured, '(');
  count_c = this->findLocation(count_c, this->_epured, ')');
  if (count_o.empty() || count_c.empty())
    throw Exception("No match for parenthesis in type declaration");
  if (count_o.size() > 1 || count_c.size() > 1)
    throw Exception("Two many parenthesis in type declaration");
  whatsbehind = this->_epured.substr(count_c.front(), (this->_epured.size() - (count_c.front() + 1)));
  if (!(whatsbehind.empty()))
    throw Exception("Invalid type");
}
