/*
** build_graph.c for tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Fri May 26 12:20:02 2017 Capitaine CASSE
** Last update Sun May 28 12:14:03 2017 Matthieu BRAULT
*/

#include "tekadv.h"

static t_level		*find_link(t_level **act, char *name)
{
  int			i;

  while (*name && *name != '-')
    name++;
  if (!(*name))
    return (NULL);
  i = 0;
  while (act[i] != NULL && my_strcmp((act[i])->map->name, name + 1))
    i += 1;
  return (act[i]);
}

t_level		*build_graph(t_level **act)
{
  int		i;
  int		j;
  t_level	*graph;

  graph = *act;
  i = 0;
  while (act[i] != NULL)
    {
      j = 0;
      if ((act[i])->tp != NULL)
	{
	  while ((act[i])->tp[j] != NULL)
	    {
 	      act[i]->tp[j]->room = find_link(act, act[i]->tp[j]->next_map);
	      if (act[i]->tp[j]->room != NULL)
		act[i]->map->content[act[i]->tp[j]->coords[1]]
		  [act[i]->tp[j]->coords[0]] = 2;
	      j = j + 1;
	    }
	}
      i += 1;
    }
  free(act);
  return (graph);
}
