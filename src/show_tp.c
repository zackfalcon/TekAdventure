/*
** show_tp.c for tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun May 28 16:52:44 2017 Capitaine CASSE
** Last update Sun May 28 20:25:55 2017 Capitaine CASSE
*/

#include "tekadv.h"

static int	draw_tp(t_game *game, t_tp **tp, sfRenderWindow *window, int i)
{
  sfSprite	*sprite;
  sfTexture	*tex;
  sfVector2u	size;
  sfVector2f	scale;

  if ((sprite = sfSprite_create()) == NULL ||
      (tex = sfTexture_createFromFile(game->level->map->tile, NULL)) == NULL)
    return (0);
  sfSprite_setTexture(sprite, tex, sfTrue);
  size = sfTexture_getSize(tex);
  scale = (sfVector2f) {(float)game->tile.x / size.x,
			(float)game->tile.y / size.y};
  sfSprite_setScale(sprite, scale);
  sfSprite_setOrigin(sprite, (sfVector2f){(float)size.x / 2,
	(float)size.y / 2});
  while (tp[i] != NULL)
    {
      sfSprite_setPosition(sprite, convert_pos((sfVector2i) {tp[i]->coords[0],
	      tp[i]->coords[1]}, game->tile));
      sfRenderWindow_drawSprite(window, sprite, NULL);
      i += 1;
    }
  sfSprite_destroy(sprite);
  sfTexture_destroy(tex);
  return (0);
}

int		show_tp(t_game *game, t_player *player, sfRenderWindow *window)
{
  int		i;
  t_event	**event;

  event = game->level->event;
  i = 0;
  if (event != NULL)
    {
      while (event[i] != NULL)
	{
	  if (event[i]->pnj && !event[i]->active)
	    return (0);
	  i += 1;
	}
    }
  if (game->level->tp != NULL)
    draw_tp(game, game->level->tp, window, 0);
  check_pos(player, game);
  return (0);
}
