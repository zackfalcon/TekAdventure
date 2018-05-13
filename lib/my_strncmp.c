/*
** my_strncmp.c for  in /home/BlackBirdz/CPool_Day06
** 
** Made by Laabid Zakaria
** Login   <BlackBirdz@epitech.net>
** 
** Started on  Mon Oct 10 22:49:16 2016 Laabid Zakaria
** Last update Fri May 26 13:32:06 2017 Capitaine CASSE
*/

#include <stdlib.h>

int	my_strncmp(const char *s1, const char *s2, const int n)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] && s2[i] && i < (n - 1) && s1[i] == s2[i])
    i += 1;
  return (s1[i] - s2[i]);
}
