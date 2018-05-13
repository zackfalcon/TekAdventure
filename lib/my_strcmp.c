/*
** my_strcmp.c for  in /home/BlackBirdz/CPool_Day06
** 
** Made by Laabid Zakaria
** Login   <BlackBirdz@epitech.net>
** 
** Started on  Mon Oct 10 21:42:08 2016 Laabid Zakaria
** Last update Fri Mar 10 16:48:31 2017 LAABID Zakaria
*/

#include <stdlib.h>

void	my_putchar(char c);

int	my_strcmp(char *s1, char *s2, int n)
{
  int   i;

  i = -1;
  if (s1 == NULL || s2 == NULL)
    return (84);
  while ((i++ < n) && (s1[i] || s2[i]))
    if (s1[i] != s2[i])
      return (s1[i] - s2[i]);
  if (s1 && s2)
    return (0);
  else
    return (84);
}
