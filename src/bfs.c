/*
** bfs.c for tekadventure in /home/antoine.casse/Desktop/tmp/astar
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat May  6 21:18:46 2017 Capitaine CASSE
** Last update Thu Dec 28 15:00:34 2017 LAABID Zakaria
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include "tekadv.h"

t_list	tablist[4] = {
  {0, 1, NULL, NULL},
  {0, -1,  NULL, NULL},
  {1, 0, NULL, NULL},
  {-1, 0, NULL, NULL},
};

static int	remove_list(t_list **list, t_list *rm)
{
  t_list	*past;

  if (*list == rm)
    {
      *list = rm->next;
      return (0);
    }
  past = *list;
  while (past->next != rm && past->next != NULL)
    past = past->next;
  past->next = past->next->next;
  return (0);
}

static t_list	*add2list(int x, int y, t_list *old, t_list *past)
{
  t_list        *list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->x = x;
  list->y = y;
  list->next = old;
  if (old == NULL)
    list->links = NULL;
  else
    {
      if ((list->links = malloc(sizeof(t_list))) == NULL)
	return (NULL);
      list->links->links = past;
      list->links->x = past->x;
      list->links->y = past->y;
      list->links->next = past->links;
    }
  return (list);
}

static char	find_next(t_list **list, int **map,
			  sfVector2i dest, t_list *pos)
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if (map[pos->y + tablist[i].y][pos->x + tablist[i].x] > 0 &&
	  map[pos->y + tablist[i].y][pos->x + tablist[i].x] >
	  map[pos->y][pos->x] + 1)
	{
	  *list = add2list(pos->x + tablist[i].x,
			   pos->y + tablist[i].y, *list, pos);
	  map[pos->y + tablist[i].y][pos->x + tablist[i].x] =
	    map[pos->y][pos->x] + 1;
	  if ((*list)->x == dest.x && (*list)->y == dest.y)
	    return (1);
	}
      i += 1;
    }
  remove_list(list, pos);
  return (0);
}

static int	free_list(t_list *list)
{
  t_list	*pars;

  while (list != NULL)
    {
      pars = list;
      list = list->next;
      free(pars);
    }
  return (0);
}

sfVector2i	bfs_find(int **map, sfVector2i pos, sfVector2i dest)
{
  t_list	*list;
  t_list	*pars;
  sfVector2i	final;

  if (pos.x == dest.x && pos.y == dest.y)
    return ((sfVector2i) {pos.x - 1, pos.y - 1});
  list = add2list(pos.x, pos.y, NULL, NULL);
  map[list->y][list->x] = 0;
  while (list != NULL && (list->x != dest.x || list->y != dest.y))
    {
      pars = list;
      while (pars != NULL)
	{
	  if (find_next(&list, map, dest, pars))
	    break ;
	  pars = pars->next;
	}
    }
  if (list == NULL)
    return ((sfVector2i) {-1, -1});
  final = (sfVector2i) {list->links->x - 1, list->links->y - 1};
  free_list(list);
  return (final);
}
