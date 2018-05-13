/*
** loop.c for Tekadventure in /home/antoine.casse/Desktop/tekadventure
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Sun Apr 16 14:20:28 2017 Capitaine CASSE
** Last update Sun May 28 23:25:36 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tekadv.h"

static int	load_screen(sfRenderWindow *window, t_menu **menu, int s)
{
  sfClock	*clock;

  s = 0;
  clock = sfClock_create();
  sfMusic_stop(menu[MENU]->music);
  music_change(LOAD_ONE, menu);
  while (s <= 9)
    {
      sfRenderWindow_clear(window, sfWhite);
      if (s % 3 == 0)
	sfRenderWindow_drawSprite(window, menu[LOAD_THREE]->sprite, NULL);
      else if ((s + 2) % 3 == 0)
	sfRenderWindow_drawSprite(window, menu[LOAD_TWO]->sprite, NULL);
      else if ((s + 1) % 3 == 0)
	sfRenderWindow_drawSprite(window, menu[LOAD_ONE]->sprite, NULL);
      sfRenderWindow_display(window);
      if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.5f)
	{
	  sfClock_restart(clock);
	  s = s + 1;
	}
    }
  sfClock_destroy(clock);
  sfMusic_stop(menu[LOAD_ONE]->music);
  return (1);
}

static int		draw_game(t_player *player, sfRenderWindow *window,
				  t_game *game, sfClock *clock)
{
  sfRenderWindow_clear(window, sfWhite);
  sfClock_restart(clock);
  if (game->m == 0)
    {
      clean_music(game->music);
      game->m = load_screen(window, game->menu, 0);
      sound_manager(game);
    }
  if (game->bg != NULL)
    sfRenderWindow_drawSprite(window, game->bg, NULL);
  if (game->idx == 1)
    show_grid(window, game, game->level->map->content);
  show_tp(game, player, window);
  show_player(window, player, game);
  hud_placing(window, game);
  game->idx = check_hud_click(window, game->idx, game);
  if (game->idx == 2 || game->idx == 0)
    return (1);
  decor_manager(window, game);
  show_events(window, game, game->level->event);
  if (game->m == 0)
    game->m = sound_manager(game);
  sfRenderWindow_display(window);
  return (0);
}

static int		loop(t_player *player, sfRenderWindow *window,
			      t_game *game)
{
  sfEvent		event;
  sfClock		*clock;

  quest_manager(game);
  player->pos = (sfVector2i) {game->level->map->map_player[0],
			      game->level->map->map_player[1]};
  player->dest = (sfVector2i) {-1, -1};
  clock = sfClock_create();
  sound_manager(game);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	}
      if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) > 0.016f)
	if (draw_game(player, window, game, clock))
	  break ;
      if (game->idx == 2)
	break ;
    }
  sfClock_destroy(clock);
  return (0);
}

static char	display_window(sfRenderWindow *window, t_menu **menu,
		       t_player *player, t_game *game)
{
  int		index;
  sfEvent	event;

  index = 0;
  music_change(index, menu);
  game->menu = menu;
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	{
	  if ((event.type == sfEvtClosed) ||
	      (sfKeyboard_isKeyPressed(sfKeyEscape)))
	    sfRenderWindow_close(window);
	}
      index = mouse_func(window, index, game, menu);
      if (index == -1)
	return (1);
      if (index == 2)
	index = loop(player, window, game);
      sfRenderWindow_clear(window, sfWhite);
      sprite_change(window, index, menu);
      sfRenderWindow_display(window);
    }
  return (0);
}

int			start_menu(t_game *game, t_player *player)
{
  t_menu		**menu;
  sfRenderWindow        *window;

  if ((menu = malloc(sizeof(t_menu))) == NULL)
    return (-1);
  if ((window = create_window()) == NULL)
    return (-1);
  game->stop[0] = 0;
  game->stop[1] = 0;
  game->actions = 0;
  game->end = 0;
  game->idx = 1;
  game->m = 0;
  game->s = 0;
  print_bg(game);
  quest_manager(game);
  if ((menu = disp_startmenu()) == NULL)
    return (-1);
  display_window(window, menu, player, game);
  sfRenderWindow_close(window);
  sfRenderWindow_destroy(window);
  return (0);
}
