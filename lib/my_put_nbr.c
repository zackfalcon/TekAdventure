/*
** my_put_nbr.c for kaas /home/AntoineC/Desktop/delivery/CPool_Day03
** 
** Made by Antoine Casse
** Login   <AntoineC@epitech.net>
** 
** Started on  Wed Oct  5 13:07:09 2016 Antoine Casse
** Last update Fri Jan 27 17:27:11 2017 Capitaine Casse
*/

#include "lkaas.h"

int     disp(int q, int r)
{
  my_put_nbr(q);
  my_putchar(r + '0');
  return (0);
}

int	my_put_nbr(int nb)
{
  int	q;
  int	r;
  int	s;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb > 9)
    {
      r = nb % 10;
      q = (nb / 10);
      if (q > 9)
	{
          disp(q, r);
	  return (0);
	}
      disp(q, r);
    }
  else
    my_putchar(nb + '0');
  return (0);
}
