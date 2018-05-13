/*
** mouse_check.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon Apr 24 04:06:54 2017 LAABID Zakaria
** Last update Sun May 28 20:10:44 2017 Matthieu BRAULT
*/

#include "tekadv.h"

t_tabmouse	tabmouse[TABMOUSE_S] = {
  {(sfVector2i) {289, 313}, BT_ON_V},
  {(sfVector2i) {353, 372}, BT_ON_B},
  {(sfVector2i) {411, 438}, BT_ON_D},
};

int	my_check_exit(sfVector2i mouse_pos)
{
  if (mouse_pos.x >= 573 && mouse_pos.x <= 767 &&
	   mouse_pos.y >= 356 && mouse_pos.y <= 390)
    return (1);
  return (NORMAL);
}

int	my_config(sfRenderWindow *window, int index,
		  t_menu **menu, t_game *game)
{
  sfVector2i	x_b;
  int		i;
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  x_b = ((sfVector2i) {730, 848});
  i = 0;
  if (my_check_config(mouse_pos) == 2)
    return (index = MENU);
  if (check_class_pos(((sfVector2i) {505, 790}), ((sfVector2i)
    {480, 510}), mouse_pos) == 1)
    config_map(window, game, game->level->map->content);
  while (i < TABMOUSE_S)
    {
      if (check_class_pos(x_b, tabmouse[i].pos, mouse_pos))
	{
	  if (menu[tabmouse[i].bt]->hover == 0)
	    menu[tabmouse[i].bt]->hover = 1;
	  else
	    menu[tabmouse[i].bt]->hover = 0;
	  return (index);
	}
      i += 1;
    }
  return (index);
}

int	my_check_config(sfVector2i mouse_pos)
{
  if (mouse_pos.x >= 442 && mouse_pos.x <= 536 &&
      mouse_pos.y >= 519 && mouse_pos.y <= 595)
    return (1);
  if (mouse_pos.x >= 270 && mouse_pos.x <= 475 &&
      mouse_pos.y >= 180 && mouse_pos.y <= 210)
    return (2);
  return (NORMAL);
}
