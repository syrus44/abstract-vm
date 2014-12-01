//
// main.cpp for main in /home/bettin_j//Documents/Abstract-Vm/src
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Sat Feb  9 10:34:14 2013 jordan bettin
// Last update Tue Feb 12 15:23:39 2013 louis cailleux
//

#include <iostream>
#include "Parser.hh"

int	main(int ac, char **av)
{
  if (ac > 2)
    {
      std::cerr << "No file found ! Usage : ./avm | ./avm <file>" << std::endl;
      return 1;
    }

    Parser	p;
    
    std::string	s1 = "cin";

    if (ac == 2)
      {
	std::string s2 = av[1];
	p.read(s2);
      }
    else
      p.read(s1);
  return (0);
}
