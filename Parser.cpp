//
// Parser.cpp for Parser in /home/caille_l//Dropbox/Abstract-Vm
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Tue Feb 12 12:14:37 2013 louis cailleux
// Last update Sat Feb 23 10:25:26 2013 jordan bettin
//

#include	"Parser.hh"

Parser::Parser()
{}

Parser::Parser(const Parser &other)
{
  this->_instructions = other.getInstructions();
}

Parser&	Parser::operator=(const Parser &other)
{
  if (this != &other)
    {
      this->_instructions = other.getInstructions();
    }
  return (*this);
}

std::multimap<int, std::string>	Parser::getInstructions() const
{
  return (this->_instructions);
}

int	Parser::read(const std::string stream)
{
  std::ifstream file(stream.c_str(), std::ios::in);
  std::string		 content;
  Epur			 *toEpur;
  AbstractVM		 *theVM = new AbstractVM;
  unsigned int		 i = 0;

  try
    {
      if (file)
	{
	  i = 0;
	  while (getline(file, content))
	    {
	      toEpur = new Epur(content);
              toEpur->removeSpaces();
              this->stockInstructions(i, toEpur->getEpured());
	      delete (toEpur);
	      i++;
	    }
	  file.close();
	  theVM->runApp(this->_instructions);
	  return (0);
	}
      else if (stream.compare("cin") == 0)
	{
	  while (getline(std::cin, content) && content.find(";;") != 0)
	    {
	      toEpur = new Epur(content);
	      toEpur->removeSpaces();
	      this->stockInstructions(i, toEpur->getEpured());
	      delete (toEpur);
	      if (content.find("\n"))
	       theVM->runApp(this->_instructions);
	      this->_instructions.clear();
	      i++;
	    }
	  return (0);
	}
      else throw Exception("File not found");
    }
  catch (const Exception &e)
    {
      std::cerr << "Error : " << e.what() << std::endl;
    }
  delete (theVM);
  return (1);
}

void    Parser::stockInstructions(int line, std::string str)
{
  Epur	 *myEpur = new Epur(str);
  std::string	   add;
  std::vector<int> location;
  size_t	   prev = 0;
  
  location = myEpur->findLocation(location, str, ' ');
  if (str.find(";") != std::string::npos)
    this->_instructions.insert(std::pair<int, std::string>(line, str));
  else
    {
      for (size_t i = 0; i != location.size(); i++) {
	add = str.substr(prev, location[i] - prev);
	prev = location[i] + 1;
	this->_instructions.insert(std::pair<int, std::string>(line, add));
	add.clear();
      }
    }
  delete (myEpur);
}

Parser::~Parser()
{}
