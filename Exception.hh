//
// Exception.hh for Exception in /home/caille_l//Dropbox/Abstract-Vm
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Tue Feb 12 17:00:02 2013 louis cailleux
// Last update Thu Feb 14 14:54:04 2013 jordan bettin
//

#ifndef	EXCEPTION_HH
#define	EXCEPTION_HH

#include <iostream>
#include <exception>

/**
 * @file
 * @author Jordan Bettin <bettin_j@epitech.eu>
 * @author Louis Cailleux <caille_l@epitech.eu>
 *
 * Representation of the Exception class
 * that manages all exception cases
 * Inheritance from std::exception
 */

class	Exception : public std::exception
{
  std::string	_msg;
  
public:
  /**
   * Constructor
   */
  Exception (std::string const &msg) throw();

  /**
   * Virtual destructor
   */
  virtual ~Exception() throw();

  /**
   * Member function what to display the message and aborts
   */
  virtual const char* what() const throw();
};

#endif
