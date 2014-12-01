//
// Epur.hh for Epur in /home/caille_l//Dropbox/Abstract-Vm
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Wed Feb 13 11:43:19 2013 louis cailleux
// Last update Fri Feb 22 13:37:31 2013 louis cailleux
//


#ifndef EPUR_HH
#define EPUR_HH

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <string>

/**
 * @file
 * @author Jordan Bettin <bettin_j@epitech.eu>
 * @author Louis Cailleux <caille_l@epitech.eu>
 *
 * Representation of a epur_str in C++
 *
 */

#include "IOperand.hh"

class Epur
{
  std::string	_epured;
  
public:
  /**
   * Constructor
   */
  Epur(const std::string);

  /**
   * Copy constructor
   */
  Epur(const Epur &);

  /**
   * Destructor
   */
  ~Epur();
  
  /*
   * getEpured : returns the string epured from the instance
   */
  std::string getEpured() const;

  /**
   * setEpured : set the parameter in the class
   */
  void setEpured(const std::string);

  /**
   * removeSpaces : remove spaces in a line
   */
  void removeSpaces();

  /**
   * Operator = for the copy
   */
  Epur &operator=(const Epur &other);

  /**
   * findLocation : find the position of a character given as parameter
   */
  std::vector<int> findLocation(std::vector<int>, std::string, char);
  
  /**
   * find type for current operand
   */
  eOperandType guessType(int j);

    /**
   * Search for typing errors in operand declaration
   */
  void	findMistakes();
};

#endif
