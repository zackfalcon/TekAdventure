/*
** hover_gesture.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun Apr 23 22:28:32 2017 LAABID Zakaria
** Last update Sun May 28 11:23:34 2017 Matthieu BRAULT
*/

#include "tekadv.h"

void		sprite_change(sfRenderWindow *window, int index,
			      t_menu **menu)
{
  sfVector2i	mouse_pos;

  mouse_pos = get_mouse_pos(window);
  set_position_button(menu);
  set_position_panels(menu);
  set_position_start(menu);
  set_position_character(menu);
  set_position_config(menu);
  set_position_config_s(menu);
  sfRenderWindow_drawSprite(window, menu[index]->sprite, NULL);
  if (index == MENU)
    {
      hover_button(window, mouse_pos, menu);
      hover_panels(window, mouse_pos, menu);
    }
  if (index == CHARAC)
    {
      hover_character(window, mouse_pos, menu);
      hover_play(window, mouse_pos, menu);
    }
  if (index == CONFIG)
    hover_config(window, mouse_pos, menu);
}

void		hover_config(sfRenderWindow *window, sfVector2i mouse,
			     t_menu **menu)
{
  hover_config_second(window, mouse, menu);
  if (check_class_pos(((sfVector2i) {597, 700})
		      , ((sfVector2i) {536, 560}), mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[BT_SAVE]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[BT_SAVE]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {270, 475}),
		      ((sfVector2i) {180, 210}), mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[BT_BACK]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[BT_BACK]->sprite, NULL);
}
