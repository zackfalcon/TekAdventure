/*
** conf_event_verif.c for  in /home/BlackBIrdz/tekadventure/src/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Sun May 28 18:32:30 2017 LAABID Zakaria
** Last update Sun May 28 23:27:06 2017 LAABID Zakaria
*/

#include <fcntl.h>
#include "config.h"
#include "tekadv.h"

static int	check_dotfile(char *file)
{
  int	i;

  i = 0;
  while (file[i] != '\0')
    {
      if (file[i] == '.')
	return (i);
      i++;
    }
  return (my_puterr(BAD_EXTENSION, FAIL));
}

static int	verif_event(char *path, char *type)
{
  int	fd;
  int	status;

  if ((status = check_dotfile(path)) == FAIL)
    return (FAIL);
  if ((my_strncmp(path + status, type, my_strlen(type))) == 0)
    return (NORMAL);
  else
    return (my_puterr(BAD_EXTENSION, FAIL));
  if ((fd = open(path, O_RDONLY)) == FAIL)
    return (FAIL);
  close(fd);
  return (0);
}

static void	error_event(int nb, int y)
{
  my_puterr(ERR_EVENT_NB, FAIL);
  my_put_nbr(nb + 1);
  my_puterr(ERR_TELEP_MAP, FAIL);
  my_put_nbr(y + 1);
}

int	event_verif(t_event **event, int nb, int y)
{
  if (event == NULL && event[nb] == NULL)
    return (0);
  if ((event[nb]->name) == NULL)
    {
      error_event(nb, y);
      return (my_puterr(ERR_EVENT_NAME, FAIL));
    }
  if ((event[nb]->texture) == NULL)
    return (my_puterr(ERR_EVENT_TEX, FAIL));
  else
    if ((verif_event(event[nb]->texture, PIC_EXT)) == FAIL)
      {
  	my_putstr(event[nb]->texture);
  	error_event(nb, y);
  	return (my_puterr(ERR_EVENT_TEX, FAIL));
      }
  if ((event[nb]->quest_pic) == NULL)
    return (my_puterr(ERR_EVENT_QPIC, FAIL));
  else
    if ((verif_event(event[nb]->quest_pic, PIC_EXT)) == FAIL)
      {
  	error_event(nb, y);
  	return (my_puterr(ERR_EVENT_QPIC, FAIL));
      }
  return (0);
}

int	event_verif_second(t_event **event, int nb, int y)
{
  if ((event[nb]->dialog) == NULL)
    return (my_puterr(ERR_EVENT_DIAL, FAIL));
  else
    if ((verif_event(event[nb]->dialog, TXT_EXT)) == FAIL)
      {
  	error_event(nb, y);
  	return (my_puterr(ERR_EVENT_DIAL, FAIL));
      }
  return (0);
}
