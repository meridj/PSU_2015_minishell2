/*
** my_check_str.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:29:58 2016 Mehdi Meridja
** Last update Tue Apr 12 11:19:46 2016 Mehdi Meridja
*/

#include <stdlib.h>

#include "my.h"
#include "minishell2.h"

int	parse(t_shell *sh)
{
  int	i;
  int	j;
  char	*new_command;

  new_command = malloc_x(my_strlen(sh->command));
  i = 0;
  j = 0;
  while (sh->command[i] != 0)
    {
      if (sh->command[i] != ' ')
	new_command[j++] = sh->command[i];
      else if (j != 0 && new_command[j - 1] != ' ')
	new_command[j++] = sh->command[i];
      i++;
    }
  new_command[j++] = 0;
  new_command[j] = 0;
  free(sh->command);
  sh->command = new_command;
  return (0);
}

int	end_unsetenv(char **new_path, char *tmp, int i, t_shell *sh)
{
  new_path[i] = NULL;
  my_free_tab(sh->env);
  free(tmp);
  sh->env = new_path;
  return (0);
}

int	parcour_chaine(t_shell *sh)
{
  if ((my_strcmp(sh->command, ".") == 0) || (my_strcmp(sh->command, " ") == 0)
      || (my_strcmp(sh->command, "/") == 0))
    {
      sh->ret = 3;
      return (-1);
    }
  parse(sh);
  return (0);
}
