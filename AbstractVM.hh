//
// AbstractVM.hh for AbstractVM in /home/bettin_j//Documents/Abstract-Vm/include
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Sat Feb  9 10:45:37 2013 jordan bettin
// Last update Fri Feb 22 13:01:20 2013 louis cailleux
//

#ifndef ABSTRACTVM_HH
#define	ABSTRACTVM_HH

#include <map>
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <cstdlib>
#include "Operands.hpp"
#include "Epur.hh"

/**
 * @file
 * @author Jordan Bettin <bettin_j@epitech.net>
 * @author Louis Cailleux <caille_l@epitech.net>
 *
 * AbstractVM Class for the representation of the virtual machine
 */

class	AbstractVM
{
  std::stack<IOperand *>	_operands;
  std::map<std::string, void (AbstractVM::*)()>	_ptrInstr;
  std::map<std::string, IOperand *(AbstractVM::*)(const std::string &)> _ptrTypes;
  
public:
  /**
   * Constructor
   */
  AbstractVM();

  /**
   * Destructor
   */
  ~AbstractVM();

  /**
   * Copy constructor
   */
  AbstractVM(const AbstractVM &);

  /**
   * Operator = for the copy
   */
  AbstractVM& operator=(const AbstractVM &);

  /**
   * Starts the execution of the virtual machine
   */
  void	runApp(std::multimap<int, std::string>);

  /**
   * Add a value in the stack which is a pointer on a IOperand 
   */
  void	push(IOperand *);

  /**
   * Delete all values present in the stack
   */
  void	pop();

  /**
   * Display every value without modifying the stack
   */
  void	dump();

  /**
   * Check if the value matches with the parameter
   */
  void	assert(IOperand *);

  /**
   * Addition method
   */
  void	add();

  /**
   * Subtraction method
   */
  void	sub();

  /**
   * Multiplication method
   */
  void	mul();

  /**
   * Division method
   */
  void	div();

  /**
   * Modulo method
   */
  void	mod();

  /**
   * Check if the value is a 8-bit integer and display it
   */
  void	print();

  /**
   * Aborts the execution of the program
   */
  void	exit();

  /**
   * check if types are good
   */

private:
  /**
   * Create a new Operand of type INT8
   */
  IOperand *	createInt8(const std::string &);

  /**
   * Create a new Operand of type INT16
   */
  IOperand *	createInt16(const std::string &);

  /**
   * Create a new Operand of type INT32
   */
  IOperand *	createInt32(const std::string &);

  /**
   * Create a new Operand of type DOUBLE
   */
  IOperand *	createDouble(const std::string &);

  /**
   * Create a new Operand of type FLOAT
   */
  IOperand *	createFloat(const std::string &);

  /**
   * Extract the operand contained in a push or an assert instruction
   */
  IOperand *    extractOperand(const std::string &, const std::string &);

  /**
   * create Operand of the same type as the one in parameter
   */
  IOperand * createOperand(eOperandType type, const std::string & value);

  /**
   * Verify the validity of instruction's type
   */
  void	typeVerification(std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator, std::string &);
};

#endif
