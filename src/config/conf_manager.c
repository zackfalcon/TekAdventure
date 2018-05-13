/*
** conf_manager.c for  in /home/BlackBIrdz/config
** 
** Made by LAABID Zakaria
** Login   <BlackBIrdz@epitech.net>
** 
** Started on  Fri May  5 14:44:37 2017 LAABID Zakaria
** Last update Sun May 28 19:02:18 2017 Matthieu BRAULT
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "config.h"

int		conf_counter(char **conf, char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (conf[i] != NULL)
    {
      if (my_strncmp(conf[i], str, my_strlen(str)) == 0)
	count++;
      i++;
    }
  return (count);
}

char		**conf_init(char **argv, int j, int i)
{
  char		**conf;
  int		fd;
  char		*tmp;

  if (check_file(argv[1]) == -1)
    return (my_puterrnull(ERRCONF_NAME));
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    return (my_puterrnull(ERRCONF_OPEN));
  while ((tmp = get_next_line(fd)) != NULL && i++ >= 0)
    free(tmp);
  close(fd);
  if ((fd = open(argv[1], O_RDONLY)) == -1)
    return (my_puterrnull(ERRCONF_OPEN));
  if ((conf = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  conf[i] = NULL;
  while (j < i)
    {
      tmp = get_next_line(fd);
      conf[j++] = epur_str(tmp);
      free(tmp);
    }
  return (conf);
}

t_level		**config_data(char **conf)
{
  int		x;
  int		max;
  t_level	**level;

  x = 0;
  if ((level = malloc(sizeof(t_level))) == NULL)
    return (NULL);
  if ((level = gen_config_space(level, conf)) == NULL)
    return (NULL);
  max = conf_counter(conf, CONF_LEVEL);
  while (x < max)
    {
      if ((is_here(conf, "event:", x + 1)) == 0)
	gen_event_space(level, conf, x);
      if ((is_here(conf, "teleporter:", x + 1)) == 0)
	gen_telep_space(level, conf, x);
      x++;
    }
  gen_config_space(level, conf);
  return (level);
}

void	conf_disp(char **conf)
{
  int	i;

  i = 0;
  while (conf[i] != NULL)
    {
      my_putstr(conf[i++]);
      my_putchar('\n');
    }
}
