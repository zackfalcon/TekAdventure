/*
** my_puterr.c for libkaas in /home/antoine.casse/Desktop/lib
** 
** Made by Antoine Casse
** Login   <antoine.casse@epitech.net>
** 
** Started on  Tue Jan 24 16:25:46 2017 Antoine Casse
** Last update Sun May 28 12:28:34 2017 Capitaine CASSE
*/

#include "lkaas.h"

void	*my_puterrnull(const char *err)
{
  write(2, err, my_strlen(err));
  return (NULL);
}

int	my_puterr(const char *err, const int x)
{
  if (write(2, err, my_strlen(err)) <= 0)
    return (-1);
  return (x);
}
