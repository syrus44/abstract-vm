//
// AbstractVM.cpp for AbstractVM in /home/bettin_j//Documents/Abstract-Vm/src
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Sat Feb  9 10:46:04 2013 jordan bettin
// Last update Sat Feb 23 17:36:23 2013 jordan bettin
//

#include "AbstractVM.hh"

AbstractVM::AbstractVM()
{
  this->_ptrInstr["pop"] = &AbstractVM::pop;
  this->_ptrInstr["dump"] = &AbstractVM::dump;
  this->_ptrInstr["add"] = &AbstractVM::add;
  this->_ptrInstr["sub"] = &AbstractVM::sub;
  this->_ptrInstr["mul"] = &AbstractVM::mul;
  this->_ptrInstr["div"] = &AbstractVM::div;
  this->_ptrInstr["mod"] = &AbstractVM::mod;
  this->_ptrInstr["print"] = &AbstractVM::print;
  this->_ptrInstr["exit"] = &AbstractVM::exit;
  this->_ptrTypes["int8"] = &AbstractVM::createInt8;
  this->_ptrTypes["int16"] = &AbstractVM::createInt16;
  this->_ptrTypes["int32"] = &AbstractVM::createInt32;
  this->_ptrTypes["double"] = &AbstractVM::createDouble;
  this->_ptrTypes["float"] = &AbstractVM::createFloat;
}

AbstractVM::~AbstractVM()
{}

AbstractVM::AbstractVM(const AbstractVM & other)
{
  this->_operands = other._operands;
  this->_ptrInstr = other._ptrInstr;
  this->_ptrTypes = other._ptrTypes;
}

AbstractVM &	AbstractVM::operator=(const AbstractVM & other)
{
  if (&other != this)
    {
      this->_operands = other._operands;
      this->_ptrInstr = other._ptrInstr;
      this->_ptrTypes = other._ptrTypes;
    }
  return *this;
}

void	AbstractVM::runApp(std::multimap<int, std::string> instr)
{
  Epur		*spellchecker;
  std::string compare;
  std::multimap<int, std::string>::iterator jt;

  
  for (std::multimap<int, std::string>::iterator it = instr.begin(); it != instr.end(); ++it)
    {
      if (!(it->second.empty()))
        {
	  if (this->_ptrInstr.find(it->second) == this->_ptrInstr.end())
	    {
	      if (it->second.compare(0, it->second.size(), "push") == 0 || it->second.compare(0, it->second.size(), "assert") == 0)
		{
		  jt = it;
		  ++jt;
		  spellchecker = new Epur(jt->second);
		  spellchecker->findMistakes();
		  this->typeVerification(jt, it, compare);
		}
	      if (this->_ptrTypes.find(compare) == this->_ptrTypes.end() && it->second.find(";") == std::string::npos)
		throw Exception("Invalid instruction");
	    }
	  else
	    (this->*_ptrInstr[it->second])();
	}
    }
}

IOperand *AbstractVM::extractOperand(const std::string& type, const std::string &str)
{
  Epur		*newep = new Epur(type);
  size_t	j = 0;
  IOperand	*result;
  std::string	arguments;
  std::string   valid = "-.0123456789";

  arguments = str.substr(str.find("(") + 1, (str.find(")") - (str.find("(") + 1)));
  for (size_t i = 0; i < arguments.size(); i++)
    {
      if (valid.find(arguments[i]) == std::string::npos)
	throw Exception("invalid operand");
      if (arguments[i] == '.')
	j++;
    }
  if (arguments.compare(0, arguments.size(), "-") == 0 || arguments.compare(0, arguments.size(), ".") == 0)
    throw Exception("Operand isn't a numerical value");
  if (arguments.empty())
    throw Exception("Empty value declared as operand");
  result = this->createOperand(newep->guessType(j), arguments);
  delete (newep);
  return (result);
}

IOperand	*AbstractVM::createOperand(eOperandType type, const std::string & value)
{
  IOperand *result;

  switch (type)
    {
    case INT8:
      result = this->createInt8(value);
      break;
    case INT16:
      result = this->createInt16(value);
      break;
    case INT32:
      result = this->createInt32(value);
      break;
    case FLOAT:
      result = this->createFloat(value);
      break;
    case DOUBLE:
      result = this->createDouble(value);
      break;
    case UNKNOWN:
      throw Exception("Unkown type for operand");
      break;
    }
  return (result);
}

void	AbstractVM::push(IOperand *newop)
{
  this->_operands.push(newop);
}

void	AbstractVM::pop()
{
  if (this->_operands.empty())
    throw Exception("The stack is empty");
  if (!(this->_operands.empty()))
    this->_operands.pop();
}

void	AbstractVM::dump()
{
  std::stack<IOperand *>	*op = new std::stack<IOperand *>;

  (*op) = this->_operands;

  while (!(op->empty()))
    {
      std::cout << op->top()->toString() << std::endl;
      op->pop();
    }
  delete (op);
}

void	AbstractVM::assert(IOperand * rhs)
{
  if (!this->_operands.empty())
    {
      if (this->_operands.top() != rhs)
	throw Exception("the values doesn't match");
    }
  throw Exception("The stack is empty");
}

