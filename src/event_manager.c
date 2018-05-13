/*
** event_manager.c for tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sat May 27 12:39:42 2017 Capitaine CASSE
** Last update Sun May 28 19:34:06 2017 Matthieu BRAULT
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "tekadv.h"

static char	*get_dialog(char *file, int i)
{
  int		fd;
  char		*tmp;
  char		*str;

  if ((fd = open(file, O_RDONLY)) < 0)
    return (NULL);
  while ((str = get_next_line(fd)) != NULL && --i > 0)
    free(str);
  if (str != NULL)
    {
      while ((tmp = get_next_line(fd)) != NULL)
	free(tmp);
    }
  close(fd);
  return (str);
}

static int	show_dialog(sfRenderWindow *window, t_event *event,
			    char *dialogfile, t_game *game)
{
  sfText	*text;
  char		*dialog;

  if ((dialog = get_dialog(dialogfile, event->actions)) == NULL)
    {
      event->actions = 0;
      event->active = 1;
      return (0);
    }
  if (!my_strcmp(dialog, STR_END) && (game->end = 1))
    {
      free(dialog);
      return (0);
    }
  if ((text = sfText_create()) == NULL)
    return (1);
  sfText_setString(text, dialog);
  sfText_setFont(text, game->font);
  sfText_setCharacterSize(text, 20);
  sfText_setPosition(text, (sfVector2f) {SCR_W - ((SCR_W/3) * 2) - 90, SCR_H -
	(SCR_H / 5) - SCR_H / 14});
  sfRenderWindow_drawText(window, text, NULL);
  sfText_destroy(text);
  free(dialog);
  return (0);
}

static int	set_character(t_game *game, t_event *event,
			      sfRenderWindow *window)
{
  sfTexture     *tex;
  sfVector2f    mult_size;
  sfVector2u    size;
  sfVector2i    pnj_pos;
  sfSprite      *sprite;

  if (event == NULL || event->texture == NULL)
    return (1);
  if ((tex = sfTexture_createFromFile(event->texture, NULL)) == NULL ||
      (sprite = sfSprite_create()) == NULL)
    return (1);
  size = sfTexture_getSize(tex);
  sfSprite_setTexture(sprite, tex, sfTrue);
  mult_size = get_mult_size(((sfVector2i)
    {(int)(size.x), (int)(size.y)}), game->tile);
  sfSprite_setScale(sprite, mult_size);
  pnj_pos = (sfVector2i) {event->coords[0], event->coords[1]};
  sfSprite_setOrigin(sprite, (sfVector2f) {size.x / 2, 4 * size.y / 5});
  sfSprite_setPosition(sprite, convert_pos(pnj_pos, game->tile));
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfTexture_destroy(tex);
  sfSprite_destroy(sprite);
  return (0);
}

static int	show_quest(t_event *event, t_game *game, sfRenderWindow *window)
{
  sfVector2i	pos;

  if (!(event->stop[0]) && sfMouse_isButtonPressed(sfMouseLeft))
     {
       pos = raw_click(game, window);
       event->stop[0] = 1;
       if (pos.x == event->coords[0] && pos.y == event->coords[1])
         event->actions += 1;
     }
   else if (!sfMouse_isButtonPressed(sfMouseLeft))
     event->stop[0] = 0;
   if (event->actions && sfKeyboard_isKeyPressed(sfKeySpace)
       && !(event->stop[1]))
     {
       event->stop[1] = 1;
       event->actions += 1;
     }
   else if (!sfKeyboard_isKeyPressed(sfKeySpace))
     event->stop[1] = 0;
   if (event->actions)
     {
       set_quest_disp(window, event);
       show_dialog(window, event, event->dialog, game);
     }
   return (0);
}

int		show_events(sfRenderWindow *window, t_game *game, t_event **event)
{
  int		i;

  i = 0;
  if (event == NULL)
    return (0);
  while (event[i] != NULL)
    {
      set_character(game, event[i], window);
      show_quest(event[i], game, window);
      i += 1;
    }
  return (0);
}
