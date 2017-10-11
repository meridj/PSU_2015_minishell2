/*
** main.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:28:55 2016 Mehdi Meridja
** Last update Tue Apr 12 11:11:56 2016 Mehdi
*/

#include <stdlib.h>

#include "minishell2.h"
#include "get_next_line.h"
#include "my.h"

int	mysh(t_shell *sh)
{
  while (linux)
    {
      signal_and_basic();
      if ((sh->command = get_line(0)) == NULL)
	return (-1);
      if ((sh->nb = parcour_chaine(sh)) != -1 && sh->nb != 3)
	{
	  sh->tab = my_str_to_wordtab(sh->command);
	  if ((check_builtins(sh)) == 0)
	    if ((my_command(sh)) == -1)
		print_not_found(sh->command);
	}
      free_struct(sh);
    }
}

int		main(int ac, char **av, char **env)
{
  char		**envp;
  t_shell	*sh;

  if (ac != 1 || my_strlen_tab(av) != 1)
    my_put_error("USAGE: ./mysh");
  else
    {
      if ((sh = malloc(sizeof(t_shell))) == NULL)
	return (-1);
      if ((envp = copy_my_env(env)) == NULL)
	my_put_error("Environement not found\n");
      else
	sh->env = envp;
      mysh(sh);
      my_putstr("exit\n");
    }
  return (0);
}
