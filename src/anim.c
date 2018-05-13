/*
** anim.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Wed May  3 16:03:43 2017 Matthieu BRAULT
** Last update Sun May 28 23:26:15 2017 Matthieu BRAULT
*/

#include <math.h>
#include <stdlib.h>
#include "tekadv.h"

int	my_move(sfRenderWindow *window, t_game *game, t_player *player)
{
  sfSprite	*sprite;
  sfVector2f	vector;
  sfVector2f	pos;

  vector = get_vector(game, player);
  vector.x = vector.x / 20.0;
  vector.y = vector.y / 20.0;
  pos = convert_pos(player->pos, game->tile);
  pos.x += (float)(player->s * vector.x);
  pos.y += (float)(player->s * vector.y);
  player->s += 1;
  if (!(player->s % 10))
    player->sprt += 1;
  if (player->sprt > 5)
    player->sprt = 0;
  sprite = get_static_char(game->player->spriteboard, (sfVector2i)
			   {player->sprt, player->dir}, game, ((sfVector2i) {6, 8}));
  sfSprite_setPosition(sprite, pos);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfSprite_destroy(sprite);
  if (player->s == 20)
    return (0);
  return (1);
}

sfVector2f	get_vector(t_game *game, t_player *player)
{
  sfVector2f	vector;
  sfVector2f	sides[2];
  sfVector2i	dec;

  sides[0] = convert_pos(player->pos, game->tile);
  sides[1] = convert_pos(player->next, game->tile);
  vector = (sfVector2f) {sides[1].x - sides[0].x, sides[1].y - sides[0].y};
  dec.x = player->next.x - player->pos.x;
  dec.y = player->next.y - player->pos.y;
  if (dec.x > 0 && dec.y == 0)
    player->dir = 1;
  else if (dec.x == 0 && dec.y > 0)
    player->dir = 3;
  else if (dec.y < 0 && dec.x == 0)
    player->dir = 7;
  else if (dec.x < 0 && dec.y == 0)
    player->dir = 5;
  return (vector);
}
