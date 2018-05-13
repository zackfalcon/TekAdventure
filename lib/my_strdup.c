/*
** my_strdup.c for libkaas in /home/antoine.casse/Desktop/Lib
** 
** Made by Antoine Casse
** Login   <antoine.casse@epitech.net>
** 
** Started on  Mon Jan 23 15:42:26 2017 Antoine Casse
** Last update Thu May 25 20:06:38 2017 LAABID Zakaria
*/

#include "lkaas.h"

char	*my_strdup(char *str)
{
  int	i;
  char	*res;

  i = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}

int	*my_intdup(char *str)
{
  int	i;
  int	*res;

  i = 0;
  if (str == NULL)
    return (NULL);
  if ((res = malloc(sizeof(int) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[i])
    {
      res[i] = str[i] - '0';
      i += 1;
    }
  res[i] = -42;
  return (res);
}
