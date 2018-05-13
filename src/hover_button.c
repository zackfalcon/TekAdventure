/*
** hover_button.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun Apr 23 22:16:56 2017 LAABID Zakaria
** Last update Mon Apr 24 04:21:22 2017 LAABID Zakaria
*/

#include "tekadv.h"

void		hover_button(sfRenderWindow *window,
			     sfVector2i mouse, t_menu **menu)
{
  sfVector2i	x_b;

  x_b = ((sfVector2i) {573, 767});
  if (check_class_pos(x_b, ((sfVector2i) {248, 279}), mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[PLAY]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[PLAY]->sprite, NULL);
  if (check_class_pos(x_b, ((sfVector2i) {356, 390}), mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[CLOSE]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[CLOSE]->sprite, NULL);
  sfRenderWindow_drawSprite(window, menu[MULTI]->sprite, NULL);
}

void		hover_character(sfRenderWindow *window,
				sfVector2i mouse, t_menu **menu)
{
  sfVector2i	y_s;

  y_s = ((sfVector2i) {529, 562});
  if (check_class_pos(((sfVector2i) {306, 448}), y_s, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[IOP]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[IOP]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {495, 637}), y_s, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[FECA]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[FECA]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {680, 826}), y_s, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[ECA]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[ECA]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {859, 1006}), y_s, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[OSA]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[OSA]->sprite, NULL);
}

void		hover_panels(sfRenderWindow *window,
			     sfVector2i mouse, t_menu **menu)
{
  sfVector2i	y_p;

  y_p = ((sfVector2i) {501, 582});
  if (check_class_pos(((sfVector2i) {451, 532}), y_p, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[OPTION]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[OPTION]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {605, 705}), y_p, mouse) == 1)
    sfRenderWindow_drawSprite(window, menu[SHOP]->sprite_h, NULL);
  else
    sfRenderWindow_drawSprite(window, menu[SHOP]->sprite, NULL);
  if (check_class_pos(((sfVector2i) {785, 880}), y_p, mouse) == 1)
    {
      sfRenderWindow_drawSprite(window, menu[NEWS]->sprite_h, NULL);
      sfRenderWindow_drawSprite(window, menu[NEWS]->sprite , NULL);
    }
  else
    sfRenderWindow_drawSprite(window, menu[NEWS]->sprite, NULL);
}
