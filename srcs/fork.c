/*
** my_command.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:30:26 2016 Mehdi Meridja
** Last update Tue Apr 12 21:07:03 2016 Mehdi Meridja
*/

#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>

#include "minishell2.h"
#include "my.h"

int	fork_my_proce(t_shell *sh, int n)
{
  pid_t	pid;
  char	*name;
  char	*tmp;

  tmp = my_strcat(sh->path[n], "/");
  name = my_strcat(tmp, sh->tab[0]);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    execve(name, sh->tab, sh->env);
  else
    wait(NULL);
  free(name);
  free(tmp);
  return (0);
}

int	fork_my_proce_2(t_shell *sh)
{
  pid_t	pid;

  if ((access(sh->tab[0], F_OK) == -1)
      || (access(sh->tab[0], X_OK) == -1)
      || (opendir(sh->tab[0])) != NULL)
    {
      my_put_error("error: no such file or directory\n");
      return (-1);
    }
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    execve(sh->tab[0], sh->tab, sh->env);
  else
    wait(NULL);
  return (0);
}

int	find_exec(char *str, char **chemin)
{
  int	i;
  char	*tmp;
  char	*stand;

  i = 0;
  while (chemin[i] != NULL)
    {
      tmp = my_strcat(chemin[i], "/");
      stand = my_strcat(tmp, str);
      free(tmp);
      if ((access(stand, F_OK)) == 0)
	{
	  free(stand);
	  return (i);
	}
      else
	i++;
      free(stand);
    }
  return (-1);
}

int	my_command(t_shell *sh)
{
  char	*chemin;
  int	n;

  if ((chemin = recupere_env("PATH=", sh->env)) == NULL)
    return (0);
  chemin[my_strlen(chemin) - 1] = '\0';
  sh->path = wordtab_custom(chemin);
  free(chemin);
  if ((n = find_exec(sh->tab[0], sh->path)) != -1)
    fork_my_proce(sh, n);
  else
    {
      if (sh->command[0] == '.' ||  sh->command[0] == '/')
	fork_my_proce_2(sh);
      else
	return (-1);
    }
  return (0);
}
