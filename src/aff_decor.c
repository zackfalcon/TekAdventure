/*
** aff_decor.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Thu May 25 16:19:39 2017 Capitaine CASSE
** Last update Sun May 28 11:20:27 2017 Matthieu BRAULT
*/

#include "tekadv.h"

int		print_bg(t_game *game)
{
  sfSprite	*sprite;
  sfTexture	*texture;
  sfVector2u	size;
  sfVector2f	scale;

  if (game->level->map == NULL || game->level->map->bg == NULL)
    {
      game->bg = NULL;
      return (0);
    }
  if ((texture = sfTexture_createFromFile(game->level->map->bg, NULL)) == NULL
      || (sprite = sfSprite_create()) == NULL)
    return (1);
  size = sfTexture_getSize(texture);
  sfSprite_setTexture(sprite, texture, sfTrue);
  scale.x = (float)SCR_W / (float)size.x;
  scale.y = (float)SCR_H / (float)size.y;
  sfSprite_setScale(sprite, scale);
  sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
  game->bg = sprite;
  return (0);
}
