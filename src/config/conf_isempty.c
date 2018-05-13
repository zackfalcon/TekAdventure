/*
** conf_isempty.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun May 28 14:53:41 2017 LAABID Zakaria
** Last update Sun May 28 20:35:32 2017 Capitaine CASSE
*/

#include <fcntl.h>
#include "config.h"
#include "tekadv.h"

int	conf_isempty(t_level **level, char **conf)
{
  int	y;
  int	x;

  y = 0;
  while (y < conf_counter(conf, CONF_LEVEL))
    {
      if ((map_verif(level[y]->map)) == FAIL ||
	  (map_verif_second(level[y]->map)) == FAIL)
	return (FAIL);
      x = 0;
      while (x < getconf_index(conf, TELEP_NB, y))
	{
	  if ((teleporter_verif(level[y]->tp, x, y)) == FAIL)
	    return (FAIL);
	  if (level[y]->event != NULL)
	    {
	      if ((event_verif(level[y]->event, x, y)) == FAIL ||
		  (event_verif_second(level[y]->event, x, y)) == FAIL)
		return (FAIL);
	    }
	  x++;
	}
      y++;
    }
  return (0);
}
