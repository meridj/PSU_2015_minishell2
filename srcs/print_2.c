/*
** print_2.c for minishell2 in /home/meridj/Rendu/PSU_2015_minishell2/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Apr 12 09:26:02 2016 Mehdi Meridja
** Last update Tue Apr 12 20:04:16 2016 Mehdi Meridja
*/

#include <stdlib.h>

#include "my.h"
#include "minishell2.h"

int	env(t_shell *sh)
{
  int	i;

  i = -1;
  if (sh->env == NULL)
    return (-1);
  while (sh->env[++i] != NULL)
    {
      my_putstr(sh->env[i]);
      my_putchar('\n');
    }
  return (0);
}
