/*
** map.c for Tekadventure in /home/antoine.casse/Desktop/tekadv/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 17:46:56 2017 Capitaine CASSE
** Last update Sun Apr 16 18:01:40 2017 Capitaine CASSE
*/

#include "tekadv.h"

static sfVector2i	get_size(char **map)
{
  int			i;
  int			j;
  sfVector2i		res;

  i = 0;
  j = 0;
  while (map[i][j] != EOB)
    j += 1;
  while (map[i] != NULL)
    i += 1;
  res.x = j;
  res.y = i;
  return (res);
}

int			load_map(t_game *game, t_player *ply)
{
  char			**map;
  sfVector2i		size;

  map = game->map[ply->map];
  size = get_size(map);
}
