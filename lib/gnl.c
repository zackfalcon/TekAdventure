/*
** gnl.c for Stumper 4 in /home/antoine.casse/CPE_2016_stumper4/src
** 
** Made by Capitaine CASSE
** Login   <antoine.casse@epitech.net>
** 
** Started on  Wed May 10 14:47:39 2017 Capitaine CASSE
** Last update Fri May 26 17:16:15 2017 Capitaine CASSE
*/

#include "get_next_line.h"
#include "lkaas.h"

static char	*cut_end(char *str, int *pos)
{
  int		i;
  char		*res;

  i = *pos;
  while (str[i] && str[i] != '\n')
    i += 1;
  if ((res = malloc(sizeof(char) * ((i - *pos) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[*pos] && str[*pos] != '\n')
    {
      res[i] = str[*pos];
      i += 1;
      *pos += 1;
    }
  res[i] = 0;
  if (str[*pos])
    *pos += 1;
  return (res);
}

static int	check_buff(char *buff)
{
  int		i;

  i = 0;
  while (buff[i] && buff[i] != '\n')
    i += 1;
  if (buff[i])
    return (0);
  return (1);
}

static int	clean_buff(char *buff)
{
  int		i;

  i = 0;
  while (i < READ_S)
    {
      buff[i] = 0;
      i += 1;
    }
  return (0);
}

static char	*gnlcat(char *a, char *b)
{
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1))) == NULL)
    return (NULL);
  while (a[i])
    {
      res[i] = a[i];
      i += 1;
    }
  while (b[j])
    {
      res[i] = b[j];
      i += 1;
      j += 1;
    }
  res[i] = 0;
  free(a);
  return (res);
}

char		*get_next_line(const int fd)
{
  char		buff[READ_S + 1];
  static char	*past = NULL;
  static int	pos = 0;

  if (past == NULL)
    {
      if ((past = malloc(sizeof(char))) == NULL)
	return (NULL);
      past[0] = 0;
    }
  buff[READ_S] = 0;
  clean_buff(buff);
  while (read(fd, buff, READ_S) && check_buff(buff))
    {
      if ((past = gnlcat(past, buff)) == NULL)
	return (NULL);
      clean_buff(buff);
    }
  if ((past = gnlcat(past, buff)) == NULL)
    return (NULL);
  if (past[pos])
    return (cut_end(past, &pos));
  free(past);
  pos = 0;
  return (past = NULL);
}
