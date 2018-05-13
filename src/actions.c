/*
** actions.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat Apr 22 19:50:07 2017 Capitaine CASSE
** Last update Sun May 28 11:28:28 2017 Matthieu BRAULT
*/

#include "tekadv.h"

void	        set_position_config_s(t_menu **menu)
{
  menu[BT_OF_V]->pos = ((sfVector2f) {735.0, 287.0});
  menu[BT_OF_B]->pos = ((sfVector2f) {735.0, 344.0});
  menu[BT_OF_D]->pos = ((sfVector2f) {735.0, 410.0});
  sfSprite_setPosition(menu[BT_OF_V]->sprite, menu[BT_OF_V]->pos);
  sfSprite_setPosition(menu[BT_OF_V]->sprite_h, menu[BT_OF_V]->pos);
  sfSprite_setPosition(menu[BT_OF_B]->sprite, menu[BT_OF_B]->pos);
  sfSprite_setPosition(menu[BT_OF_B]->sprite_h, menu[BT_OF_B]->pos);
  sfSprite_setPosition(menu[BT_OF_D]->sprite, menu[BT_OF_D]->pos);
  sfSprite_setPosition(menu[BT_OF_D]->sprite_h, menu[BT_OF_D]->pos);
}

sfVector2f	get_mult_size(sfVector2i size, sfVector2i tile)
{
  sfVector2f	res;

  res.y = (float)((float)tile.y * 3 / (float)size.y);
  res.x = (float)res.y;
  return (res);
}

sfVector2f	convert_pos(sfVector2i pos, sfVector2i tile)
{
  sfVector2f	res;

  res.x = (float)SCR_W / 2;
  res.y = 0.0;
  res.x += (float)((pos.x - pos.y) * tile.x / 2);
  res.y += (float)((pos.x + pos.y + 1) * tile.y / 2);
  return (res);
}

sfVector2i	project_pos(sfVector2f pos, sfVector2i tile)
{
  sfVector2i	grid;

  pos.x -= SCR_W / 2;
  grid.x = (int)(pos.x / ((float)tile.x / 2) + pos.y / ((float)tile.y / 2))
    / 2;
  grid.y = (int)(pos.y / ((float)tile.y / 2) - pos.x / ((float)tile.x / 2))
    / 2;
  return (grid);
}

sfVector2i	raw_click(t_game *game, sfRenderWindow *window)
{
  sfVector2i	pos;
  sfVector2i	grid;
  sfVector2i	tile;

  tile = game->tile;
  pos = sfMouse_getPositionRenderWindow(window);
  pos.x -= SCR_W / 2;
  grid.x = (int)(pos.x / ((float)tile.x / 2) + pos.y / ((float)tile.y / 2))
    / 2;
  grid.y = (int)(pos.y / ((float)tile.y / 2) - pos.x / ((float)tile.x / 2))
    / 2;
  return (grid);
}
