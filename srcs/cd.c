/*
** my_cd.c for minishell2 in /home/meridj/Rendu/minishell1/srcs/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Sun Apr 10 15:29:21 2016 Mehdi Meridja
** Last update Tue Apr 12 20:04:29 2016 Mehdi Meridja
*/

#include <stdlib.h>
#include <unistd.h>

#include "minishell2.h"
#include "my.h"

char	*nouveau;
char	*ancien;

int	cd_1(t_shell *sh)
{
  char	*home;

  if ((home = recupere_env("HOME=", sh->env)) == NULL)
    {
      my_put_error("erreur : Home non trouvé\n");
      return (0);
    }
  ancien = nouveau;
  nouveau = home;
  chdir(home);
  return (0);
}

int	cd_2(void)
{
  char	*tmp;

  tmp = nouveau;
  nouveau = ancien;
  ancien = tmp;
  chdir(nouveau);
  return (0);
}

char	*parse_to_new(char *str, int i)
{
  int	j;

  j = 0;
  while (str[i] != 0)
    {
      str[j] = str[i];
      j++;
      i++;
    }
  str[j] = '\0';
  return (str);
}

int	cd_one_one(t_shell *sh, int i)
{
  char	*tmp;
  int	j;

  j = -1;
  if (sh->tab[1][0] == '.' && sh->tab[1][1] == '.')
    {
      i = my_strlen(nouveau) - 1;
      while (nouveau[i] != '/' && i-- != 0);
      tmp = malloc_x(i + 1);
      while (++j != i)
	tmp[j] = nouveau[j];
      tmp[i] = 0;
      free(nouveau);
      nouveau = tmp;
      sh->tab[1] = parse_to_new(sh->tab[1], 2);
    }
  nouveau = cd_3(sh, nouveau);
  return (0);
}

int	go_to_cd(t_shell *sh)
{
  if (ancien == NULL)
    if ((ancien = (glob_creation("OLDPWD=", sh))) == NULL)
	return (-1);
  if (nouveau == NULL)
    if ((nouveau = (glob_creation("PWD=", sh))) == NULL)
      return (-1);
  if ((chdir(sh->tab[1])) != 0 && sh->tab[1] != NULL && sh->tab[1][0] != '-')
    {
      if (access(sh->tab[1], F_OK) == -1)
	print_path_not_found(sh->tab[1]);
      else
	my_put_error("error: Permission non accordée.\n");
      return (-1);
    }
  if (sh->tab[1] == NULL)
    cd_1(sh);
  else if (!sh->tab[1][1] && sh->tab[1][0] == '-')
    cd_2();
  else
    {
      ancien = nouveau;
      cd_one_one(sh, 0);
    }
  return (0);
}
