//
// Parser.hh for Parser in /home/caille_l//Dropbox/Abstract-Vm
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Tue Feb 12 13:12:34 2013 louis cailleux
// Last update Fri Feb 15 11:04:17 2013 jordan bettin
//

#ifndef	PARSER_HH
#define	PARSER_HH

#include <map>
#include <utility>
#include <fstream>
#include <string>
#include <iostream>
#include "Exception.hh"
#include "Epur.hh"
#include "AbstractVM.hh"

/**
 * @file
 * @author Jordan Bettin <bettin_j@epitech.net>
 * @author Louis Cailleux <caille_l@epitech.net>
 * 
 * Representation of a parser class for parsing the file or stream
 */

class	Parser
{
private:
  std::multimap<int, std::string>	_instructions;

public:
  /**
   * Constructor
   */
  Parser();

  /**
   * Copy constructor
   */
  Parser(const Parser &);

  /**
   * Operator = for the copy
   */
  Parser& operator=(const Parser &);

  /**
   * getInstructions : returns the list of instructions
   */
  std::multimap<int, std::string> getInstructions() const;

  /**
   * read : choose a file or the standard input and parses the content
   */
  int	read(const std::string);

  /**
   * stockInstructions : store instructions in a map after parsing
   */
  void  stockInstructions(int, std::string);

  /**
   * Destructor
   */
  ~Parser();
};

#endif
