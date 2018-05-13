/*
** tools.c for Tekadventure in /home/antoine.casse/Desktop/Tekadventure/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Fri Mar 31 20:37:29 2017 Capitaine CASSE
** Last update Fri May 26 18:19:39 2017 Matthieu BRAULT
*/

#include "tekadv.h"

sfRenderWindow		*create_window(void)
{
  sfVideoMode           mode;
  sfRenderWindow        *window;

  mode.width = SCR_W;
  mode.height = SCR_H;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode,
				 "Dofas - Dofus Remake",
				 sfResize | sfClose, 0);
  if (!(window))
    return (NULL);
  return (window);
}
