/*
** my_putstr.c for libkaas in /home/AntoineC/Desktop/delivery/CPool_Day04
** 
** Made by Antoine Casse
** Login   <AntoineC@epitech.net>
** 
** Started on  Thu Oct  6 15:27:41 2016 Antoine Casse
** Last update Tue Jan 24 16:27:36 2017 Antoine Casse
*/

#include "lkaas.h"

int	my_putstr(char *str)
{
  int	nb;

  nb = 0;
  while (str[nb])
    {
      my_putchar(str[nb]);
      nb += 1;
    }
  return (0);
}
