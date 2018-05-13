/*
** my_putchar.c for libkaas in /home/AntoineC/Desktop/Pool_Days/CPool_Day03
** 
** Made by Antoine Casse
** Login   <AntoineC@epitech.net>
** 
** Started on  Fri Oct  7 08:03:43 2016 Antoine Casse
** Last update Tue Jan 24 16:24:22 2017 Antoine Casse
*/

#include "lkaas.h"

int	my_putchar(char c)
{
  if (write (1, &c, 1) < 0)
    return (1);
  return (0);
}
