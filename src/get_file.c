/*
** get_file.c for Tekadventure in /home/antoine.casse/Desktop/tekadv
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 13:41:02 2017 Capitaine CASSE
** Last update Tue Apr 25 13:29:23 2017 Capitaine CASSE
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tekadv.h"

static int	get_specs(char *line, int *specs)
{
  int		i;

  i = 0;
  if ((specs[0] = my_atoi(line)) <= 0)
    return (my_puterr(INV_SPECS, 1));
  while (line[i] >= '0' && line[i] <= '9')
    i += 1;
  line += 1;
  if ((specs[1] = my_atoi(line + i)) <= 0)
    return (my_puterr(INV_SPECS, 1));
  return (0);
}

static int	*get_line(char *tmp, int size)
{
  int		*res;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(int) * (size + 1))) == NULL)
    return (NULL);
  while (tmp[i] && j < size)
    {
      res[j] = my_atoi(tmp + i);
      while (tmp[i] >= '0' && tmp[i] <= '9')
	i += 1;
      if (tmp[i])
	i += 1;
      j += 1;
    }
  if (tmp[i] || j < size)
    {
      my_puterr(INV_MAP, 0);
      return (NULL);
    }
  res[j] = EOB;
  return (res);
}

static int	get_map(t_game *game, int fd)
{
  char		*tmp;
  int		size[2];
  static int	lvl = 0;
  int		l;

  if ((tmp = get_next_line(fd)) == NULL)
    return (1);
  if (get_specs(tmp, size))
    return (1);
  if ((game->map[lvl] = malloc(sizeof(int *) * (size[0] + 1))) == NULL)
    return (1);
  game->map[lvl][size[0]] = NULL;
  free(tmp);
  l = 0;
  while (l < size[0] && (tmp = get_next_line(fd)) != NULL)
    {
      if ((game->map[lvl][l] = get_line(tmp, size[1])) == NULL)
	return (1);
      l += 1;
      free(tmp);
    }
  if (l < size[0])
    return (my_puterr(INV_MAP, 1));
  lvl += 1;
  return (0);
}

t_game		*get_file(char *file)
{
  int		fd;
  char		*tmp;
  t_game	*game;
  int		specs[2];

  if ((fd = open(file, O_RDONLY)) < 0 ||
      (game = malloc(sizeof(t_game))) == NULL)
    return (NULL);
  game->enemies = NULL;
  if ((tmp = get_next_line(fd)) == NULL || get_specs(tmp, specs))
    return (NULL);
  if ((game->map = malloc(sizeof(int **) * (specs[0] + 1))) == NULL)
    return (NULL);
  game->map[specs[0]] = NULL;
  while ((tmp = get_next_line(fd)) != NULL)
    {
      if (tmp[0] != '#')
	{
	  if (tmp[0] == '*')
	    if (get_map(game, fd))
	      return (NULL);
	}
      free(tmp);
    }
  return (game);
}
