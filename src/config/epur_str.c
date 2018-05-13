/*
** epur_str.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May 22 17:08:11 2017 LAABID Zakaria
** Last update Sun May 28 13:18:23 2017 Matthieu BRAULT
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "config.h"

static int	get_size(char *str)
{
  int		i;
  int		nb;
  char		stop;

  i = 0;
  nb = 0;
  stop = 1;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v')
	{
	  if (!stop)
	    {
	      nb += 1;
	      stop = 1;
	    }
	  nb += 1;
	}
      else
	stop = 0;
      i += 1;
    }
  return (nb);
}

static void	fill_str(char *res, char *str)
{
  char		stop;
  int		i;
  int		j;

  stop = 1;
  i = 0;
  j = 0;
  while (str[i])
     {
       if (str[i] != ' ' && str[i] != '\t' && str[i] != '\v')
         {
           if (!stop)
             {
               res[j++] = ' ';
               stop = 1;
             }
           res[j++] = str[i];
         }
       else
         stop = 0;
       i += 1;
     }
}

char		*epur_str(char *str)
{
  char		*res;
  int		nb;

  if (str == NULL)
    return (NULL);
  while (*str == ' ' || *str == '\t' || *str == '\v')
    str += 1;
  nb = get_size(str);
  if ((res = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (NULL);
  res[nb] = 0;
  fill_str(res, str);
  return (res);
}
