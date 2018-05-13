/*
** conf_events_utils.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon May  8 00:39:58 2017 LAABID Zakaria
** Last update Sun May 28 19:00:02 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include "config.h"

int		config_event_goto(char *start, char **conf, int y)
{
  char		*start2;
  char		*end;
  int		i;

  i = 0;
  y++;
  if ((start2 = my_strcat(CONF_LEVEL, my_str_nbr(y))) == NULL ||
      (end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1))) == NULL)
    return (-1);
  while (conf[i] != NULL)
    {
      if (my_strncmp(start2, conf[i], my_strlen(start2)) == 0)
	break ;
      i++;
    }
  while (conf[i] != NULL)
    {
      if ((my_strncmp(start, conf[i], my_strlen(start))) == 0)
	return (i);
      if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	break ;
      i++;
    }
  free_cat(start2, end);
  return (i);
}

static void	config_event_one(t_level **level, char **conf, int x, int y)
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
	      if (my_strncmp(EVENT_NAME, conf[i], L_NAME) == 0)
		level[y]->event[x - 1]->name = unquote((conf[i] + L_NAME + 2));
	      if (my_strncmp(EVENT_TEXT, conf[i], L_TEXT) == 0)
		level[y]->event[x - 1]->texture = unquote((conf[i] + L_TEXT + 2));
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

static void	config_event_two(t_level **level, char **conf, int x, int y)
{
  char		*start;
  char		*end;
  int		i;

  while (x <= getconf_index(conf, EVENT_NB, y))
    {
      if ((start = my_strcat(EVENT_TYPE, my_str_nbr(x))) != NULL &&
	  (end = my_strcat(EVENT_TYPE, my_str_nbr(x++ + 1))) != NULL &&
	  (i = config_event_goto(start, conf, y)) != -1)
	{
	  while (conf[i] != NULL)
	    {
	      if (my_strncmp(EVENT_COORD, conf[i], L_COORD) == 0)
		{
		  level[y]->event[x - 2]->coords[0] = my_atoi(conf[i] + 8);
		  level[y]->event[x - 2]->coords[1] = my_atoi(conf[i] + 10);
		}
	      else if ((my_strncmp(CONF_LEVEL, conf[i], L_CONF)) == 0
		       || my_strncmp(end, conf[i], my_strlen(end)) == 0)
		break ;
	      i++;
	    }
	  free_cat(start, end);
	}
    }
}

int		config_event_fill(t_level **level, char **conf, int y)
{
  int		x;

  x = 1;
  config_event_one(level, conf, x, y);
  config_event_two(level, conf, x, y);
  config_event_three(level, conf, x, y);
  config_event_four(level, conf, x, y);
  return (0);
}
