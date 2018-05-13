/*
** conf_teleporter_verif.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun May 28 15:44:55 2017 LAABID Zakaria
** Last update Sun May 28 23:27:55 2017 LAABID Zakaria
*/

#include "config.h"
#include "tekadv.h"

static void	error_teleport(int nb, int y)
{
  my_puterr(ERR_TELEP_NB, FAIL);
  my_put_nbr(nb + 1);
  my_puterr(ERR_TELEP_MAP, FAIL);
  my_put_nbr(y + 1);
}

static int	verif_character(char *str, int nb, int y)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'a' && str[i] <= 'z') ||
	  (str[i] >= 'A' && str[i] <= 'Z') ||
	  (str[i] >= '0' && str[i] <= '9')
	  || str[i] == '-')
	i++;
      else
	{
	  error_teleport(nb, y);
	  return (my_puterr(ERR_TELEP_NAME, FAIL));
	}
    }
  return (0);
}

static int	is_number_in(int x, int nb)
{
  if (nb < 0)
    {
      my_puterr(ERR_TELEP_NB, FAIL);
      my_put_nbr(x + 1);
      return (my_puterr(ERR_TELEP_NEG, FAIL));
    }
  return (0);
}

int	teleporter_verif(t_tp **tp, int nb, int y)
{
  if ((verif_character(tp[nb]->next_map, nb, y)) == FAIL)
    return (FAIL);
  if ((tp[nb]->next_map) == NULL)
    {
      error_teleport(nb, y);
      return (my_puterr(ERR_TELEP_NAME, FAIL));
    }
  if (tp[nb]->load != 0 && tp[nb]->load != 1)
    {
      error_teleport(nb, y);
      return (my_puterr(ERR_TELEP_LOAD, FAIL));
    }
  if ((is_number_in(nb, tp[nb]->coords[0])) == FAIL)
    return (FAIL);
  if ((is_number_in(nb, tp[nb]->coords[1])) == FAIL)
    return (FAIL);
  return (0);
}

void	config_telep_loop(t_level **level, char *conf, int x, int y)
{
  int	j;

  if (my_strncmp(TELEP_COORD, conf, my_strlen(TELEP_COORD)) == 0)
    {
      j = 8;
      while (conf[j] != '\0' && conf[j] != ',')
	j += 1;
      j += 1;
      level[y]->tp[x - 1]->coords[0] = my_atoi(conf + 8);
      level[y]->tp[x - 1]->coords[1] = my_atoi(conf + j);
    }
}
