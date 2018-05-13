/*
** conf_map_second.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun May 28 17:44:07 2017 LAABID Zakaria
** Last update Sun May 28 19:11:58 2017 Matthieu BRAULT
*/

#include "tekadv.h"
#include "config.h"

static void	map_fill_loop(t_level **level, char *conf, int index)
{
  int		j;

  j = 0;
  if ((my_strncmp(MAP_MUSIC, conf, my_strlen(MAP_MUSIC)) == 0))
    level[index]->map->music = unquote(conf + my_strlen(MAP_MUSIC) + 1);
  if ((my_strncmp(MAP_PLAYER, conf, my_strlen(MAP_PLAYER)) == 0))
    {
      level[index]->map->map_player[0] = my_atoi(conf + 12);
      while (conf[12 + j] && conf[12 + j] != ',')
	j += 1;
      j += 1;
      level[index]->map->map_player[1] = my_atoi(conf + 12 + j);
    }
}

t_level	**config_map_fill_three(t_level **level, char **conf, int index)
{
  char		*start;
  char		*end;
  int		i;
  int		y;

  i = 0;
  y = index + 1;
  if ((start = my_strcat(CONF_LEVEL, my_str_nbr(y))) == NULL ||
      (end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1))) == NULL)
    return (NULL);
  while (conf[i] != NULL && my_strncmp(start, conf[i], my_strlen(start)) != 0)
    i = i + 1;
  while (conf[i] != NULL)
    {
      map_fill_loop(level, conf[i], index);
      if ((my_strncmp(end, conf[i], my_strlen(end)) == 0))
	break;
      i++;
    }
  free_cat(start, end);
  return (level);
}

t_level	**config_map_fill_four(t_level **level, char **conf, int index)
{
  char		*start;
  char		*end;
  int		i;
  int		y;

  i = 0;
  y = index + 1;
  if ((start = my_strcat(CONF_LEVEL, my_str_nbr(y))) == NULL ||
      (end = my_strcat(CONF_LEVEL, my_str_nbr(y + 1))) == NULL)
    return (NULL);
  while (conf[i] != NULL)
    if (my_strncmp(start, conf[i++], my_strlen(start)) == 0)
      break;
  while (conf[i] != NULL)
    {
      if ((my_strncmp(MAP_DECOR, conf[i], my_strlen(MAP_DECOR)) == 0))
	level[index]->map->decor = unquote(conf[i] + my_strlen(MAP_DECOR) + 2);
      if ((my_strncmp(MAP_TILE, conf[i], my_strlen(MAP_TILE)) == 0))
	level[index]->map->tile = unquote(conf[i] + my_strlen(MAP_TILE) + 2);
      if ((my_strncmp(end, conf[i], my_strlen(end)) == 0))
	break;
      i++;
    }
  free_cat(start, end);
  return (level);
}