void	AbstractVM::add()
{
  IOperand *v1;
  IOperand *v2;
  IOperand *res;

  if (this->_operands.size() >= 2)
    {
      v1 = this->_operands.top();
      this->_operands.pop();
      v2 = this->_operands.top();
      res = (*v2) + (*v1);
      this->_operands.push(res);
    }
  else
    throw Exception("The stack doesn't contain enough values");
}

void	AbstractVM::sub()
{
  IOperand *v1;
  IOperand *v2;
  IOperand *res;

  if (this->_operands.size() >= 2)
    {
      v1 = this->_operands.top();
      this->_operands.pop();
      v2 = this->_operands.top();
      res = (*v2) - (*v1);
      this->_operands.push(res);
    }
  else
    throw Exception("The stack doesn't contain enough values");
}

void	AbstractVM::mul()
{
  IOperand *v1;
  IOperand *v2;
  IOperand *res;

  if (this->_operands.size() >= 2)
    {
      v1 = this->_operands.top();
      this->_operands.pop();
      v2 = this->_operands.top();
      res = (*v2) * (*v1);
      this->_operands.push(res);
    }
  else
    throw Exception("The stack doesn't contain enough values");
}

void	AbstractVM::div()
{
  IOperand *v1;
  IOperand *v2;
  IOperand *res;

  if (this->_operands.size() >= 2)
    {
      v1 = this->_operands.top();
      this->_operands.pop();
      v2 = this->_operands.top();
      res = (*v2) / (*v1);
      this->_operands.push(res);
    }
  else
    throw Exception("The stack doesn't contain enough values");
}

void	AbstractVM::mod()
{
  IOperand *v1;
  IOperand *v2;
  IOperand *res;

  if (this->_operands.size() >= 2)
    {
      v1 = this->_operands.top();
      this->_operands.pop();
      v2 = this->_operands.top();
      res = (*v2) % (*v1);
      this->_operands.push(res);
    }
  else
    throw Exception("The stack doesn't contain enough values");
}

void	AbstractVM::print()
{
  std::string	tmp_v;
  short int	int8;
  short	int16;
  int	int32;
  double	d;
  float		f;

  if (!(this->_operands.empty()))
    {
      switch (this->_operands.top()->getType())
	{
	case INT8:
	  {
	    tmp_v = this->_operands.top()->toString();
	    std::istringstream	is(tmp_v);
	    is >> int8;
	    std::cout << int8 << std::endl;
	    break;
	  };
	case INT16:
	  {
	    tmp_v = this->_operands.top()->toString();
	    std::istringstream	is(tmp_v);
	    is >> int16;
	    std::cout << int16 << std::endl;
	    break;
	  };
	case INT32:
	  {
	    tmp_v = this->_operands.top()->toString();
	    std::istringstream	is(tmp_v);
	    is >> int32;
	    std::cout << int32 << std::endl;
	    break;
	  };
	case DOUBLE:
	  {
	    tmp_v = this->_operands.top()->toString();
	    std::istringstream	is(tmp_v);
	    is >> d;
	    std::cout << d << std::endl;
	    break;
	  };
	case FLOAT:
	  {
	    tmp_v = this->_operands.top()->toString();
	    std::istringstream	is(tmp_v);
	    is >> f;
	    std::cout << f << std::endl;
	    break;
	  }
	default:
	  throw Exception("Invalid type");
	}
    }
  else
    throw Exception("The stack doesn't contain enough values");
}

void	AbstractVM::exit()
{
  try {
    quick_exit(EXIT_SUCCESS);
  }
  catch (Exception &e) {
    std::cerr << "No match for instruction exit" << std::endl;
  }
}

IOperand *	AbstractVM::createInt8(const std::string & value)
{
  return (new Operands<short int>(INT8, value));
}

IOperand *	AbstractVM::createInt16(const std::string & value)
{
  return (new Operands<short>(INT16, value));
}

IOperand *	AbstractVM::createInt32(const std::string & value)
{
  return (new Operands<int>(INT32, value));
}

IOperand *	AbstractVM::createDouble(const std::string & value)
{
  return (new Operands<double>(DOUBLE, value));
}

IOperand *	AbstractVM::createFloat(const std::string & value)
{
  return (new Operands<float>(FLOAT, value));
}

void	AbstractVM::typeVerification(std::multimap<int, std::string>::iterator jt, std::multimap<int, std::string>::iterator it, std::string &compare)
{
  std::multimap<int, std::string>::iterator kt;

  if (jt->second.find("(") != std::string::npos && jt->second.find(")") && jt->first == it->first)
    {
      kt = jt;
      ++kt;
      if (kt->first == it->first && kt->first)
	throw Exception("Too many arguments for instruction");
      compare = jt->second.substr(0, jt->second.find("("));
      if (this->_ptrTypes.find(compare) == this->_ptrTypes.end())
	throw Exception("Invalid type");
      else
	{
	  if (it->second.compare(0, it->second.size(), "push") == 0)
	    this->push(this->extractOperand(compare, jt->second));
	  else
	    this->assert(this->extractOperand(compare, jt->second));
	}
    }
  else
    throw Exception("Invalid instruction");
}
