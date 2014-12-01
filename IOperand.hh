//
// IOperand.hh for IOperand in /home/bettin_j//Documents/Abstract-Vm/include
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Sat Feb  9 09:32:15 2013 jordan bettin
// Last update Thu Feb 21 17:01:55 2013 louis cailleux
//

#ifndef IOPERAND_HH
#define	IOPERAND_HH

#include <string>
#include <iostream>
#include <exception>

/**
 * @file
 * @author Jordan Bettin <bettin_j@epitech.net>
 * @author Louis Cailleux <caille_l@epitech.net>
 *
 * Interface IOperand : representation of the interface IOperand 
 * for the AbstractVM classes
 */

/**
 * Enumeration eOperandType
 * lists all operand types supported by the virtual machine
 */
typedef enum eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE,
    UNKNOWN,
  }		eOperandType;

class	IOperand
{
public:
  /**
   * toString : Returns a string representing the instance
   */
  virtual std::string const & toString() const = 0;

  /**
   * getPrecision : Returns the precision of instance's type
   */
  virtual int getPrecision() const = 0;

  /**
   * getType : Returns the instance's type
   */
  virtual eOperandType getType() const = 0;

  /**
   * operator+ : Performs addition on two references
   * of IOperand
   */
  virtual IOperand * operator+(const IOperand & rhs) const = 0;

  /**
   * operator- : Performs subtraction on two references
   * of IOperand
   */
  virtual IOperand * operator-(const IOperand & rhs) const = 0;

  /**
   * operator* : Performs multiplication on two references
   * of IOperand
   */
  virtual IOperand * operator*(const IOperand & rhs) const = 0;

  /**
   * operator/ : Performs division on two references
   * of IOperand
   */
  virtual IOperand * operator/(const IOperand & rhs) const = 0;

  /**
   * operator% : Performs modulo on two references
   * of IOperand
   */
  virtual IOperand * operator%(const IOperand & rhs) const = 0;

  /**
   * Virtual destructor
   */
  virtual ~IOperand() {}
};

#endif
