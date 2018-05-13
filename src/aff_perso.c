/*
** aff_perso.c for tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Wed Apr 26 18:52:38 2017 Capitaine CASSE
** Last update Sun May 28 11:50:56 2017 Capitaine CASSE
*/

#include <unistd.h>
#include "tekadv.h"

int		resize_player(sfTexture *texture,
			      t_game *game, sfRenderWindow *window)
{
  sfVector2i	pos;

  pos.x = SCR_W / 2 + game->ply->pos.x * game->tile.x / 2 -
    game->ply->pos.y * game->tile.y / 2;
  pos.y = game->ply->pos.x * game->tile.x / 2
    + game->ply->pos.y * game->tile.y / 2;
}

int		draw_static(sfTexture *texture, t_game *game,
			    sfRenderWindow *window)
{
  static int	pos = 0;
  sfIntRect	rect;
  sfSprite	*sprite;

  sprite = sfSprite_create();
  rect.y1 = SIZE_PLY * game->ply->class;
  rect.x1 = SIZE_PLY * pos;
  rect.y2 = rect.y1 + SIZE_PLY;
  rect.x2 = rect.x2 + SIZE_PLY;
  sfSprite_setTextureRect(sprite, rect);
  resize_player(texture, game, window);
  sfRenderWindow_drawSprite(window, sprite);
  pos += 1;
  if (pos == 8)
    pos = 0
}

int		aff_player(sfRenderWindow *window, t_game *game)
{
  sfTexture	*tex;

  tex = sfTexture_createFromFile(TEXPLY, NULL);
  if (status == 0)
    draw_static(tex, game, window);
  sfTexture_destroy(tex);
  return (0);
}
