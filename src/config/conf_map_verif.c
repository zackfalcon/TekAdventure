/*
** conf_map_verif.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun May 28 15:27:52 2017 LAABID Zakaria
** Last update Sun May 28 19:10:55 2017 LAABID Zakaria
*/

#include <fcntl.h>
#include "config.h"
#include "tekadv.h"

static int	check_dotfile(char *file)
{
  int	i;

  i = 0;
  while (file[i] != '\0')
    {
      if (file[i] == '.')
	return (i);
      i++;
    }
  return (my_puterr(BAD_EXTENSION, FAIL));
}

int	verif_conf_open(char *path, char *type)
{
  int	fd;
  int	status;

  if ((status = check_dotfile(path)) == FAIL)
    return (FAIL);
  if ((my_strncmp(path + status, type, my_strlen(type))) == 0)
    return (NORMAL);
  else
    return (my_puterr(BAD_EXTENSION, FAIL));
  if ((fd = open(path, O_RDONLY)) == FAIL)
    return (FAIL);
  close(fd);
  return (0);
}

int	map_verif_second(t_map *map)
{
  if (map->music == NULL)
    return (my_puterr(ERR_MAP_MUSIC, FAIL));
  else
    if ((verif_conf_open(map->music, MUSIC_EXT)) == FAIL)
      return (my_puterr(ERR_MUSIC_PATH, FAIL));
  if (map->tile == NULL)
    return (my_puterr(ERR_MAP_TILE, FAIL));
  else
    if ((verif_conf_open(map->tile, PIC_EXT)) == FAIL)
      return (my_puterr(ERR_TILE_PATH, FAIL));
  if (map->name == NULL)
    return (my_puterr(ERR_MAP_NAME, FAIL));
  return (0);
}

int	map_verif(t_map *map)
{
  if (map->bg == NULL)
    return (my_puterr(ERR_MAP_BG, FAIL));
  else
    if ((verif_conf_open(map->bg, PIC_EXT)) == FAIL)
      return (my_puterr(ERR_BG_PATH, FAIL));
  if (map->content == NULL)
    return (my_puterr(ERR_MAP_CONT, FAIL));
  if (map->decor == NULL)
    return (my_puterr(ERR_MAP_DECOR, FAIL));
  else
    if ((verif_conf_open(map->decor, PIC_EXT)) == FAIL)
      return (my_puterr(ERR_DECOR_PATH, FAIL));
  return (0);
}
