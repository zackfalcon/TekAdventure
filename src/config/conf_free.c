/*
** conf_free.c for  in /home/b00bix/tekadventure
** 
** Made by Matthieu BRAULT
** Login   <b00bix@epitech.net>
** 
** Started on  Sun May 28 15:51:47 2017 Matthieu BRAULT
** Last update Sun May 28 16:04:11 2017 Matthieu BRAULT
*/

#include <stdlib.h>

void	free_cat(char *s1, char *s2)
{
  free(s1);
  free(s2);
}
