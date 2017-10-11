/*
** my_cd2.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:29:35 2016 Mehdi Meridja
** Last update Tue Apr 12 20:04:36 2016 Mehdi Meridja
*/

#include <stdlib.h>

#include "minishell2.h"
#include "my.h"

char*	glob_creation(char *name, t_shell *sh)
{
  char	*tmp;

  if (!(tmp = recupere_env(name, sh->env)))
    {
      my_put_error("erreur: PWD non rouvé\n");
      return (NULL);
    }
  return (tmp);
}

char	*cd_3(t_shell *sh, char *nouveau)
{
  char	*tmp;

  if (sh->tab[1][0] == '/')
    {
      free(nouveau);
      nouveau = sh->tab[1];
    }
  else
    {
      tmp = my_strcat(nouveau, "/");
      free(nouveau);
      nouveau = my_strcat(tmp, sh->tab[1]);
      free(tmp);
    }
  return (nouveau);
}
