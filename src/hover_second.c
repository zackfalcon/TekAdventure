/*
** hover_second.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Mon Apr 24 03:33:03 2017 LAABID Zakaria
** Last update Sun May 28 11:23:35 2017 Matthieu BRAULT
*/

#include "tekadv.h"

static void	hover_config4(sfRenderWindow *window, sfVector2i mouse,
			      t_menu **menu, sfVector2i x_b)
{
  if (menu[BT_ON_D]->hover == 1)
    {
      if (check_class_pos(x_b, ((sfVector2i) {411, 438}), mouse) == 1)
	sfRenderWindow_drawSprite(window, menu[BT_ON_D]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[BT_ON_D]->sprite, NULL);
    }
  else
    {
      if (check_class_pos(x_b, ((sfVector2i) {411, 438}), mouse) == 1)
	sfRenderWindow_drawSprite(window, menu[BT_OF_D]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[BT_OF_D]->sprite, NULL);
    }
}

static void	hover_config3(sfRenderWindow *window, sfVector2i mouse,
			      t_menu **menu, sfVector2i x_b)
{
  if (menu[BT_ON_B]->hover == 1)
    {
      if (check_class_pos(x_b, ((sfVector2i) {353, 372}), mouse) == 1)
	sfRenderWindow_drawSprite(window, menu[BT_ON_B]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[BT_ON_B]->sprite, NULL);
    }
  else
    {
      if (check_class_pos(x_b, ((sfVector2i) {353, 372}), mouse) == 1)
	sfRenderWindow_drawSprite(window, menu[BT_OF_B]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[BT_OF_B]->sprite, NULL);
    }
  hover_config4(window, mouse, menu, x_b);
}

void		hover_config_second(sfRenderWindow *window, sfVector2i mouse,
					    t_menu **menu)
{
  sfVector2i	x_b;

  x_b = ((sfVector2i) {730, 848});
  if (menu[BT_ON_V]->hover == 1)
    {
      if (check_class_pos(x_b, ((sfVector2i) {289, 313}), mouse) == 1)
	sfRenderWindow_drawSprite(window, menu[BT_ON_V]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[BT_ON_V]->sprite, NULL);
    }
  else
    {
      if (check_class_pos(x_b, ((sfVector2i) {289, 313}), mouse) == 1)
	sfRenderWindow_drawSprite(window, menu[BT_OF_V]->sprite_h, NULL);
      else
	sfRenderWindow_drawSprite(window, menu[BT_OF_V]->sprite, NULL);
    }
  hover_config3(window, mouse, menu, x_b);
}

static void		hover_play_second(sfRenderWindow *window,
					  sfVector2i mouse, t_menu **menu)
{
  sfVector2i		y_s;

  y_s = ((sfVector2i) {529, 562});
  if (check_class_pos(((sfVector2i) {495, 637}), y_s, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[S_FECA]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[S_FECA]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {680, 826}), y_s, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[S_ECA]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[S_ECA]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {859, 1006}), y_s, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[S_OSA]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[S_OSA]->sprite, NULL);
}

void		hover_play(sfRenderWindow *window, sfVector2i mouse,
			   t_menu **menu)
{
  sfVector2i	y_s;

  y_s = ((sfVector2i) {529, 562});
  if (check_class_pos(((sfVector2i) {270, 475}),
		      ((sfVector2i) {180, 210}), mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[BT_BACK]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[BT_BACK]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {306, 448}), y_s, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[START]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[START]->sprite, NULL);
  hover_play_second(window, mouse, menu);
}
