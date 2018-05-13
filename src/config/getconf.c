/*
** getconf.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 22:16:37 2017 LAABID Zakaria
** Last update Sat Jun  3 09:58:46 2017 LAABID Zakaria
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int	find_to_zero(int nb_sub)
{
  int	i;

  i = 0;
  while (nb_sub != 0)
    {
      nb_sub = (nb_sub / 10);
      i++;
    }
  return (i);
}

char	*my_str_nbr(int nb)
{
  char	*nbr;
  int	i;
  int	x;
  int	k;

  x = 0;
  k = 0;
  i = find_to_zero(nb);
  if ((nbr = malloc(sizeof(char) * i + 1)) == NULL)
    return (NULL);
  while (k != i)
    {
      if (nb < 0)
	return (NULL);
      if (nb < 10)
	nbr[x++] = ('0' + nb);
      else
	{
	  my_put_nbr(nb / 10);
	  my_put_nbr(nb % 10);
	}
      k++;
    }
  nbr[x] = '\0';
  return (nbr);
}

static int	getconf_second(char *start, char *end, char **conf, char *str)
{
  int		conf_second;
  int		size_str;
  int		index;

  index = 0;
  size_str = my_strlen(str);
  while (conf[index] != NULL)
    {
      if (my_strncmp(start, conf[index], my_strlen(start)) == 0)
	break ;
      index++;
    }
  while (conf[index] != NULL)
    {
      if (my_strncmp(str, conf[index], size_str) == 0)
	{
	  conf_second = my_atoi(epur_str((char *)
					   (conf[index] + size_str)));
	  return (conf_second);
	}
      if (my_strncmp(end, conf[index], my_strlen(end)) == 0)
	return (0);
      ++index;
    }
  return (0);
}

int	getconf_index(char **conf, char *str, int i)
{
  char	*start;
  char	*end;

  i++;
  start = my_strcat(CONF_LEVEL, my_str_nbr(i));
  end = my_strcat(CONF_LEVEL, my_str_nbr(i + 1));
  if (conf_counter(conf, CONF_LEVEL) == 1)
    return (my_atoi(epur_str(getconf(conf, str))));
  return (getconf_second(start, end, conf, str));
}
