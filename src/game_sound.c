/*
** game_sound.c for  in /home/BlackBIrdz/tekadventure/src
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sat May 27 05:38:32 2017 LAABID Zakaria
** Last update Sun May 28 20:02:26 2017 Capitaine CASSE
*/

#include "tekadv.h"

int		clean_music(sfMusic *music)
{
  if (music == NULL)
    return (0);
  sfMusic_stop(music);
  sfMusic_destroy(music);
  return (0);
}

int		sound_manager(t_game *game)
{
  sfMusic	*music;

  if ((music = sfMusic_createFromFile(game->level->map->music)) == NULL)
    {
      game->music = NULL;
      return (FAIL);
    }
  sfMusic_play(music);
  sfMusic_setLoop(music, sfTrue);
  game->music = music;
  return (0);
}
