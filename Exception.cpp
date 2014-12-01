//
// Exception.cpp for Execption.cpp in /home/caille_l//Dropbox/Abstract-Vm
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Tue Feb 12 17:05:50 2013 louis cailleux
// Last update Thu Feb 14 15:04:09 2013 jordan bettin
//

#include "Exception.hh"

Exception::Exception(const std::string &msg) throw()
{
  this->_msg = msg;
}

Exception::~Exception() throw()
{
}

const char*             Exception::what() const throw()
{
  return (this->_msg.c_str());
}
