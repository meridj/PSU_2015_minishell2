/*
** builtins.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:28:24 2016 Mehdi Meridja
** Last update Tue Apr 12 21:07:43 2016 Mehdi
*/

#include <stdlib.h>

#include "my.h"
#include "minishell2.h"

int	find_str_str(char *chaine1, char *chaine2)
{
  int	i;

  i = 0;
  while (chaine1[i] && chaine2[i] && chaine1[i] == chaine2[i])
    i++;
  if (!chaine1[i])
    return (1);
  return (0);
}

void	set_env_re(t_shell *sh, int nb, int index, int count)
{
  while (sh->env[++index])
    {
      count = 0;
      while (sh->tab[1][count]
	     && sh->tab[1][count] ==  sh->env[index][count])
	count++;
      if (sh->env[index][count] == '=')
	{
	  if ((sh->env[index] = malloc(sizeof(char)
				       * my_strlen(sh->tab[1])
				       + my_strlen(sh->tab[2]) + 2)) == NULL)
	    return ;
	  count = 0;
	  while (sh->tab[1][count])
	    {
	      sh->env[index][count] = sh->tab[1][count];
	      count++;
	    }
	  sh->env[index][count++] = '=';
	  while (sh->tab[2][nb])
	    sh->env[index][count++] = sh->tab[2][nb++];
	  sh->env[index][count] = 0;
      	}
    }
}

int	set_env(t_shell *sh)
{
  if (my_strlen_tab(sh->tab) <= 2)
    my_put_error("error: no parameters enougth\n");
  else if ((recupere_env(sh->tab[1], sh->env)) == NULL)
    creation_env(sh);
  else
    set_env_re(sh, 0, -1, 0);
  return (0);
}

int	check_builtins(t_shell *sh)
{
  int	nb;

  if ((my_strcmp(sh->command, "\0")) == 0)
    sh = sh;
  else if ((my_strcmp(sh->tab[0], "exit")) == 0)
    {
      nb = go_to_exit(sh->tab);
      free_struct(sh);
      exit(nb);
    }
  else if ((my_strcmp(sh->tab[0], "unsetenv")) == 0)
    unset(sh, 0, 0, 0);
  else if ((my_strcmp(sh->tab[0], "setenv")) == 0)
    set_env(sh);
  else if ((my_strcmp(sh->tab[0], "cd")) == 0)
    go_to_cd(sh);
  else if ((my_strcmp(sh->tab[0], "env")) == 0)
    env(sh);
  else
    return (0);
  return (1);
}
