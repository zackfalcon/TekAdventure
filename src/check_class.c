/*
** check_class.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Fri Apr 21 23:25:04 2017 Matthieu BRAULT
** Last update Tue May  2 15:00:37 2017 Matthieu BRAULT
*/

#include "tekadv.h"

int	check_class_pos(sfVector2i x, sfVector2i y, sfVector2i mouse)
{
  if (mouse.x >= x.x && mouse.x <= x.y && mouse.y >= y.x && mouse.y <= y.y)
    return (1);
  else
    return (0);
}

int		my_check_class(sfRenderWindow *window, t_player *player)
{
  sfVector2i	mouse_pos;
  sfVector2i	y;

  mouse_pos = get_mouse_pos(window);
  y = ((sfVector2i) {535, 561});
  if (check_class_pos(((sfVector2i) {306, 448}), y, mouse_pos) == 1)
    get_iop(player);
  else if (check_class_pos(((sfVector2i) {495, 637}), y, mouse_pos) == 1)
    get_feca(player);
  else if (check_class_pos(((sfVector2i) {680, 826}), y, mouse_pos) == 1)
    get_ecaflip(player);
  else if (check_class_pos(((sfVector2i) {859, 1006}), y, mouse_pos) == 1)
    get_osa(player);
  else
    return (0);
  player->classe_texture = sfTexture_createFromFile(CLASSE_BOARD, NULL);
  return (1);
}
