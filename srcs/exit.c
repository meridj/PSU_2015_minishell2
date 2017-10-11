/*
** exit.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Mon Apr 11 11:48:30 2016 Mehdi Meridja
** Last update Tue Apr 12 08:09:26 2016 Mehdi Meridja
*/

#include <stdlib.h>
#include <unistd.h>

#include "minishell2.h"
#include "my.h"

int     go_to_exit(char **tab)
{
  int	nb;

  if (tab[1] != NULL)
    {
      nb = my_getnbr(tab[1]);
      my_putstr("exit\n");
      return (nb);
    }
  else
    {
      my_putstr("exit\n");
      return (-1);
    }
}
