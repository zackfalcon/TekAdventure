/*
** my_getnbr.c for libkaas in /home/AntoineC/Desktop/delivery/CPool_Day04
** 
** Made by Antoine Casse
** Login   <AntoineC@epitech.net>
** 
** Started on  Thu Oct  6 20:59:36 2016 Antoine Casse
** Last update Tue May 16 14:31:29 2017 LAABID Zakaria
*/

int	my_atoi(char *str)
{
  int	compteur;
  int	res_int;
  char	tempo;

  compteur = 0;
  res_int = 0;
  while (('0' <= str[compteur]) && (str[compteur] <= '9'))
    {
      res_int *= 10;
      tempo = str[compteur];
      res_int += tempo - '0';
      compteur += 1;
    }
  return (res_int);
}
