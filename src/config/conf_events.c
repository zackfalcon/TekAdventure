/*
** conf_events.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun May 28 17:50:28 2017 LAABID Zakaria
** Last update Sun May 28 23:31:51 2017 Capitaine CASSE
*/

#include "tekadv.h"
#include "config.h"

void	config_event_three(t_level **level, char **conf, int x, int y)
{
  char		*start;
  char		*end;
  int		i;

  while (x <= getconf_index(conf, EVENT_NB, y))
    {
      if ((start = my_strcat(EVENT_TYPE, my_str_nbr(x))) != NULL &&
	  (end = my_strcat(EVENT_TYPE, my_str_nbr(x + 1))) != NULL &&
	  (i = config_event_goto(start, conf, y)) != -1)
	{
	  while (conf[i] != NULL)
	    {
	      if (my_strncmp(EVENT_DIALOG, conf[i], L_DIALOG) == 0)
		level[y]->event[x - 1]->dialog = unquote((conf[i] + L_DIALOG + 2));
	      if (my_strncmp(EVENT_QUEST, conf[i], L_QUEST) == 0)
		level[y]->event[x - 1]->quest_pic = unquote((conf[i] + L_QUEST + 2));
	      else if ((my_strncmp(CONF_LEVEL, conf[i], L_CONF)) == 0 ||
		       my_strncmp(end, conf[i], my_strlen(end)) == 0)
		break ;
	      i++;
	    }
	  free_cat(start, end);
	}
      x++;
    }
}

void	config_event_four(t_level **level, char **conf, int x, int y)
{
  char		*start;
  char		*end;
  int		i;

  while (x <= getconf_index(conf, EVENT_NB, y))
    {
      if ((start = my_strcat(EVENT_TYPE, my_str_nbr(x))) != NULL &&
	  (end = my_strcat(EVENT_TYPE, my_str_nbr(x + 1))) != NULL &&
	  (i = config_event_goto(start, conf, y)) != -1)
	    {
	      while (conf[i] != NULL)
		{
		  level[y]->event[x - 1]->active = 0;
		  if (my_strncmp(EVENT_PNJ, conf[i], L_PNJ) == 0)
		    level[y]->event[x - 1]->pnj = my_atoi((conf[i] + L_PNJ + 1));
		  else if ((my_strncmp(CONF_LEVEL, conf[i], L_CONF)) == 0 ||
			   my_strncmp(end, conf[i], my_strlen(end)) == 0)
		    break ;
		  i++;
		}
	      free_cat(start, end);
	    }
      x++;
    }
}
