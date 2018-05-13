/*
** conf_verif.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Thu May 25 15:49:35 2017 LAABID Zakaria
** Last update Sun May 28 19:28:38 2017 Matthieu BRAULT
*/

#include <tekadv.h>
#include "config.h"

static int	conf_line(char **conf)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (conf[i] != NULL)
    {
      if (conf[i][0] != '#')
	count++;
      i++;
    }
  return (count);
}

int		is_commentary(char **conf)
{
  int		y;

  y = 0;
  while (conf[y] != NULL)
    {
      if (conf[y][0] == '#')
	return (1);
      y++;
    }
  return (0);
}

char		**del_commentary(char **conf)
{
  char		**new_conf;
  int		y;
  int		x;

  y = 0;
  x = 0;
  if ((is_commentary(conf)) == 0)
    return (conf);
  if ((new_conf = malloc(sizeof(char *) * (conf_line(conf) + 1))) == NULL)
    return (my_puterrnull(ERRCONF_DEL));
  while (conf[y] != NULL)
    {
      if (conf[y][0] != '#')
	{
	  if ((new_conf[x] = my_strdup(conf[y])) == NULL)
	    return (my_puterrnull(ERRCONF_DEL));
	  free(conf[y]);
	  x++;
	}
      y++;
    }
  new_conf[x] = NULL;
  free(conf);
  return (new_conf);
}
