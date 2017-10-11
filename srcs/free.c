/*
** free.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Mon Apr 11 10:42:11 2016 Mehdi Meridja
** Last update Mon Apr 11 17:15:31 2016 Mehdi Meridja
*/

#include <stdlib.h>

#include "my.h"
#include "minishell2.h"

int	free_struct(t_shell *sh)
{
  int	i;

  if (sh->ret != 3)
    {
      if ((my_strcmp(sh->command, "\0")) == 0)
	sh->ret = 0;
      i = 0;
      if (sh->ret != 0 && sh->tab)
	{
	  while (sh->tab[i])
	    free(sh->tab[i++]);
	}
      free(sh->tab);
      i = 0;
      if (sh->nb == 2 && sh->path)
	{
	  while (sh->path[i])
	    free(sh->path[i++]);
	  free(sh->path);
	}
    }
  free(sh->command);
  return (0);
}
