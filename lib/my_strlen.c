/*
** my_strlen.c for libkaas in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Fri May 26 12:53:50 2017 Capitaine CASSE
** Last update Fri May 26 13:23:13 2017 Capitaine CASSE
*/

#include "lkaas.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    i += 1;
  return (i);
}
