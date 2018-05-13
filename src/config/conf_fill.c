/*
** conf_fill.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Wed May  3 17:51:14 2017 LAABID Zakaria
** Last update Sun May 28 22:35:14 2017 LAABID Zakaria
*/

#include "config.h"
#include "tekadv.h"

static int	free_conf(char **conf)
{
  int		i;

  i = 0;
  while (conf[i])
    {
      free(conf[i]);
      i += 1;
    }
  free(conf);
  return (0);
}

int	is_here(char **conf, char *str, const int y)
{
  char		*start2;
  char		*end;
  int		i;

  i = 0;
  if ((start2 = my_strcat(CONF_LEVEL, my_str_nbr(y))) == NULL ||
      (end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1))) == NULL)
    return (FAIL);
  while (conf[i] != NULL)
    {
      if (my_strncmp(start2, conf[i], my_strlen(start2)) == 0)
	break;
      i++;
    }
  while (conf[i] != NULL)
    {
      if ((my_strncmp(str, conf[i], my_strlen(str))) == 0)
	return (0);
      if ((my_strncmp(end, conf[i], my_strlen(end))) == 0)
	return (FAIL);
      i++;
    }
  return (FAIL);
}

static void	set_conf(t_level **level, char **conf, int y)
{
  config_map_fill(level, conf, y);
  if (is_here(conf, TELEPORTER, y + 1) == 0)
    {
      if ((getconf_index(conf, TELEP_NB, y)) == 0)
	level[y]->event = NULL;
      else
	config_telep_fill(level, conf, y);
    }
  else
    level[y]->tp = NULL;
  if (is_here(conf, EVENT, y + 1) == 0)
    {
      if ((getconf_index(conf, EVENT_NB, y)) == 0)
	level[y]->event = NULL;
      else
	config_event_fill(level, conf, y);
    }
  else
    level[y]->event = NULL;
}

t_game		*config_fill(char **argv)
{
  t_game	*game;
  t_level	**level;
  char		**conf;
  int		y;

  y = 0;
  if ((game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->map_status = 0;
  if ((conf = conf_init(argv, 0, 0)) == NULL)
    return (NULL);
  if ((conf_counter(conf, CONF_LEVEL)) == 0)
    return (my_puterrnull(ERRCONF_CONF));
  if ((level = config_data(conf)) == NULL)
    return (NULL);
  while (y < conf_counter(conf, CONF_LEVEL))
    set_conf(level, conf, y++);
  if ((conf_isempty(level, conf)) == FAIL)
    return (NULL);
  game->level = build_graph(level);
  free_conf(conf);
  return (game);
}
