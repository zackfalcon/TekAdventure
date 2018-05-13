/*
** my_wordtab.c for  in /home/Blackbirdz/CPE_2016_BSQ
** 
** Made by Zakaria LAABID
** Login   <Blackbirdz@epitech.net>
** 
** Started on  Mon Dec 12 15:24:17 2016 Zakaria LAABID
** Last update Thu May 25 17:25:28 2017 LAABID Zakaria
*/

#include <stdlib.h>

char	**size_str_tab(char *str, char **tab, int len, char c)
{
  int	i;
  int	k;
  int	j;

  i = 0;
  j = 0;
  while (i < len)
    {
      k = 0;
      while (str[j] != c && str[j] != '\0')
	{
	  j = j + 1;
	  k = k + 1;
	}
      while (str[j] == c && str[j] != '\0')
	j = j + 1;
      if ((tab[i] = malloc(sizeof(char) * k + 2)) == NULL)
	return (NULL);
      i = i + 1;;
    }
  return (tab);
}

char	**cpy_cara_str_tab(char *str, char **tab, int len, char c)
{
  int	i;
  int	j;
  int	k;

  j = 0;
  i = 0;
  while (i < len)
    {
      k = 0;
      while (str[j] == c && str[j] != '\0')
        j = j + 1;
      while ((str[j] != c && str[j] != '\0'))
	{
	  tab[i][k] = str[j];
	  k = k + 1;
	  j = j + 1;
	}
      tab[i][k] = '\0';
      i = i + 1;
    }
  while (tab[i - 1][0] == '\0')
    i = i - 1;
  tab[i] = NULL;
  return (tab);
}

char	**wordtab(char *str, char c)
{
  char	**tab;
  int	i;
  int	len;

  len = 1;
  i = 1;
  if (str == NULL)
    return (NULL);
  if (str[0] == '\0')
    return (NULL);
  while (str[i])
    {
      if (str[i] != c && str[i - 1] == c && str[i] != '\0')
	len = len + 1;
      i = i + 1;
    }
  if ((tab = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  if ((tab = size_str_tab(str, tab, len, c)) == NULL)
    return (NULL);
  tab = cpy_cara_str_tab(str, tab, len, c);
  return (tab);
}
